#include <QtGui>
#include <QtTest/QtTest>

class TestGui: public QObject
{
    Q_OBJECT

private slots:
    void testGui();

};

void TestGui::testGui()
{
    QSpinBox spinBox;

    spinBox.setMinimum(1);
    spinBox.setMaximum(100);
    spinBox.setSingleStep(1);
    spinBox.setValue(1);
    
    QTest::keyClick(&spinBox, Qt::Key_Up);

    QCOMPARE(spinBox.value(), 2);
}

QTEST_MAIN(TestGui)
#include "guitest.moc"

