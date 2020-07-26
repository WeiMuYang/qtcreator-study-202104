#include "receiver.h"
#include <QtNetwork>

Receiver::Receiver(QObject *parent)
	: QObject(parent)
{
	udpSocket = new QUdpSocket(this);
	udpSocket->bind(44444);
	connect(udpSocket, SIGNAL(readyRead()),
		this, SLOT(processPendingDatagrams()));
}

Receiver::~Receiver()
{
	delete udpSocket;
}

void Receiver::processPendingDatagrams()
{
	while (udpSocket->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		udpSocket->readDatagram(datagram.data(), datagram.size());
		qDebug()<<(tr("接收数据: \"%1\"")
			.arg(datagram.data()));
	}
}
