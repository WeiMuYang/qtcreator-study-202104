
#ifndef CALCULATE_INTERFACE_H_1185933162
#define CALCULATE_INTERFACE_H_1185933162

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freedesktop.Qt.CalculateInterface
 */
class CalculateInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.Qt.CalculateInterface"; }

public:
    CalculateInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~CalculateInterface();

public Q_SLOTS: // METHODS
    inline QDBusReply<double> housePrice()
    {
        QList<QVariant> argumentList;
        return callWithArgumentList(QDBus::Block, QLatin1String("housePrice"), argumentList);
    }

    inline QDBusReply<void> initInput(double price, double area, int percent, double interest, int year)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(price) << qVariantFromValue(area) << qVariantFromValue(percent) << qVariantFromValue(interest) << qVariantFromValue(year);
        return callWithArgumentList(QDBus::Block, QLatin1String("initInput"), argumentList);
    }

    inline QDBusReply<double> initPay()
    {
        QList<QVariant> argumentList;
        return callWithArgumentList(QDBus::Block, QLatin1String("initPay"), argumentList);
    }

    inline QDBusReply<double> lead()
    {
        QList<QVariant> argumentList;
        return callWithArgumentList(QDBus::Block, QLatin1String("lead"), argumentList);
    }

    inline QDBusReply<double> payPerMonth()
    {
        QList<QVariant> argumentList;
        return callWithArgumentList(QDBus::Block, QLatin1String("payPerMonth"), argumentList);
    }

    inline QDBusReply<double> totalInterest()
    {
        QList<QVariant> argumentList;
        return callWithArgumentList(QDBus::Block, QLatin1String("totalInterest"), argumentList);
    }

    inline QDBusReply<int> totalMonths()
    {
        QList<QVariant> argumentList;
        return callWithArgumentList(QDBus::Block, QLatin1String("totalMonths"), argumentList);
    }

    inline QDBusReply<double> totalPay()
    {
        QList<QVariant> argumentList;
        return callWithArgumentList(QDBus::Block, QLatin1String("totalPay"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace org {
  namespace freedesktop {
    namespace Qt {
      typedef ::CalculateInterface CalculateInterface;
    }
  }
}
#endif
