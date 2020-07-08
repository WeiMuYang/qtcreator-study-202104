#include <QApplication>
#include <QtCore>
#include "digitdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb2312"));
    Digital digit;
    digit.show();
    return app.exec();
}
