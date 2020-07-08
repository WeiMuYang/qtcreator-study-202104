
#include <QtGui>
#include "workThread.h"
#include "dialog.h"
	
ThreadDlg::ThreadDlg(QWidget *parent)
    : QDialog(parent)
{
    startButton = new QPushButton(tr("��ʼ"));
    quitButton = new QPushButton(tr("�˳�"));
		stopButton = new QPushButton(tr("ֹͣ"));
		stopButton->setEnabled(false);
    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
		buttonBox->addButton(stopButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
    setWindowTitle(tr("�����߳�"));
}

void ThreadDlg::start()
{
	for(int i=0;i<MAXSIZE;i++)
	{
		threadVector[i] = new WorkThread();
	}
	
		for(int i=0;i<MAXSIZE;i++)
	{
		threadVector[i]->start(QThread::LowestPriority);
	}
	stopButton->setEnabled(true);
	startButton->setEnabled(false);
}


void ThreadDlg::stop()
{
	for(int i=0;i<MAXSIZE;i++)
	{
		threadVector[i]->terminate();
		threadVector[i]->wait();
	}
	startButton->setEnabled(true);
	stopButton->setEnabled(false);
}
