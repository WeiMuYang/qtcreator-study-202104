#include <QtGui>

#include "dndwidget.h"

int main(int argv, char **args)
{
    QApplication app(argv, args);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    DNDWidget dndWidget;
    dndWidget.show();

    return app.exec();
}
