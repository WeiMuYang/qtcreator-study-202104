#include <QtGui>
#include <QTextCodec>
#include <math.h>

#include "mainwindow.h"

int main(int argc, char **argv)
{
	Q_INIT_RESOURCE(c2);
    QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	MainWindow mainWindow;
    mainWindow.setGeometry(100, 100, 800, 500);
    mainWindow.show();
    
    return app.exec();
}
