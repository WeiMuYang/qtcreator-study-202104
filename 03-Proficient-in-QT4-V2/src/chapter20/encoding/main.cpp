#include <QApplication>
#include <QTextCodec>
#include "ConvertWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    
    ConvertWidget widget;
    widget.show();
    return app.exec();
}
