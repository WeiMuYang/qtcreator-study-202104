//
// C++ Interface: previewlabel
//
// Description: 
//
//
// Author: zeki <czm@zeki>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef PREVIEWLABEL_H
#define previewlabel

#include <QtGui>

class PreviewLabel : public QLabel
{
	Q_OBJECT
	
public:
	PreviewLabel(QWidget *parent = 0);

public slots:
	void penChanged(QPen& pen);
	void brushChanged(QBrush& brush);

protected:
	void paintEvent(QPaintEvent *event);

private:
	QPen curPen;
	QBrush curBrush;
};

#endif
