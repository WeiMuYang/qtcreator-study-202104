#ifndef ARRROWWIDGET_H_
#define ARROWWIDGET_H_

#include <QtGui>

class ArrowWidget : public QWidget
{
	Q_OBJECT
	
public:
	ArrowWidget(QWidget *parent = 0);
	
protected:
	void paintEvent(QPaintEvent *event);
	
private:
	QStringList list;
};


#endif /*BRUSHWIDGET_H_*/
