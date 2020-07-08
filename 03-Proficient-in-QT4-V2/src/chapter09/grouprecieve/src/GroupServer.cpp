

#include "GroupServer.h"

 void GroupServer::initSocket()
 {
     	unsigned long  FSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
	struct ip_mreq imreq;
	imreq.imr_multiaddr.s_addr = inet_addr("225.1.0.111");
	imreq.imr_interface.s_addr=htonl(INADDR_ANY);
	setsockopt(FSocket, IPPROTO_IP, IP_ADD_MEMBERSHIP, 
		(char *) &imreq, sizeof(ip_mreq));	
	struct sockaddr_in FAddr;
	memset(&FAddr, 0, sizeof(FAddr));
	FAddr.sin_family = AF_INET;
	FAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	FAddr.sin_port = htons(8999); 
	bind(FSocket, (sockaddr*)&FAddr, sizeof(FAddr));  
	udpSocket = new QUdpSocket();	
	udpSocket->setSocketDescriptor(FSocket);
     	connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
 }

 void GroupServer::readPendingDatagrams()
 {
     while (udpSocket->hasPendingDatagrams()) {
         QByteArray datagram;
         datagram.resize(udpSocket->pendingDatagramSize());
         QHostAddress sender;
         quint16 senderPort;

         udpSocket->readDatagram(datagram.data(), datagram.size(),
                                 &sender, &senderPort);		 	 
	memcpy(&count,datagram.data(), sizeof(long));				 
	qDebug()<<count<<"-------->>>>"<<Receivedpackets;
	Receivedpackets++;
     }
 }
