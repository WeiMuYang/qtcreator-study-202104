#include <iostream>
#include <QtCore>
#include <QtGui>
#include <QDebug>

#include "Msg.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

	Msg msg;	
	msg.show();
	
	return app.exec();
}

