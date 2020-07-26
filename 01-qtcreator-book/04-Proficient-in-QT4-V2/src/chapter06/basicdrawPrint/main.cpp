#include <QApplication>
#include <QTextCodec>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
	//QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	QString locale = QLocale::system().name();
	
	QTranslator translator;
	translator.load(QString("basicdraw_") + locale);
	app.installTranslator(&translator);
	
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
