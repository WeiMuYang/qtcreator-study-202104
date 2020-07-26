#include <QtGui>
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    MyWidget myWidget;
    myWidget.show();
    
    return app.exec();
}
