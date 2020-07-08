#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    MainWindow window;
    window.show();
    return app.exec();
}
