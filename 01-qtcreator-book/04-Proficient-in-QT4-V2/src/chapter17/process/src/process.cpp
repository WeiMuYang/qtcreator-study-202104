
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <QtGui>

 int main(int argc, char *argv[])
 {
	QApplication app(argc, argv);
	QTextCodec::setCodecForTr( QTextCodec::codecForName("gb2312"));
     if (app.arguments().count() != 2) {
//          qFatal("Error - expected executable path as argument");
		 qDebug()<<QObject::tr("需要一个备份路径作为参数，如：'process /home'");
         return -1;
     }

     QProcess proc;
     QString executable ="tar";
     QStringList arguments;
     arguments<<"czvf"<<"backup.tar.gz";
     arguments<<app.arguments().at(1);
     proc.start(executable, arguments);
     if (!proc.waitForStarted())
         return false;

     proc.closeWriteChannel();
	 QByteArray  procOutPut;

     while (!proc.waitForFinished(20))
     {
     	procOutPut = proc.readAll();
	 	qDebug()<<procOutPut;
     }
         
	return EXIT_SUCCESS;

 }