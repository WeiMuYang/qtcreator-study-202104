#include "composition.h"

#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    CompositionWidget compWidget;
    compWidget.show();

    return app.exec();
}
