#include <QtTest/QtTest>
#include <QtDebug>

#include "nautical.h"

using namespace QTest;

class TestNautical: public QObject
{
    Q_OBJECT
private slots:
    void toKilometerTest();
};

void TestNautical::toKilometerTest()
{
    Nautical nautical(1);
    QVERIFY(qAbs(nautical.toKilometer() - 1.852) < 0.0000001);
}

QTEST_MAIN(TestNautical)
#include "testnautical.moc"

