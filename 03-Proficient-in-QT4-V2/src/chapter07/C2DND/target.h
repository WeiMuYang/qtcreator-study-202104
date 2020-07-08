#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsItem>
#include <QObject>

class Target : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Target();
    Target(qreal speed, qreal course, short type, short attribute);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

public:
    qreal m_course;
    qreal m_speed;
    short m_type; 		// surface, undersurface, air
    short m_attribute; 	// friend, foe, unknown
    QColor m_color;
    
protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void dragEnterEvent(QGraphicsSceneDragDropEvent * event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent * event);  
    void dropEvent(QGraphicsSceneDragDropEvent * event);

private:
	enum Attr {
		Foe,
		Us,
		Unknown
	};
	enum Type {
		Surface,
		UnderSurface,
		Air
	};
};

#endif
