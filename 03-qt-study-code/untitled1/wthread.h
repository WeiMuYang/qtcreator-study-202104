#ifndef WTHREAD_H
#define WTHREAD_H


#include <QThread>
#include "data.h"


class wThread:public QThread
{
public:
    wThread();

protected:
    void run();

private:
    Data *m_d;
};

#endif // WTHREAD_H
