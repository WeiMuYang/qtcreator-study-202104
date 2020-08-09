#ifndef TRAVEL_H
#define TRAVEL_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QUdpSocket>

class travel : public QObject
{
    Q_OBJECT
public:
    explicit travel(QObject *parent = 0);
    ~travel();

signals:
    void sig_ok();
public slots:
    void slot_do(QString msg,int port);
    // 主要实现功能的函数，用于传送数据给客户端，其中两个传入参数分别是待传数据和客户端端口号
private:
    QUdpSocket *mudpsocket;

};

#endif // TRAVEL_H
