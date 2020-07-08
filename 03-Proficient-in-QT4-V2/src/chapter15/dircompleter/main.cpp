#include <QApplication>
#include "DirWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    DirWidget dirWidget;
    dirWidget.show();
    
    return app.exec();
}
