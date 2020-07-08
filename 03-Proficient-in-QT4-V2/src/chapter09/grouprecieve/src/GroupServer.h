
#include <QtNetwork> 
#include <QApplication>
#include <QObject>
#include "CBase.h"

class GroupServer : public QObject{
	Q_OBJECT
public:	

	GroupServer(){FSocket = 0;udpSocket = 0;count=0;Receivedpackets=0;};
	~GroupServer(){};
	void initSocket();

public slots:	
	void readPendingDatagrams();
private:
	QUdpSocket * udpSocket;
	unsigned long  FSocket;
	long count,Receivedpackets;	
};



