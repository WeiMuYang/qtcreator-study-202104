#include "target.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QAction>

#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;

Target::Target()
    : speed(qrand()%10+1), type(qrand()%3), attribute(qrand()%3)
{
    course = (qrand() % 360);
    switch(attribute) {
    case 0: // 敌方
		color.setRgb(255, 0, 0);
		break;
    case 1: // 我方
		color.setRgb(0, 255, 255);
		break;
    default: // 不明
		color.setRgb(255, 255, 0);
	break;
    }		
}

QRectF Target::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-20 - adjust, -22 - adjust,
                  40 + adjust, 83 + adjust);
}

void Target::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	QPen pen(color);
	pen.setWidth(2);
    painter->setPen(pen);
    switch(type) {
    case 0: 	//水面目标 
		painter->drawEllipse(-15, -15, 30, 30);
    	break;
    case 1:  	// 水下目标
		painter->drawArc(-15, -15, 30, 30, 180*16, 180*16);
    	break;
   default:		// 空中目标
		painter->drawLine(-15, 0, 0, -15);
		painter->drawLine(0, -15, 15, 0);
    	break;
   }
   	painter->drawLine(0, 0, int(speed*5*cos(course)), int(speed*5*sin(course)));
}

void Target::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
     QMenu menu;
     menu.setWindowOpacity(0.8);
     QAction *removeAction = menu.addAction(tr("武器发射"));
     QAction *markAction = menu.addAction(tr("电子干扰"));
     QAction *selectedAction = menu.exec(event->screenPos());
} 
