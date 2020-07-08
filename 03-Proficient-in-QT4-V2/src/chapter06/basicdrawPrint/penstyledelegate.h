//
// C++ Interface: penstyledelegate
//
// Description: 
//
//
// Author: zeki <czm@zeki>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef QPENSTYLEDELEGATE_H
#define QPENSTYLEDELEGATE_H

#include <QtGui>

class QPenStyleDelegate : public QAbstractItemDelegate
{
    Q_OBJECT

public:
    QPenStyleDelegate(QObject *parent = 0);

    // painting
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;

};

#endif
