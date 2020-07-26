#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QtGui>
#include <QtXml>

class DrawWidget : public QWidget
{
	Q_OBJECT

public:
	DrawWidget(QWidget *parent = 0);
	void readSvg(QString fileName);
	
protected:
	void paintEvent(QPaintEvent *event);

private:
	QDomDocument doc;
	bool bDraw;
	
	void setPenAndBrush(QPainter& painter, QDomElement& domElement);
};

#endif
