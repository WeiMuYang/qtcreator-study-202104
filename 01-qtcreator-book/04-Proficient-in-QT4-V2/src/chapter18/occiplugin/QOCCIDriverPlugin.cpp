
#include <qsqldriverplugin.h>
#include <qstringlist.h>
#include "qsql_occi.h"

class QOCCIDriverPlugin : public QSqlDriverPlugin
{
public:
    QOCCIDriverPlugin();

    QSqlDriver* create(const QString &);
    QStringList keys() const;
};

QOCCIDriverPlugin::QOCCIDriverPlugin()
    : QSqlDriverPlugin()
{
}

QSqlDriver* QOCCIDriverPlugin::create(const QString &name)
{
    if (name == QLatin1String("QOCCI") || name == QLatin1String("QOCCI8")) {
        QOCCIDriver* driver = new QOCCIDriver();
        return driver;
    }
    return 0;
}

QStringList QOCCIDriverPlugin::keys() const
{
    QStringList l;
    l.append(QLatin1String("QOCCI8"));
    l.append(QLatin1String("QOCCI"));
    return l;
}

Q_EXPORT_STATIC_PLUGIN(QOCCIDriverPlugin)
Q_EXPORT_PLUGIN2(qsqlocci, QOCCIDriverPlugin)
