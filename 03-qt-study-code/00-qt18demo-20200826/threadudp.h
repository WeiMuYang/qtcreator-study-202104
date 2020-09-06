#ifndef THREADUDP_H
#define THREADUDP_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QUdpSocket>
#include <QByteArray>

class ThreadUDP : public QThread
{
    Q_OBJECT
public:
     ThreadUDP( );

    void SendUDPBytesArray(QString str);    // 发送数据报

public slots:
    void UdpReceiveBytesArray();           // 发送数据报

protected:
    void run();

signals:


private:

    QUdpSocket *m_UdpOfSend;
    QUdpSocket *m_UdpOfRecive;

    QByteArray m_ByteArryofRecive;

    bool m_Stop;


};

#endif // THREADUDP_H
