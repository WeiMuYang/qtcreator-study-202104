
#include <QtGui>
#include <QtNetwork>
#include "dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    TotalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    serverProgressBar = new QProgressBar;
    serverStatusLabel = new QLabel(tr("����˾���"));

    startButton = new QPushButton(tr("����"));
    quitButton = new QPushButton(tr("�˳�"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(&tcpServer, SIGNAL(newConnection()),
            this, SLOT(acceptConnection()));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(serverProgressBar);
    mainLayout->addWidget(serverStatusLabel);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("�����ļ�"));
}

void Dialog::start()
{
    startButton->setEnabled(false);

    QApplication::setOverrideCursor(Qt::WaitCursor);
    bytesReceived = 0;

    while (!tcpServer.isListening() && !tcpServer.listen(QHostAddress::LocalHost,16689)) {
        QMessageBox::StandardButton ret = QMessageBox::critical(this,
                                        tr("�ػ�"),
                                        tr("�޷���ʼ����: %1.")
					.arg(tcpServer.errorString()),
                                        QMessageBox::Retry
					| QMessageBox::Cancel);
        if (ret == QMessageBox::Cancel)
            return;
    }
    serverStatusLabel->setText(tr("����"));
}

void Dialog::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection, SIGNAL(readyRead()),
            this, SLOT(updateServerProgress()));
    connect(tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    serverStatusLabel->setText(tr("��������"));
    tcpServer.close();
}

void Dialog::updateServerProgress()
{
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_3);
    
    if(bytesReceived <= sizeof(qint64)*2){
      if((tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2)&&(fileNameSize ==0)){
      	in>>TotalBytes>>fileNameSize;
	bytesReceived += sizeof(qint64)*2;
       }       
      if((tcpServerConnection->bytesAvailable() >= fileNameSize)&&(fileNameSize !=0)){
       in>>fileName;
       bytesReceived += fileNameSize;
       localFile = new QFile(fileName);
       	if (!localFile->open(QFile::WriteOnly )) {
        	QMessageBox::warning(this, tr("Ӧ�ó���"),
                             tr("�޷���ȡ�ļ� %1:\n%2.")
                             .arg(fileName)
                             .arg(localFile->errorString()));
        	return;
    	}   
      }else{
      		return;
      }
    }
    
    if (bytesReceived < TotalBytes){
	bytesReceived += tcpServerConnection->bytesAvailable();
	inBlock = tcpServerConnection->readAll();
	localFile->write(inBlock);
	inBlock.resize(0);
    }
    serverProgressBar->setMaximum(TotalBytes);
    serverProgressBar->setValue(bytesReceived);
    qDebug()<<bytesReceived;
    serverStatusLabel->setText(tr("�ѽ��� %1MB")
                               .arg(bytesReceived / (1024 * 1024)));

    if (bytesReceived == TotalBytes) {
        tcpServerConnection->close();
        startButton->setEnabled(true);
        QApplication::restoreOverrideCursor();
    }
}

void Dialog::displayError(QAbstractSocket::SocketError socketError)
{
    if (socketError == QTcpSocket::RemoteHostClosedError)
        return;

    QMessageBox::information(this, tr("�������"),
                             tr("�������´���: %1.")
                             .arg(tcpServerConnection->errorString()));
    tcpServerConnection->close();
    serverProgressBar->reset();
    serverStatusLabel->setText(tr("����˾���"));
    startButton->setEnabled(true);
    QApplication::restoreOverrideCursor();
}
