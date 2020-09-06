#include "threadudp.h"
#include <QDebug>

ThreadUDP::ThreadUDP( )
{

    m_UdpOfSend = new  QUdpSocket();

    m_UdpOfRecive = new QUdpSocket(this);
    //  m_UdpOfRecive->bind(QHostAddress("192.168.1.101"), 8000);

    m_Stop = false;

    connect(m_UdpOfRecive, SIGNAL(readyRead()), this, SLOT(UdpReceiveBytesArray()));

}

// 发送信息
void ThreadUDP::SendUDPBytesArray(QString str)
{
    //获取对方的端口号和ip
    QString ip = "192.168.1.101";  // ui->lineEditip->text();
    quint16 port = 8000;
    m_UdpOfSend->writeDatagram(str.toUtf8(), (QHostAddress)ip, port);
}



// 接收信息
void ThreadUDP::UdpReceiveBytesArray()
{
    while(m_UdpOfRecive->hasPendingDatagrams())
    {
        m_ByteArryofRecive.resize(m_UdpOfRecive->pendingDatagramSize());
        m_UdpOfRecive->readDatagram(m_ByteArryofRecive.data(), m_ByteArryofRecive.size());
        qDebug() <<  m_ByteArryofRecive.data() ;
    }
    QString str = QString(m_ByteArryofRecive);
}

void ThreadUDP::run()
{
     ;
}

