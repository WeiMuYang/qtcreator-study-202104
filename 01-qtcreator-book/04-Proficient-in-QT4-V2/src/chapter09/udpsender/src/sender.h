#ifndef SENDER_H
#define SENDER_H

#include <QObject>
class QTimer;
class QUdpSocket;

class Sender : public QObject
{
	Q_OBJECT

public:
    Sender(QObject *parent = 0);
    ~Sender();
    void start();

private slots:
    void broadcastDatagram();

private:
	QUdpSocket *udpSocket;
	QTimer *timer;
	int messageNo;   
};

#endif // SENDER_H
