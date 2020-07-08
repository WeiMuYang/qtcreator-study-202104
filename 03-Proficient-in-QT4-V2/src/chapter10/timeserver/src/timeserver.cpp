
#include "timeserver.h"
#include "timethread.h"
#include "dialog.h"
TimeServer::TimeServer(QObject *parent)
    : QTcpServer(parent)
{
		dlg = (Dialog*)parent;
}

void TimeServer::incomingConnection(int socketDescriptor)
{
    TimeThread *thread = new TimeThread(socketDescriptor,this);
		connect(thread, SIGNAL(finished()), dlg, SLOT(showResult()),Qt::QueuedConnection);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
