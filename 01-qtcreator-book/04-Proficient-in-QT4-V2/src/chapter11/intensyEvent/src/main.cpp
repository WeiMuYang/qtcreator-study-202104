
#include <QApplication>
#include "dialog.h"
#include <QtCore>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    Dialog dialog;
    dialog.show();
    return dialog.exec();
}
