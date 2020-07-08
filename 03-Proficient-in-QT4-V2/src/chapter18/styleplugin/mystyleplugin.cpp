#include <QtGui>

#include "mystyleplugin.h"
#include "mystyle.h"

QStringList MyStylePlugin::keys() const
{
    return QStringList() << "MyStyle";
}

QStyle *MyStylePlugin::create(const QString &key)
{
    if (key.toLower() == "mystyle")
        return new MyStyle;
    return 0;
}

Q_EXPORT_PLUGIN2(mystyleplugin, MyStylePlugin)
