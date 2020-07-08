
#include <QtGui>
#include <QtDBus>
#include "loadform.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    LoadForm loadForm;
    loadForm.show();
    return app.exec();
}