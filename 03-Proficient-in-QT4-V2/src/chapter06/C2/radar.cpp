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

RadarView::RadarView( QGraphicsScene * scene, QWidget * parent) :
	QGraphicsView(scene, parent)
{
	startTimer(1000);
}

void RadarView::timerEvent(QTimerEvent *)
{
	QList<QGraphicsItem *> itemList = items();
	QGraphicsItem *item;
	foreach(item, itemList)
	{
		Target* target = (Target*) item;
	   	target->setPos(target->mapToParent(target->speed * cos(target->course), 
	   		target->speed * sin(target->course)));
	}
}
