#include <QtGui>

#include "arrowwidget.h"

ArrowWidget::ArrowWidget(QWidget *parent)
	: QWidget(parent)
{
}

void ArrowWidget::paintEvent(QPaintEvent *event)
{
	QPainterPath path;
	path.moveTo(10,100);
	path.cubicTo(10, 100, 100, 10, 200, 70);
	path.lineTo(200, 50);
	path.lineTo(220, 80);
	path.lineTo(200, 110);
	path.lineTo(200, 90);
	path.cubicTo(200, 100, 100, 50, 50, 100);

	QPainter painter(this);
	painter.fillRect(0, 0, width(), height(), Qt::white);
	QPen pen(QColor(255, 0, 0), 2);
	painter.setPen(pen);
	painter.drawPath(path);
	
	QLinearGradient linearGrad(QPointF(200, 0), QPointF(1000, 0));
    linearGrad.setColorAt(0, Qt::black);
    linearGrad.setColorAt(1, Qt::white); 
	QFont font("隶书", 80);
	font.setBold(true); 
	QPainterPath textPath;
	textPath.addText(200, 300, font, tr("电子工业出版社"));
	painter.setBrush(linearGrad);
	painter.drawPath(textPath);
}

