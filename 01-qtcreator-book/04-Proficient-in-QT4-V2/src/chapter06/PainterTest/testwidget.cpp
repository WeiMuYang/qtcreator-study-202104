#include <QtGui>

#include "testwidget.h"

const int w = 100;
const int h = 80;

TestWidget::TestWidget(QWidget *parent)
	: QWidget(parent)
{
	currentMode = Gradient;
}

void TestWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.fillRect(0,0,width(),height(),Qt::white);
	switch(currentMode)
	{
		case PenStyle:
			paintPenStyle(painter);
			break;
		case PenCapStyle:
			paintPenCapStyle(painter);
			break;
		case PenJoinStyle:
			paintPenJoinStyle(painter);
			break;
		case BrushStyle:
			paintBrushStyle(painter);
			break;
		case Gradient:
			paintGradient(painter);
		default:
			qWarning("error!");
	}
}

void TestWidget::paintBrushStyle(QPainter& painter)
{
	list.clear();
	list << "Qt::NoBrush" << "Qt::SolidPattern"	<< "Qt::Dense1Pattern" << "Qt::Dense2Pattern"
			 << "Qt::Dense3Pattern" << "Qt::Dense4Pattern"	<< "Qt::Dense5Pattern"
			 << "Qt::Dense6Pattern" << "Qt::Dense7Pattern" 	<< "Qt::HorPattern"
			 << "Qt::VerPattern" << "Qt::CrossPattern" << "Qt::BDiagPattern"
			 << "Qt::FDiagPattern" << "Qt::DiagCrossPattern";
	QBrush brush;
	QRect rect;
	int x = 10;
	int y = 10;
	for(int i=Qt::NoBrush; i <= Qt::DiagCrossPattern; i++)
	{
		brush.setStyle((Qt::BrushStyle)i);
		painter.setBrush(brush);
		rect.setRect(x, y, w, h);
		painter.drawRect(rect);
		painter.drawText(x, y + h + 15, list.at(i)); 
		if((i+1)%4 == 0) {
			x = 10;
			y += h + h/2;
		}
		else
			x += w + w/2;
	}	
}

void TestWidget::paintPenStyle(QPainter& painter)
{
	list.clear();
	list << "Qt::NoPen" << "Qt::SolidLine" << "Qt::DashLine" << "Qt::DotLine" << "Qt::DashDotLine"
		 << "Qt::DashDotDotLine" << "Qt::CustomDashLine";
	QPen pen;
	pen.setWidth(4);
	int y=10;
	for(int i=Qt::NoPen; i <= Qt::CustomDashLine; i++)
	{
		pen.setStyle((Qt::PenStyle)i);
		if(i==Qt::CustomDashLine)
		{
			 QVector<qreal> dashes;
			 qreal space = 4;

			 dashes << 1 << space << 3 << space << 5 << space
			            << 7 << space ;

			 pen.setDashPattern(dashes); 
		}
		painter.setPen(pen);
		painter.drawLine(10, y, 310, y);
		painter.drawText(320, y+5, list.at(i));
		y += 20;
	}
}

void TestWidget::paintPenCapStyle(QPainter& painter)
{
	QPen pen;
	pen.setWidth(20);
	pen.setCapStyle(Qt::SquareCap);
	painter.setPen(pen);
	painter.drawLine(30, 50, 210, 50);
	painter.drawText(250, 55, "Qt::SquareCap");

	pen.setCapStyle(Qt::FlatCap);
	painter.setPen(pen);
	painter.drawLine(30, 100, 210, 100);
	painter.drawText(250, 105, "Qt::FlatCap");
	
	pen.setCapStyle(Qt::RoundCap);
	painter.setPen(pen);
	painter.drawLine(30, 150, 210, 150);
	painter.drawText(250, 155, "Qt::RoundCap");
}

void TestWidget::paintPenJoinStyle(QPainter& painter)
{
	list.clear();
	list << "Qt::BevelJoin" << "Qt::MiterJoin" << "Qt::RoundJoin" << "Qt::SvgMiterJoin";
	QVector<Qt::PenJoinStyle> joinStyle;
	joinStyle << Qt::MiterJoin << Qt::BevelJoin << Qt::RoundJoin << Qt::SvgMiterJoin;
	QPointF points[3] = {
		QPointF(10.0, 30.0),
		QPointF(80.0, 70.0),
		QPointF(10.0, 110.0),			
	};
	qreal dx = 150;
	qreal dy = 0;
	QPen pen;
	pen.setWidth(20);
	for(short i=0; i<4; i++)
	{
		painter.translate(dx, dy);
		pen.setJoinStyle(joinStyle[i]);
		painter.setPen(pen);
		painter.drawPolyline(points, 3);
		painter.drawText(0, 150, list[i]);
	}
}

void TestWidget::setMode(TestMode mode)
{
	currentMode = mode;
	update();
}

void TestWidget::paintGradient(QPainter& painter)
{
	painter.translate(10, 10);
	QLinearGradient linearGradient(0, 0, 200, 100);
	linearGradient.setColorAt(0, Qt::red);
	linearGradient.setColorAt(0.5, Qt::green);
	linearGradient.setColorAt(1, Qt::blue);
	painter.setBrush(linearGradient);
	painter.drawRect(0, 0, 200, 100);

	painter.translate(0, 150);
	QRadialGradient radialGradient(50, 50, 50, 30, 30);	// cx, cy, radius, fx, fy
	radialGradient.setColorAt(0.2, Qt::cyan);
	radialGradient.setColorAt(0.8, Qt::yellow);
	radialGradient.setColorAt(1, Qt::magenta);
	painter.setBrush(radialGradient);
	painter.drawEllipse(0, 0, 100, 100);
	
	painter.translate(0, 150);
	QConicalGradient conicalGradient(60, 40, 30);			// cx, cy, angle
	conicalGradient.setColorAt(0, Qt::gray);
	conicalGradient.setColorAt(0.4, Qt::darkGreen);
	conicalGradient.setColorAt(0.6, Qt::darkMagenta);
	conicalGradient.setColorAt(1, Qt::darkBlue);
	painter.setBrush(conicalGradient);
	painter.drawEllipse(0, 0, 100, 100);
}
