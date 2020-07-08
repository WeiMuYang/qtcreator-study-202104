#ifndef COMPASS_H
#define COMPASS_H

#include <QTime>
#include <QWidget>
#include <QtDesigner/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT Compass : public QWidget
{
    Q_OBJECT
    Q_ENUMS(Direction)
    Q_PROPERTY(double angle READ angle WRITE setAngle)
    Q_PROPERTY(int second READ second WRITE setSecond)
    Q_PROPERTY(Direction orientation READ orientation WRITE setOrientation)

public:
    Compass(QWidget *parent = 0);
    enum Direction {East, South, West, North};
    
	inline qreal angle()
	{
		return m_angle;
	};
	inline void setAngle(qreal angle)
	{
	 	m_angle = angle;
	};

	inline int second()
	{
		return m_second;
	};
	void setSecond(int second);
	
	inline Direction orientation() { return m_orientation; };
	void setOrientation(Direction orientation);

public slots:
    void setValue(qreal heading);

signals:
    void valueChanged(qreal heading);

protected:
    void paintEvent(QPaintEvent *event);

protected slots:
	void timerEvent(QTimerEvent *event);

private:
    qreal m_angle;
    qreal m_step;
    qreal m_animateAngle;
    int m_second;
    Direction m_orientation;
};

#endif
