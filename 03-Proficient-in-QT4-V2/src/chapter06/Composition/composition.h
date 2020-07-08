#ifndef COMPOSITION_H
#define COMPOSITION_H

#include <QtGui>

class CompositionCanvas : public QWidget
{
    Q_OBJECT

public:
    CompositionCanvas(QWidget *parent = 0, Qt::WindowFlags f = 0);

public slots:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void compositeModeChanged(int currentRow);
	void alphaChanged(int value);
	void redChanged(int value);
	void greenChanged(int value);
	void blueChanged(int value);

private:
	QPoint pos;
	QImage srcImage;
	QImage dstImage;
	QImage resultImage;
	QPainter::CompositionMode currentMode;
	QColor color;
};

class CompositionWidget : public QWidget
{
    Q_OBJECT

public:
    CompositionWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);

private:
	QHBoxLayout *hLayout;
	QGridLayout *gridLayout;
	
	QLabel *aLabel;
	QLabel *rLabel;
	QLabel *gLabel;
	QLabel *bLabel;
		
	QSlider *aSlider;
	QSlider *rSlider;
	QSlider *gSlider;
	QSlider *bSlider;
			
	QListWidget *list;
	CompositionCanvas *canvas;
};

#endif // COMPOSITION_H
