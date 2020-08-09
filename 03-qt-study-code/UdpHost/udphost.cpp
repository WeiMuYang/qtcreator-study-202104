#include "udphost.h"
#include "ui_udphost.h"

UdpHost::UdpHost(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UdpHost)
{
    qDebug() << "主线程:" << QThread::currentThreadId();
    ui->setupUi(this);
    traveltoclient=new travel();//创建对象
    thread=new QThread();//创建线程
    traveltoclient->moveToThread(thread);//使用该方法实现多线程，这是ＱＴ推荐的

    connect(thread,&QThread::finished,traveltoclient,&QObject::deleteLater);
    connect(this,&UdpHost::sig_dowork,traveltoclient,&travel::slot_do);
    // 用connect的方式调用do函数,否则多线程报错
    connect(traveltoclient,&travel::sig_ok,this,&UdpHost::slot_finish);
}

UdpHost::~UdpHost()
{
    delete ui;
    //关闭子线程
    thread->quit();
    thread->wait();
}

void UdpHost::on_pushButton_start_clicked()
{
    thread->start();
    QString msg = ui->textEdit->toPlainText();
    emit sig_dowork(msg,6666);//把数据和端口号作为参数传出去
}
void UdpHost::slot_finish()
{
    qDebug()<<"结束"<<QThread::currentThreadId();
}
