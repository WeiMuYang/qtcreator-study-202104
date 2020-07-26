#include <QtGui>
#include "TestWidget.h"

TestWidget::TestWidget(QWidget * parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	ui.setupUi(this);
	remain = 45;
	startTimer(60*1000);
}

void TestWidget::on_comboBox_currentIndexChanged(const QString & text)
{
    QFile file(":/qss/" + text.toLower() + ".qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = tr(file.readAll());

    qApp->setStyleSheet(styleSheet);
}

void TestWidget::timerEvent(QTimerEvent *event)
{
	--remain;
	ui.lblRemain->setText(QString(tr("ªπ £%1∑÷÷”")).arg(remain));
}
