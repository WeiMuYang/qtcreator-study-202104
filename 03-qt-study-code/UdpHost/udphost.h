#ifndef UDPHOST_H
#define UDPHOST_H

#include <QWidget>
#include "travel.h"
#include <QThread>
#include <QString>

namespace Ui {
class UdpHost;
}

class UdpHost : public QWidget
{
    Q_OBJECT

public:
    explicit UdpHost(QWidget *parent = 0);
    ~UdpHost();

signals:
    void sig_dowork(QString,int);

private slots:
    void on_pushButton_start_clicked();
public slots:
    void slot_finish();

private:
    Ui::UdpHost *ui;
    travel *traveltoclient;
    QThread *thread;


};

#endif // UDPHOST_H
