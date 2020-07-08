#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);

signals:

public slots:
};

#endif // MYTHREAD_H
