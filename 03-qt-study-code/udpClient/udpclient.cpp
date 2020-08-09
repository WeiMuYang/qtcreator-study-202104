#include "udpclient.h"
#include "ui_udpclient.h"
#include <QByteArray>

udpClient::udpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::udpClient)
{
    ui->setupUi(this);
    mudpsocket=new QUdpSocket(this);
    mudpsocket->bind(6666);
    connect(mudpsocket,&QUdpSocket::readyRead,this,&udpClient::slot_received);
    //监听readRead信号
}

udpClient::~udpClient()
{
    delete ui;
}

void udpClient::slot_received()
{
    while(mudpsocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        // 为避免数据丢失，在尝试读取之前，调用pendingDatagramSize()确定未决数据报的大小
        datagram.resize(mudpsocket->pendingDatagramSize());
        // 读取数据，该方法传入四个参数，后面两个可以为空，分别是数据，数据的最大大小，地址和端口
        mudpsocket->readDatagram(datagram.data(),datagram.size());
        QString msg=datagram.data();
        ui->label_get->setText(msg);//显示收到的数据

    }
}
