
#include "calculate_adaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class CalculateAdaptor
 */

CalculateAdaptor::CalculateAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

CalculateAdaptor::~CalculateAdaptor()
{
    // destructor
}

double CalculateAdaptor::housePrice()
{
    // handle method call org.freedesktop.Qt.CalculateInterface.housePrice
    double out0;
    QMetaObject::invokeMethod(parent(), "housePrice", Q_RETURN_ARG(double, out0));
    return out0;
}

void CalculateAdaptor::initInput(double price, double area, int percent, double interest, int year)
{
    // handle method call org.freedesktop.Qt.CalculateInterface.initInput
    QMetaObject::invokeMethod(parent(), "initInput", Q_ARG(double, price), Q_ARG(double, area), Q_ARG(int, percent), Q_ARG(double, interest), Q_ARG(int, year));
}

double CalculateAdaptor::initPay()
{
    // handle method call org.freedesktop.Qt.CalculateInterface.initPay
    double out0;
    QMetaObject::invokeMethod(parent(), "initPay", Q_RETURN_ARG(double, out0));
    return out0;
}

double CalculateAdaptor::lead()
{
    // handle method call org.freedesktop.Qt.CalculateInterface.lead
    double out0;
    QMetaObject::invokeMethod(parent(), "lead", Q_RETURN_ARG(double, out0));
    return out0;
}

double CalculateAdaptor::payPerMonth()
{
    // handle method call org.freedesktop.Qt.CalculateInterface.payPerMonth
    double out0;
    QMetaObject::invokeMethod(parent(), "payPerMonth", Q_RETURN_ARG(double, out0));
    return out0;
}

double CalculateAdaptor::totalInterest()
{
    // handle method call org.freedesktop.Qt.CalculateInterface.totalInterest
    double out0;
    QMetaObject::invokeMethod(parent(), "totalInterest", Q_RETURN_ARG(double, out0));
    return out0;
}

int CalculateAdaptor::totalMonths()
{
    // handle method call org.freedesktop.Qt.CalculateInterface.totalMonths
    int out0;
    QMetaObject::invokeMethod(parent(), "totalMonths", Q_RETURN_ARG(int, out0));
    return out0;
}

double CalculateAdaptor::totalPay()
{
    // handle method call org.freedesktop.Qt.CalculateInterface.totalPay
    double out0;
    QMetaObject::invokeMethod(parent(), "totalPay", Q_RETURN_ARG(double, out0));
    return out0;
}

