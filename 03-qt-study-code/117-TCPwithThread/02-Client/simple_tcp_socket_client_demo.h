#ifndef SIMPLETCPSOCKETCLIENTDEMO_H
#define SIMPLETCPSOCKETCLIENTDEMO_H

#include <QObject>

class SimpleTcpSocketClientDemo : public QObject
{
    Q_OBJECT
public:
    explicit SimpleTcpSocketClientDemo(QObject *parent = nullptr);

signals:

};

#endif // SIMPLETCPSOCKETCLIENTDEMO_H
