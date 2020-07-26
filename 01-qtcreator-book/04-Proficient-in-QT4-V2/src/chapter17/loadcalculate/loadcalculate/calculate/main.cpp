
#include "calculate_adaptor.h"
#include "calculate.h"
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	
    Calculate *calculate = new Calculate();
    new CalculateAdaptor(calculate);
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/Calculate", calculate);
    connection.registerService("org.freedesktop.DbusExample");

    return app.exec();
}