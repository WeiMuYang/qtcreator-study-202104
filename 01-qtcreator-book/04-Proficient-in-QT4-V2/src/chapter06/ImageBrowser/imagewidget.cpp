#include <QtCore>
#include <QtDebug>
#include "imagewidget.h"

ImageWidget::ImageWidget(QWidget *parent)
	: QWidget(parent)
{
	QDesktopWidget desktop;
	pixmap = QPixmap(desktop.width(), desktop.height());
	scale = 1;
	angle = 0;
	bFit = true;

    setAcceptDrops(true);
}

void ImageWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	if(angle)
	{
	    QPointF center(width()/2.0,height()/2.0);
		painter.translate(center);
		painter.rotate(angle);
		painter.translate(-center);
	}
	if(bFit)
	{
		QPixmap fitPixmap = pixmap.scaled(width(),height(), Qt::KeepAspectRatio);
		painter.drawPixmap(0, 0, fitPixmap);
	}
	else
		painter.drawPixmap(0, 0, pixmap);
}

void ImageWidget::setPixmap(QString fileName)
{
	pixmap.load(fileName);
	update();
}

QPixmap ImageWidget::getPixmap()
{
	return pixmap;
}

void ImageWidget::setAngle(qreal rotateAngle)
{
	angle += rotateAngle;
	update();
}

void ImageWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
		QString localFile;
		QRegExp rx("\\.(jpg|bmp|jpeg|png|xpm)$", Qt::CaseInsensitive);
		foreach(QUrl url , event->mimeData()->urls()) {
			localFile = url.toLocalFile();
			if(rx.indexIn(localFile) >= 0) {
				event->accept();
				return;
			}
			else {
			        event->ignore();
			}
		}
    } else {
        event->ignore();
    }
}

void ImageWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasUrls()) {
		QString localFile;
		QRegExp rx("\\.(jpg|bmp|jpeg|png|xpm)$", Qt::CaseInsensitive);
		foreach(QUrl url , event->mimeData()->urls()) {
			localFile = url.toLocalFile();
			if(rx.indexIn(localFile) >= 0) {
				event->accept();
				setPixmap(localFile);
				return;
			}
			else {
			        event->ignore();
			}
		}
    } else {
        event->ignore();
    }
}

void ImageWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
 	event->accept();
}

