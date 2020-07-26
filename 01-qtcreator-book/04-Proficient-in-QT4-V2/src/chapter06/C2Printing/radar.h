//
// C++ Interface: radar
//
// Description: 
//
//
// Author: zeki <czm@zeki>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef RADAR_H
#define RADAR_H

#include <QGraphicsView>

class RadarView : public QGraphicsView
{
Q_OBJECT

public:
	RadarView( QGraphicsScene * scene, QWidget * parent = 0 );

public slots:
    void timerEvent(QTimerEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};
 
#endif
