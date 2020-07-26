//
// C++ Implementation: radar
//
// Description: 
//
//
// Author: zeki <czm@zeki>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include <math.h>
#include <QtGui>

#include "radar.h"
#include "target.h"
#include "mainwindow.h"

RadarView::RadarView( QGraphicsScene * scene, QWidget * parent)
	: QGraphicsView(scene, parent)
{
	setMouseTracking(true);
	resize(800,600);
	startTimer(1000);
}

void RadarView::timerEvent(QTimerEvent *)
{
	QList<QGraphicsItem *> itemList = items();
	QGraphicsItem *item;
	foreach(item, itemList)
	{
		Target* target = (Target*) item;
	   	target->setPos(target->mapToParent(target->m_speed * cos(target->m_course), 
	   		target->m_speed * sin(target->m_course)));
	}
}

void RadarView::mouseMoveEvent(QMouseEvent *event)
{
	QPoint pos = event->pos();
	QPointF scenePos = mapToScene(pos);
	MainWindow *mainWin = qobject_cast<MainWindow*>(this->parentWidget());
	QString coords = QString("scene coords:x=%1,y=%2;view coords:x=%3,y=%4").
		arg((double)scenePos.x()).arg((double)scenePos.y()).arg(pos.x()).arg(pos.y());
	if (QGraphicsItem *item = itemAt(event->pos())) {
		QPointF itemPos = item->mapFromScene(scenePos);
		coords += QString(";item coords:x=%1,y=%2").arg(itemPos.x()).arg(itemPos.y());
	}
	
	mainWin->statusBar()->showMessage(coords);
}

