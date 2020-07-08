//
// C++ Implementation: previewlabel
//
// Description: 
//
//
// Author: zeki <czm@zeki>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "previewlabel.h"

PreviewLabel::PreviewLabel(QWidget *parent)
	: QLabel(parent)
{
	
}

void PreviewLabel::penChanged(QPen& pen)
{
	curPen = pen;
	update();
}

void PreviewLabel::brushChanged(QBrush& brush)
{
	curBrush = brush;
	update();
}

void PreviewLabel::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setPen(curPen);
	painter.setBrush(curBrush);
	painter.drawRect(rect().x() + 10, rect().y() + 10, rect().width() - 20, rect().height() - 20);
}


