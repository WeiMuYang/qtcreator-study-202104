
#include <QtGui>
#include <QtNetwork>
#include "dialog.h"
#include "timeserver.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent),count(0)
{
    server = new TimeServer(this);
		statusLabel = new QLabel;
		reqStatusLable = new QLabel;
    quitButton = new QPushButton(tr("退出"));
    quitButton->setAutoDefault(false);

    if (!server->listen()) {
        QMessageBox::critical(this, tr("多线程时间服务器"),
                              tr("无法启动服务器: %1.")
                              .arg(server->errorString()));
        close();
        return;
    }

    statusLabel->setText(tr("时间服务器运行在端口： %1.\n")
                         .arg(server->serverPort()));

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);
    buttonLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(statusLabel);
		mainLayout->addWidget(reqStatusLable);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("多线程时间服务器"));
}
void Dialog::showResult()
{
	  reqStatusLable->setText(tr("第%1次请求完毕.\n").arg(++count));

}
