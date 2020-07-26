
#include <QtGui>
#include <QtNetwork>
#include <QDateTimeEdit>
#include "client.h"

Client::Client(QWidget *parent)
    : QDialog(parent)
{
    hostLabel = new QLabel(tr("服务器名:"));
    portLabel = new QLabel(tr("端口:"));

    hostLineEdit = new QLineEdit("Localhost");
    portLineEdit = new QLineEdit;
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    hostLabel->setBuddy(hostLineEdit);
    portLabel->setBuddy(portLineEdit);

    statusLabel = new QLabel(tr("请首先运行时间服务器！"));
																
		dateEdit = new QDateTimeEdit(this);
		
    getTimeButton = new QPushButton(tr("获取时间"));
    getTimeButton->setDefault(true);
    getTimeButton->setEnabled(false);

    quitButton = new QPushButton(tr("退出"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(getTimeButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    tcpSocket = new QTcpSocket(this);

    connect(hostLineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableGetFortuneButton()));
    connect(portLineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableGetFortuneButton()));
    connect(getTimeButton, SIGNAL(clicked()),
            this, SLOT(requsetTime()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readTime()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(hostLineEdit, 0, 1);
    mainLayout->addWidget(portLabel, 1, 0);
    mainLayout->addWidget(portLineEdit, 1, 1);
		mainLayout->addWidget(dateEdit, 2, 0,1,2);
    mainLayout->addWidget(statusLabel, 3, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 4, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("时间服务客户端"));
    portLineEdit->setFocus();
}

void Client::requsetTime()
{
    getTimeButton->setEnabled(false);
    time2u = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost(hostLineEdit->text(),
                             portLineEdit->text().toInt());
}

void Client::readTime()
{
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_4_3);

    if (time2u == 0) {
        if (tcpSocket->bytesAvailable() < (int)sizeof(uint))
            return;
        in >> time2u;
    }

		dateEdit->setDateTime(QDateTime::fromTime_t (time2u)); 
    getTimeButton->setEnabled(true);
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("时间服务客户端"),
                                 tr("主机不可达！"));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("时间服务客户端"),
                                 tr("连接被拒绝！"));
        break;
    default:
        QMessageBox::information(this, tr("时间服务客户端"),
                                 tr("产生如下错误: %1.")
                                 .arg(tcpSocket->errorString()));
    }

    getTimeButton->setEnabled(true);
}

void Client::enableGetFortuneButton()
{
    getTimeButton->setEnabled(!hostLineEdit->text().isEmpty()
                                 && !portLineEdit->text().isEmpty());
}
