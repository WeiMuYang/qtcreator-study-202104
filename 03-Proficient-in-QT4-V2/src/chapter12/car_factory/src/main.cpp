
#include <QtGui>
#include <QtCore>
#include "mainwindow.h"
#include "connectdlg.h"

int main(int argc, char *argv[])
{
		QApplication app(argc, argv);
		QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    ConnDlg dialog;
    if (dialog.exec() != QDialog::Accepted)
        return -1;
    QFile *carDetails = new QFile("attribs.xml");
    MainWindow window("factory", "cars", carDetails);
    window.show();
    return app.exec();
}
