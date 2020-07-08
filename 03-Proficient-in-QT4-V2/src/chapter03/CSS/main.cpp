#include <QApplication>
#include <QTextCodec>

#include "TestWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    TestWidget test;
    test.show();
    return app.exec();
}
