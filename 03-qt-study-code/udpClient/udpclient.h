#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class udpClient;
}

class udpClient : public QWidget
{
    Q_OBJECT

public:
    explicit udpClient(QWidget *parent = 0);
    ~udpClient();

public slots:
    void slot_received();//用来处理接收到的数据

private:
    Ui::udpClient *ui;
    QUdpSocket *mudpsocket;
};

#endif // UDPCLIENT_H
