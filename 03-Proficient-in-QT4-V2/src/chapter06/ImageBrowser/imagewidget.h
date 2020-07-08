#ifndef IMAGEWIDGET_H_
#define IMAGEWIDGET_H_

#include <QtGui>

class ImageWidget : public QWidget
{
	Q_OBJECT
	
public:
	bool bFit;
	qreal scale;

public:
	ImageWidget(QWidget *parent = 0);
	void setPixmap(QString fileName);
	QPixmap getPixmap();
	void setAngle(qreal rotateAngle);
	    
protected:
	void paintEvent(QPaintEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
	void dragLeaveEvent(QDragLeaveEvent *event);

private:
	QPixmap pixmap; 
	qreal angle;
};

#endif /*IMAGEWIDGET_H_*/
