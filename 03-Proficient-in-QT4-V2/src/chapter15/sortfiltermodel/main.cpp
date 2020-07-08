#include <QtGui>

#include "score.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    Score scoreWin;
    scoreWin.show();
    return app.exec();
}
