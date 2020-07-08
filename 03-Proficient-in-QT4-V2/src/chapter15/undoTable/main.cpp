#include <QtGui>
#include "mainwindow.h"

int main(int argc, char** argv) 
{
    Q_INIT_RESOURCE(undo);
    QApplication app(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QTranslator translator;
	QStringList environment = QProcess::systemEnvironment();
	QString str;
	foreach(str, environment) {
		if(str.startsWith("QTDIR="))
			break;	
	}
	if(str.startsWith("QTDIR="))
	{
		QString qtdir = str.mid(6);
		translator.load("qt_" + QLocale::system().name(), qtdir.append("/translations/"));
		qApp->installTranslator(&translator);
	}
	else {
		qDebug("You must set QTDIR environment variable.");
		return 1;
	}

	MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
