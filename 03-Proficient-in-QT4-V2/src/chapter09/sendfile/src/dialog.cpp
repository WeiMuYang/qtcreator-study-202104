
#include <QtGui>
#include <QtNetwork>
#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    loadSize = 4*1024;
    TotalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    clientProgressBar = new QProgressBar;
    clientStatusLabel = new QLabel(tr("�ͻ��˾���"));
    startButton = new QPushButton(tr("��ʼ"));
    quitButton = new QPushButton(tr("�˳�"));
    openButton = new QPushButton (tr("��"));
    startButton->setEnabled(false);
    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(openButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));
    connect(&tcpClient, SIGNAL(connected()), this, SLOT(startTransfer()));
    connect(&tcpClient, SIGNAL(bytesWritten(qint64)),
            this, SLOT(updateClientProgress(qint64)));
    connect(&tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(clientProgressBar);
    mainLayout->addWidget(clientStatusLabel);
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
    bytesWritten = 0;
    clientStatusLabel->setText(tr("������..."));
    tcpClient.connectToHost(QHostAddress::LocalHost, 16689);
}

void Dialog::startTransfer()
{
    localFile = new QFile(fileName);
    if (!localFile->open(QFile::ReadOnly )) {
        QMessageBox::warning(this, tr("Ӧ�ó���"),
                             tr("�޷���ȡ�ļ� %1:\n%2.")
                             .arg(fileName)
                             .arg(localFile->errorString()));
        return;
    }
    TotalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_3);
    
    QString currentFile = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    sendOut<<qint64(0)<<qint64(0)<<currentFile;
    TotalBytes +=  outBlock.size();
    sendOut.device()->seek(0);
    sendOut<<TotalBytes<<qint64((outBlock.size()-sizeof(qint64)*2));
    bytesToWrite = TotalBytes - tcpClient.write(outBlock);
    clientStatusLabel->setText(tr("������"));
    qDebug()<<currentFile<<TotalBytes;
    outBlock.resize(0);
}

void Dialog::updateClientProgress(qint64 numBytes)
{
    bytesWritten += (int)numBytes;
    if (bytesToWrite > 0){
    	outBlock = localFile->read(qMin(bytesToWrite, loadSize));
 	bytesToWrite -= (int)tcpClient.write(outBlock);
	outBlock.resize(0);    
    }
    else{  
    	localFile->close();
    }
    clientProgressBar->setMaximum(TotalBytes);
    clientProgressBar->setValue(bytesWritten);
    clientStatusLabel->setText(tr("�ѷ��� %1MB")
                               .arg(bytesWritten / (1024 * 1024)));
}

void Dialog::displayError(QAbstractSocket::SocketError socketError)
{
    if (socketError == QTcpSocket::RemoteHostClosedError)
        return;

    QMessageBox::information(this, tr("����"),
                             tr("�������´���: %1.")
                             .arg(tcpClient.errorString()));

    tcpClient.close();
    clientProgressBar->reset();
    clientStatusLabel->setText(tr("�ͻ��˾���"));
    startButton->setEnabled(true);
    QApplication::restoreOverrideCursor();
}

void Dialog::openFile()
{
    fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            startButton->setEnabled(true);
	    
}







