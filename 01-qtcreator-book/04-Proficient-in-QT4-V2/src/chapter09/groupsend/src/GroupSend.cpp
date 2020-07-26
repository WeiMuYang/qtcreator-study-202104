

#include "GroupSend.h"
GroupSend::GroupSend()
{
	count = 0;
	FSendBuffer = (char*)malloc(sizeof(long)+1024*16);
	memcpy(FSendBuffer, &count,sizeof(long));
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(sendPakages()));	
}


GroupSend::~GroupSend()
{
	free(FSendBuffer);
}
 void GroupSend::initSocket()
 {
     	unsigned long  FSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
	unsigned char TTL = 16;
	bool Loop = true;
	setsockopt(FSocket, IPPROTO_IP, IP_MULTICAST_TTL, (const char *) &TTL,sizeof(unsigned char));
	setsockopt(FSocket, IPPROTO_IP, IP_MULTICAST_LOOP, (const char *) &Loop,sizeof(unsigned char));
	udpSocket = new QUdpSocket();	
	udpSocket->setSocketDescriptor(FSocket);
	timer->start(1);
 }

 void GroupSend::sendPakages()
{
	qDebug()<<tr("packages sent:")<<count;
	udpSocket->writeDatagram(FSendBuffer, sizeof(long)+1024*16, QHostAddress("225.1.0.111"),8999);
	count++;
	memcpy(FSendBuffer, &count,sizeof(long));

}
