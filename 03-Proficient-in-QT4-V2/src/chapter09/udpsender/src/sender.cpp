#include "sender.h"
#include <QtNetwork>

Sender::Sender(QObject *parent)
	: QObject(parent)
{
	timer = new QTimer(this);
	udpSocket = new QUdpSocket(this);
	messageNo = 1;
	connect(timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));
}

Sender::~Sender()
{
	delete timer;
	delete udpSocket;

}

void Sender::start()
{
	timer->start(1000);
}

void Sender::broadcastDatagram()
{
	qDebug()<<(tr("¿ªÊ¼¹ã²¥£º%1").arg(messageNo));
	QByteArray datagram = "BroadCast Messages:"+ QByteArray::number(messageNo);
	udpSocket->writeDatagram(datagram.data(), datagram.size(),
		QHostAddress::Broadcast, 44444);
	++messageNo;
}
