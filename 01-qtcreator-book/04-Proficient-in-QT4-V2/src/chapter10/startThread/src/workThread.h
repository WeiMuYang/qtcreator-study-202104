
#ifndef WORKTHREAD_H
#define WORKTHREAD_H
#include <QThread>

class WorkThread : public QThread
{
 protected:
//  		 WorkThread ( QObject * parent = 0 );
     void run();
// private:
// 		 QString str;
};
 
#endif