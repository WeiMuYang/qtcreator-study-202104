#include <QMouseEvent>
#include <QPainter>
#include <QtDebug>

#include "form.h"

Form::Form(QWidget * parent)
	: QWidget(parent)
{
    setAttribute(Qt::WA_NoBackground);
	bDrawing = false;
	curShape = Ellipse;

	resize(800,600);
    bufferImage = QImage(width(), height(), QImage::Format_ARGB32_Premultiplied);
    bufferImage.fill(qRgb(255, 255, 255));
    tempImage = QImage(width(), height(), QImage::Format_ARGB32_Premultiplied);
}

void Form::setShape(ShapeType shape)
{
	curShape = shape;
}

void Form::mousePressEvent( QMouseEvent * event )
{
	bDrawing = true;
	x = event->x();
	y = event->y();
}

void Form::mouseMoveEvent(QMouseEvent *event)
{
	w = event->x() - x;
	h = event->y() - y;
    tempImage = bufferImage;
	paint(tempImage);
}

void Form::mouseReleaseEvent(QMouseEvent *event)
{
	bDrawing = false;
	paint(bufferImage);
}

void Form::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	if(bDrawing)
    	painter.drawImage(QPoint(0, 0), tempImage);
	else
    	painter.drawImage(QPoint(0, 0), bufferImage);
}

void Form::fontChanged(const QFont& font)
{
	textFont = font;
}

void Form::paint(QImage& image)
{
	QPainter painter(&image);
	painter.setPen(curPen);
	painter.setBrush(curBrush);
	switch(curShape) {
	case Rectangle:
		painter.drawRect(x, y, w, h);
		break;
	case Ellipse:
		painter.drawEllipse(x, y, w, h);
		break;
	case Text:
		QFontMetrics metrics(textFont);
		QRect rect = metrics.boundingRect(textFont.family());
		painter.setFont(textFont);
		painter.translate(x, y);
		painter.scale(w/rect.width(), h/rect.height());
		// 因为文字从下面对齐
		painter.drawText(0, rect.height(), textFont.family());
		break;
	}		
	update();
}

void Form::penChanged(QPen& pen)
{
	curPen = pen;
}

void Form::brushChanged(QBrush& brush)
{
	curBrush = brush;
}