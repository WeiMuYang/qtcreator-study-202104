#ifndef MYITEM_H
#define MYITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsItem>

class MyItem : public QGraphicsItem
{

public:
      MyItem( );

    QRectF boundingRect() const;

    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

signals:

public slots:
};

#endif // MYITEM_H
