#ifndef TESTWIDGET_H_
#define TESTWIDGET_H_

#include <QtGui>

class TestWidget : public QWidget
{
	Q_OBJECT
	
public:
	TestWidget(QWidget *parent = 0);
	enum TestMode {
		PenStyle,
		PenCapStyle,
		PenJoinStyle,
		BrushStyle,
		Gradient
	};
	TestMode currentMode;
	void setMode(TestMode mode);
	
protected:
	void paintEvent(QPaintEvent *event);
	void paintPenStyle(QPainter& painter);
	void paintPenCapStyle(QPainter& painter);
	void paintPenJoinStyle(QPainter& painter);
	void paintBrushStyle(QPainter& painter);
	void paintGradient(QPainter& painter);
	
private:
	QStringList list;
};


#endif 
