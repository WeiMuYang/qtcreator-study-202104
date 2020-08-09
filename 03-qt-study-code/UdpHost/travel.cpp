#include "travel.h"
#include <QUdpSocket>
#include <QThread>
travel::travel(QObject *parent) : QObject(parent)
{
   qDebug()<<"构造了travel";
   mudpsocket=new QUdpSocket(this);//新建一个UDP套接字
}

travel::~travel()
{
    qDebug()<<"析构了travel";
}

void travel::slot_do(QString msg,int port)
{

    // writeDatagram方法传入４个参数，分别是数据，数据大小，接收端ip，接收端端口
    // 如果传输成功，该方法返回传输数据的大小（字节），如果失败返回
    int len= mudpsocket ->writeDatagram(msg.toUtf8(),msg.length(),QHostAddress::Broadcast,port);
    if(len!=msg.length())
    {return;}
    qDebug() << "开启线程" << QThread::currentThreadId();//查看槽函数在哪个线程运行
    emit sig_ok();//发出我已经传输完毕的信号
}
