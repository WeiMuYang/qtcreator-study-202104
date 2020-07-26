

#include <QApplication>
#include <QtCore>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr( QTextCodec::codecForName("gb2312"));
    MainWindow window;
    window.show();
    return app.exec();
}
