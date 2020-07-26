#include <QApplication>
#include <QTextCodec>
#include "UniCodeWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    
    UniCodeWidget widget;
    widget.show();
    return app.exec();
}
