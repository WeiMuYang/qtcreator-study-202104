
#include <QtNetwork> 
#include <QApplication>
#include <QObject>
#include "CBase.h"

class GroupSend : public QObject{
	Q_OBJECT
public:	

	GroupSend();
	~GroupSend();
	void initSocket();

public slots:	
	void sendPakages();
private:
	QUdpSocket * udpSocket;
	char* FSendBuffer;
	QTimer* timer;
	unsigned long  FSocket;
	long count;	
};



