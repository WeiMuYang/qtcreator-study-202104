#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtGui>

class MyWidget : public QWidget
{
	Q_OBJECT
public:
	MyWidget(QWidget* parent = 0);
protected slots:
	void test(QListWidgetItem* item);
private:
	QVBoxLayout *layout;
	QListWidget *list;
		
};

#endif
