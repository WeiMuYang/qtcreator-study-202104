
#ifndef CALCULATE_ADAPTOR_H_1185933799
#define CALCULATE_ADAPTOR_H_1185933799

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;

/*
 * Adaptor class for interface org.freedesktop.Qt.CalculateInterface
 */
class CalculateAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.freedesktop.Qt.CalculateInterface")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"org.freedesktop.Qt.CalculateInterface\" >\n"
"    <method name=\"payPerMonth\" >\n"
"      <arg direction=\"out\" type=\"d\" />\n"
"    </method>\n"
"    <method name=\"totalMonths\" >\n"
"      <arg direction=\"out\" type=\"i\" />\n"
"    </method>\n"
"    <method name=\"initPay\" >\n"
"      <arg direction=\"out\" type=\"d\" />\n"
"    </method>\n"
"    <method name=\"totalInterest\" >\n"
"      <arg direction=\"out\" type=\"d\" />\n"
"    </method>\n"
"    <method name=\"totalPay\" >\n"
"      <arg direction=\"out\" type=\"d\" />\n"
"    </method>\n"
"    <method name=\"lead\" >\n"
"      <arg direction=\"out\" type=\"d\" />\n"
"    </method>\n"
"    <method name=\"housePrice\" >\n"
"      <arg direction=\"out\" type=\"d\" />\n"
"    </method>\n"
"    <method name=\"initInput\" >\n"
"      <arg direction=\"in\" type=\"d\" name=\"price\" />\n"
"      <arg direction=\"in\" type=\"d\" name=\"area\" />\n"
"      <arg direction=\"in\" type=\"i\" name=\"percent\" />\n"
"      <arg direction=\"in\" type=\"d\" name=\"interest\" />\n"
"      <arg direction=\"in\" type=\"i\" name=\"year\" />\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    CalculateAdaptor(QObject *parent);
    virtual ~CalculateAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    double housePrice();
    void initInput(double price, double area, int percent, double interest, int year);
    double initPay();
    double lead();
    double payPerMonth();
    double totalInterest();
    int totalMonths();
    double totalPay();
Q_SIGNALS: // SIGNALS
};

#endif
