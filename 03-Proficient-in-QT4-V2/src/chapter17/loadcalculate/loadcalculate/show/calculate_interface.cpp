
#include "calculate_interface.h"

/*
 * Implementation of interface class CalculateInterface
 */

CalculateInterface::CalculateInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

CalculateInterface::~CalculateInterface()
{
}

