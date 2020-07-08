
#ifndef WORKTHREAD_H
#define WORKTHREAD_H
#include <QThread>

class WorkThread : public QThread
{
public:
    WorkThread ( QObject * parent = 0 );
 protected:

     void run();
 private:
         QString str;
};

#endif
