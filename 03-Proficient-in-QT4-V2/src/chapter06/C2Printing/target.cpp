#include "target.h"

#include <iostream>
#include <QtGui>

#include <math.h>

using namespace std;

static const double Pi = 3.14159265358979323846264338327950288419717;

Target::Target()
    : m_speed(qrand()%10+1), m_course(qrand() % 6), m_type(qrand()%3), m_attribute(qrand()%3) 
{
    switch(m_attribute) {
    case 0: // 敌方
		m_color.setRgb(255, 0, 0);
		break;
    case 1: // 我方
		m_color.setRgb(0, 255, 255);
		break;
    default: // 不明
		m_color.setRgb(255, 255, 0);
	break;
    }		
    setAcceptDrops(true);
}

Target::Target(qreal speed, qreal course, short type, short attribute)
{
	m_speed = speed;
	m_course = course;
	m_type = type;
	m_attribute = attribute;
    switch(m_attribute) {
    case 0: // 敌方
		m_color.setRgb(255, 0, 0);
		break;
    case 1: // 我方
		m_color.setRgb(0, 255, 255);
		break;
    default: // 不明
		m_color.setRgb(255, 255, 0);
	break;
    }		
    setAcceptDrops(true);
}

QRectF Target::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-20 - adjust, -22 - adjust,
                  40 + adjust, 83 + adjust);
}

void Target::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	QPen pen(m_color);
	pen.setWidth(2);
    painter->setPen(pen);
    switch(m_type) {
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
   	painter->drawLine(0, 0, int(m_speed*5*cos(m_course)), int(m_speed*5*sin(m_course)));
}

void Target::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
     QMenu menu;
     menu.setWindowOpacity(0.8);
     QAction *removeAction = menu.addAction(tr("武器发射"));
     QAction *markAction = menu.addAction(tr("电子干扰"));
     QAction *selectedAction = menu.exec(event->screenPos());
} 

void Target::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	if((m_attribute != Us)) {
		event->ignore();
		return;
	}

    setCursor(Qt::ClosedHandCursor);		
	QByteArray itemData;
	QDataStream dataStream(&itemData, QIODevice::WriteOnly);
	dataStream << mapToParent(QPointF(0, 0));	//传递场景坐标
	
	QMimeData *data = new QMimeData;
	data->setData("application/x-dndtarget", itemData);
	
    QDrag *drag = new QDrag(event->widget());
    drag->setMimeData(data);
    drag->start();
}

void Target::dragEnterEvent(QGraphicsSceneDragDropEvent * event)
{
	if(m_attribute != Foe)
		event->ignore();
    else if(event->mimeData()->hasFormat("application/x-dndtarget")) {
        event->accept();
    } else {
        event->ignore();
    }	
}
  
void Target::dragMoveEvent(QGraphicsSceneDragDropEvent * event)
{
	if(m_attribute != Foe)
		event->ignore();
    else if(event->mimeData()->hasFormat("application/x-dndtarget")) {
        event->accept();
    } else {
        event->ignore();
    }	
}

void Target::dropEvent(QGraphicsSceneDragDropEvent * event)
{
	if(m_attribute != Foe)
		event->ignore();
    else if (event->mimeData()->hasFormat("application/x-dndtarget")) {
        QByteArray itemData = event->mimeData()->data("application/x-dndtarget");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        
        QPointF missile;
        dataStream >> missile;

        QPointF owner = mapToParent(0, 0);
        qreal dx = owner.x() - missile.x();
        qreal dy = owner.y() - missile.y();
        qreal course = atan(dy/dx);
        QPointF test = mapFromScene(missile);
        if (((test.x() > 0) && (test.y() > 0)) ||
        	((test.x() > 0) && (test.y() < 0)) )
        	course = Pi + course;

        Target *target = new Target(12, course, Air, Us);
        target->setPos(missile);
		target->setVisible(true);
        scene()->addItem(target);

        event->accept();
    } else {
        event->ignore();
    }	
}
