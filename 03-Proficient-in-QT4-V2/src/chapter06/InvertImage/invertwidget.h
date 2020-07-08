#ifndef BRUSHWIDGET_H_
#define BRUSHWIDGET_H_

#include <QtGui>

class InvertWidget : public QWidget
{
	Q_OBJECT
	
public:
	InvertWidget(QWidget *parent = 0);
	
protected:
	void paintEvent(QPaintEvent *event);
	
private:
	QImage image;
};


#endif /*BRUSHWIDGET_H_*/
