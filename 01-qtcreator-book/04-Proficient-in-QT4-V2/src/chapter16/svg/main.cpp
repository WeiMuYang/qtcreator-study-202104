#include <QApplication>
#include <QString>

#include "mainwindow.h"

int main(int argc, char **argv)
{
	Q_INIT_RESOURCE(svgviewer);
 
    QApplication app(argc, argv);

    MainWindow window;
    if (argc == 2)
        window.openFile(argv[1]);
    else
        window.openFile("files/bubbles.svg");
    window.show();
    return app.exec();
}
