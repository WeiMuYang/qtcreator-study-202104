#include <QtCore>
#include <QObject>
#include "httpget.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
	QTextCodec::setCodecForTr( QTextCodec::codecForName("gb2312"));
	QStringList args = app.arguments();
	if (args.count() !=2){
		qDebug()<<QObject::tr("ÓÃ·¨: wget url")<<endl
		<<QObject::tr("Àý:")<<endl
		<<QObject::tr(" wget http://www.gnu.org/software/wget/manual/wget.txt");
	return -1;
	}

	HttpGet httpClient;
	if (!httpClient.downloadFile(QUrl(args[1])))
		return -1;
	QObject::connect(&httpClient,SIGNAL(done()),&app,SLOT(quit()));
	return app.exec();
}
