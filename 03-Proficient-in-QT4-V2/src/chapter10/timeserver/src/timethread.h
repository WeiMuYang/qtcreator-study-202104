
#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QThread>
#include <QTcpSocket>

class TimeThread : public QThread
{
    Q_OBJECT

public:
    TimeThread(int socketDescriptor, QObject *parent);

    void run();

signals:
    void error(QTcpSocket::SocketError socketError);
private:
    int socketDescriptor;

};

#endif
