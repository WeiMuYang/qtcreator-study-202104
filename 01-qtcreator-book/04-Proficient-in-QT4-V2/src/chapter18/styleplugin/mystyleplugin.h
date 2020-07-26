#ifndef MYSTYLEPLUGIN_H
#define MYSTYLEPLUGIN_H

#include <QStylePlugin>

class QStringList;
class QStyle;

class MyStylePlugin : public QStylePlugin
{
    Q_OBJECT

public:
    MyStylePlugin() {};

    QStringList keys() const;
    QStyle *create(const QString &key);
};

#endif
