
#include <QtGui>

#include "dialog.h"
//!ʹ��0���붨ʱ����ʽ�������ĺ궨��
//#define USET_TIME_EVENT

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    isStop = false;
	loadSize = 4*1024;
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
	tempBuf.resize(0); 
    progressBar = new QProgressBar;
    statusLabel = new QLabel(tr("�����ȵ���򿪰�ťѡ��һ���ļ���"));
    saveButton = new QPushButton(tr("����"));
    quitButton = new QPushButton(tr("�˳�"));
    openButton = new QPushButton (tr("��"));
	stopButton = new QPushButton(tr("��ֹ"));
    saveButton->setEnabled(false);
	stopButton->setEnabled(false);
    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(saveButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(openButton, QDialogButtonBox::ActionRole);
	buttonBox->addButton(stopButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveFile()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(progressBar);
    mainLayout->addWidget(statusLabel);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("����ǿ���¼�"));
}

void Dialog::saveFile()
{
    rFile = new QFile(fileName);
    if (!rFile->open(QFile::ReadOnly )) {
        QMessageBox::warning(this, tr("����"),
                             tr("�޷���ȡ�ļ� %1:\n%2.")
                             .arg(fileName)
                             .arg(rFile->errorString()));
        return;
    }
		currentFile = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
		wFile = new QFile(currentFile);
		if (!wFile->open(QFile::WriteOnly )) {
				QMessageBox::warning(this, tr("����"),
                             tr("�޷�д�ļ� %1:\n%2.")
                             .arg(currentFile)
                             .arg(wFile->errorString()));
        	return;
    }   
		
    totalBytes = rFile->size();
	bytesToWrite = totalBytes;
    statusLabel->setText(tr("����"));
	#ifdef USET_TIME_EVENT
		timeId = startTimer(0);
	#else
		doCopy();
	#endif
}
void Dialog::doCopy()
{
		while(bytesToWrite >0)
		{
			if(isStop){
				rFile->close();
				wFile->close();
				wFile->remove(currentFile);
				progressBar->setMaximum(totalBytes);
				progressBar->setValue(0);
				statusLabel->setText(tr("��ֹ"));
				saveButton->setEnabled(false);
				stopButton->setEnabled(false);
				qApp->processEvents();
				return;
			}else{
				tempBuf = rFile->read(qMin(bytesToWrite, loadSize));
				wFile->write(tempBuf);
				bytesWritten += qMin(bytesToWrite, loadSize);
				bytesToWrite -= qMin(bytesToWrite, loadSize);
				progressBar->setMaximum(totalBytes);
				progressBar->setValue(bytesWritten);
				statusLabel->setText(tr("�ѿ��� %1MB")
				.arg(bytesWritten / (1024 * 1024)));
				tempBuf.resize(0);
				qApp->processEvents();
			}
		}
		rFile->close();
		wFile->close();


}
void Dialog::openFile()
{
    fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
				{   
					saveButton->setEnabled(true);
					stopButton->setEnabled(true);
				}
}

void Dialog::stop()
{
		isStop = true;
}

void Dialog::timerEvent(QTimerEvent* event)
{
		if(event->timerId() == timeId)
		{
		while((bytesToWrite >0) && (!qApp->hasPendingEvents()))
			{
				if(isStop){
					rFile->close();
					wFile->close();
					wFile->remove(currentFile);
					progressBar->setMaximum(totalBytes);
					progressBar->setValue(0);
					statusLabel->setText(tr("��ֹ"));
					saveButton->setEnabled(false);
					stopButton->setEnabled(false);
					return;
				}else{
					tempBuf = rFile->read(qMin(bytesToWrite, loadSize));
					wFile->write(tempBuf);
					bytesWritten += qMin(bytesToWrite, loadSize);
					bytesToWrite -= qMin(bytesToWrite, loadSize);
					progressBar->setMaximum(totalBytes);
					progressBar->setValue(bytesWritten);
					statusLabel->setText(tr("�ѿ��� %1MB")
					.arg(bytesWritten / (1024 * 1024)));
					tempBuf.resize(0);
				}
			}
			event->accept();
		}
		else{
			Dialog::timerEvent(event);
		
		}
}


