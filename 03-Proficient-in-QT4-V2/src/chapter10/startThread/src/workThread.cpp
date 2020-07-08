
 
#include "workThread.h"
#include "dialog.h"
#include <QTextEdit>
#include <QDebug>
#include <stdio.h>
// WorkThread::WorkThread(QObject *parent)
//     : QThread(parent)
// {
// }

 void WorkThread::run()
 {
     while(true)
		 for (int n = 0; n < 10;++n) {
// 		 		str = QString("%1%2%3%4%5%6%7%8\n").arg(n).arg(n).arg(n).arg(n).arg(n).arg(n).arg(n).arg(n);
// 				qDebug()<<str;
					printf("%d%d%d%d%d%d%d%d\n",n,n,n,n,n,n,n,n);
     }
 }
 