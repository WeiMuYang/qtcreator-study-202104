
#include <QtGui>
#include "workThread.h"
#include "dialog.h"
	
ThreadDlg::ThreadDlg(QWidget *parent)
    : QDialog(parent)
{
    startButton = new QPushButton(tr("开始"));
    quitButton = new QPushButton(tr("退出"));
		stopButton = new QPushButton(tr("停止"));
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
    setWindowTitle(tr("启动线程"));
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
