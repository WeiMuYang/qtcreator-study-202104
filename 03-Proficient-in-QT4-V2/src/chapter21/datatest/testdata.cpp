#include <QtTest/QtTest>

#include "nautical.h"

//using namespace QTest;

class TestNautical: public QObject
{
    Q_OBJECT

private slots:
    void toKm_data();
    void toKm();
};

void TestNautical::toKm_data()
{
    QTest::addColumn<Nautical>("nautical");
    QTest::addColumn<double>("kilometer");

    QTest::newRow("1") << Nautical(1) << 1.852;
    QTest::newRow("10") << Nautical(10) << 18.52;
    QTest::newRow("100") << Nautical(100) << 185.2;
}

void TestNautical::toKm()
{
    QFETCH(Nautical, nautical);
    QFETCH(double, kilometer);

    //QCOMPARE(nautical.toKilometer(), kilometer);
    QVERIFY(qAbs(nautical.toKilometer() - kilometer < 0.0000001));
}

QTEST_MAIN(TestNautical)
#include "testdata.moc"

