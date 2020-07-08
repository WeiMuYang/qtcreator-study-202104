#include <QtGui>

#include "compass.h"

const int labelX = -8;
const int labelY = -65;

Compass::Compass(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Compass"));
    m_angle = 0;	// North
    m_step = 0;
	m_animateAngle = 0;    
    m_second = 0;
    resize(200, 200);
}

void Compass::paintEvent(QPaintEvent *)
{
    static const QPoint needle[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };

	QColor poleColor(127, 0, 127);
    QColor scaleColor(0, 127, 127, 191);

    int side = qMin(width(), height());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(poleColor);

    painter.save();
    painter.drawConvexPolygon(needle, 3);
    painter.restore();

    painter.setPen(poleColor);
	QFont font;
	font.setBold(true);
	font.setPointSize(18);
	painter.setFont(font);

	painter.rotate(-m_animateAngle);
    for (int i = 0; i < 8; ++i) {
        painter.drawLine(0, -96, 0, -88);
        switch(i) {
        case 0:
        	painter.drawText(labelX, labelY, "N");
        	break;
        case 2:
        	painter.drawText(labelX, labelY, "E");
        	break;
        case 4:
        	painter.drawText(labelX, labelY, "S");
        	break;
        case 6:
        	painter.drawText(labelX, labelY, "W");
        	break;
        }	
        painter.rotate(45.0);
    }

    painter.setPen(scaleColor);

    for (int j = 0; j < 60; ++j) {
    	if(j % 15 != 0)
        	painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
}

void Compass::setValue(qreal heading)
{
	m_angle = heading;
}
 
void Compass::timerEvent(QTimerEvent *event)
{
	m_animateAngle += m_step;
	if(m_animateAngle <= m_angle)
		update();
	else
		killTimer(event->timerId());
}

void Compass::setSecond(int second)
{
 	m_second = second;
 	m_animateAngle = 0;
 	if (m_second <= 0)
 		m_step = m_angle;
 	else
 		m_step = m_angle / (second * 20);
 	startTimer(50);
}


