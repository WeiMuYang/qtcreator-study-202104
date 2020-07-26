
#include <QApplication>
#include <QtCore>
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	QTextCodec::setCodecForTr( QTextCodec::codecForName("gb2312"));
    Client client;
    client.show();
    return client.exec();
}
