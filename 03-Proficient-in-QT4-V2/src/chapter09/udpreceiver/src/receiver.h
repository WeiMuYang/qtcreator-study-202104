#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
class QUdpSocket;

class Receiver : public QObject
{
	Q_OBJECT

public:
    Receiver(QObject *parent =0 );
    ~Receiver();

private slots:
		void processPendingDatagrams();

private:
	QUdpSocket *udpSocket;
    
};

#endif // RECEIVER_H
