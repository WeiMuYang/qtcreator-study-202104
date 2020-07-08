#include <QtCore>
#include <QObject>
#include "ftplogin.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
	QTextCodec::setCodecForTr( QTextCodec::codecForName("gb18030"));
	QStringList args = app.arguments();
	if (args.count() !=2){
		qDebug()<<QObject::tr("ÓÃ·¨: ftplogin url")<<endl
		<<QObject::tr("Àý:")<<endl
		<<QObject::tr(" ftplogin ftp://ftp.trolltech.com");
		return -1;
		}
	
	FtpLogin ftpClient;
	if (!ftpClient.logIn(QUrl(args[1])))
		return -1;
	QObject::connect(&ftpClient,SIGNAL(done()),&app,SLOT(quit()));
    return app.exec();
}
