#ifndef FORM_H
#define FORM_H

#include <QtGui>

class Form : public QWidget
{
	Q_OBJECT

public:
	Form(QWidget * parent = 0);
	enum ShapeType {
		Line,
		Polyline,
		Rectangle,
		Polygon,
		Arc,
		Pie,
		Chord,
		Ellipse,
		Text
	};
	void setShape(ShapeType shape);

public slots:
	void fontChanged(const QFont& font);
	void penChanged(QPen& pen);
	void brushChanged(QBrush& brush);

protected:
	bool bDrawing;
	int x,y,w,h;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);

private:
	QImage bufferImage;
	QImage tempImage;
	ShapeType curShape;
	QPen curPen;
	QBrush curBrush;
	QFont textFont;
	int thickness;

	void paint(QImage& image);
};

#endif

