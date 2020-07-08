#include <QtDebug>

#include "drawwidget.h"

DrawWidget::DrawWidget(QWidget *parent)
	: QWidget(parent)
{
	bDraw = false;
}

void DrawWidget::readSvg(QString fileName)
{
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly))
		return;
	if (!doc.setContent(&file)) {
		file.close();
		return;
	}
	file.close();
	bDraw = true;
	update();
}
	
void DrawWidget::paintEvent(QPaintEvent *event)
{
	if(!bDraw)
		return;
	QPainter painter(this);
    QDomElement root = doc.documentElement();
    QDomElement child = root.firstChildElement();
	QRect rect;
    while (!child.isNull()) {
        if(child.tagName() == "rect") {
			setPenAndBrush(painter, child);
			rect.setRect(child.attribute("x").toInt(),
				child.attribute("y").toInt(),
				child.attribute("width").toInt(),
				child.attribute("height").toInt());
			painter.drawRect(rect);
		}		
		else if (child.tagName() == "circle") {
			setPenAndBrush(painter, child);
			int cx=child.attribute("cx").toInt();
			int cy=child.attribute("cy").toInt();
			int r=child.attribute("r").toInt();
			rect.setRect(cx-r, cy-r, 2*r, 2*r);
			painter.drawEllipse(rect);
		}
		else if (child.tagName() == "text") {
			setPenAndBrush(painter, child);
			int x=child.attribute("x").toInt();
			int y=child.attribute("y").toInt();
			QFont font;
			font.setFamily(child.attribute("font-family"));
			font.setPointSize(child.attribute("font-size").toInt());
			painter.setFont(font);
			painter.drawText(x, y, child.text());
		}
		else if (child.tagName() == "polyline") {
			setPenAndBrush(painter, child);
			QString points = child.attribute("points");
			QStringList list = points.split(" ");
			QPoint pointArray[100];
			int i=0;
			foreach(QString point, list) {
				int index = point.indexOf(",");
				pointArray[i].setX(point.left(index).toInt());
				pointArray[i].setY(point.mid(index + 1).toInt());
				i++;
			}
			painter.drawPolyline(pointArray, i);
		}
        child = child.nextSiblingElement();
    }
}

void DrawWidget::setPenAndBrush(QPainter& painter, QDomElement& domElement)
{
	bool ok;
	QPen pen;
	QBrush brush;
	QString fill = domElement.attribute("fill");
	if(fill != "none") {
		QRgb color = (QRgb)fill.toInt(&ok, 16);  
		brush.setColor(QColor(color));
	}
	QString stroke = domElement.attribute("stroke");
	if(stroke != "none") {
		if(stroke == "blue")
			pen.setColor(Qt::blue);				
		else if(stroke == "red")
			pen.setColor(Qt::red);
		else {
			QRgb color = (QRgb)stroke.toInt(&ok, 16);
			pen.setColor(QColor(color));
		}
	}
	QString strokeWidth = domElement.attribute("stroke-width");
	pen.setWidth(strokeWidth.toInt());
	painter.setPen(pen);
	painter.setBrush(brush);	
}

