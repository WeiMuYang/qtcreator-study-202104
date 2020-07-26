#ifndef TESTWIDGET_H_
#define TESTWIDGET_H_

#include <QWidget>
#include "ui_test.h"

class TestWidget : public QWidget
{
	Q_OBJECT
	
public:
	TestWidget(QWidget * parent = 0, Qt::WindowFlags f = 0);

protected slots:
	void timerEvent(QTimerEvent *event);
	
private slots:
	void on_comboBox_currentIndexChanged(const QString & text);

private:
	Ui::test ui;
	short remain;
};

#endif /*TESTWIDGET_H_*/
