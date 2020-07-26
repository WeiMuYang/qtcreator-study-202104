#include <QtGui>
#include <QtTest/QtTest>

class TestGui: public QObject
{
    Q_OBJECT

private slots:
    void testGui_data();
    void testGui();
};

void TestGui::testGui_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<int>("expected");

    QTestEventList list1;
    list1.addKeyClick(Qt::Key_Up);
    QTest::newRow("up") << list1 << 11;

    QTestEventList list2;
    list2.addKeyClick(Qt::Key_Down);
    QTest::newRow("down") << list2 << 9 ;
}

void TestGui::testGui()
{
    QFETCH(QTestEventList, events);
    QFETCH(int, expected);

    QSpinBox spinBox;
    spinBox.setMinimum(1);
    spinBox.setMaximum(100);
    spinBox.setSingleStep(1);
    spinBox.setValue(10);

    events.simulate(&spinBox);

    QCOMPARE(spinBox.value(), expected);
}

QTEST_MAIN(TestGui)
#include "guireplay.moc"

