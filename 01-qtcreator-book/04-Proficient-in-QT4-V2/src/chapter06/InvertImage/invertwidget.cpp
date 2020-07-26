#include <QtGui>

#include "invertwidget.h"

InvertWidget::InvertWidget(QWidget *parent)
	: QWidget(parent)
{
	image = QImage(800, 600, QImage::Format_RGB32);
	image.load("plane.jpg");
	image.invertPixels();
}


void InvertWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.drawImage(0, 0, image);
}

