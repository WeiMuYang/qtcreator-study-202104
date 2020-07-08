

#include "workThread.h"
#include "dialog.h"
#include <QTextEdit>
#include <qDebug>
#include <stdio.h>
 WorkThread::WorkThread(QObject *parent)
     : QThread(parent)
 {
 }

 void WorkThread::run()
 {
     while(true)
         for (int n = 0; n < 10;++n) {

                  printf("%d%d%d%d%d%d%d%d\n",n,n,n,n,n,n,n,n);
     }
 }
