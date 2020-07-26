#include <QtCore>
#include <QObject>
#include "sender.h"
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
	QTextCodec::setCodecForTr( QTextCodec::codecForName("gb2312"));
	Sender sender;
	sender.start();
    return app.exec();
}
