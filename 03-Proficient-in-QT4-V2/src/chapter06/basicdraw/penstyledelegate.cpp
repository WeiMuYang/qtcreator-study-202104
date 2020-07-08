//
// C++ Implementation: penstyledelegate
//
// Description: 
//
//
// Author: zeki <czm@zeki>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "penstyledelegate.h"

QPenStyleDelegate::QPenStyleDelegate(QObject *parent)
    : QAbstractItemDelegate(parent)
{
}

void QPenStyleDelegate::paint(QPainter *painter,
                                const QStyleOptionViewItem &option,
                                const QModelIndex &index) const
{
    QString text = index.data(Qt::DisplayRole).toString();
    Qt::PenStyle penStyle = (Qt::PenStyle)index.data(Qt::UserRole).toInt();
    QRect r = option.rect;

    if (option.state & QStyle::State_Selected) {
        painter->save();
        painter->setBrush(option.palette.highlight());
        painter->setPen(Qt::NoPen);
        painter->drawRect(option.rect);
        painter->setPen(QPen(option.palette.highlightedText(),2, penStyle));
    }
    else
    	painter->setPen(penStyle);
    painter->drawLine(0, r.y() + r.height()/2, r.right(), r.y() + r.height()/2);

    if (option.state & QStyle::State_Selected)
        painter->restore();

}

QSize QPenStyleDelegate::sizeHint(const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const
{
    return QSize(100,30);
}

