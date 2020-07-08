#include <QSvgRenderer>

#include <QApplication>
#include <QPainter>
#include <QImage>
#include <QWheelEvent>
#include <QtDebug>

#include "svgview.h"

SvgView::SvgView(const QString &file, QWidget *parent)
    : QWidget(parent)
{
    doc = new QSvgRenderer(file, this);
    connect(doc, SIGNAL(repaintNeeded()),
            this, SLOT(update()));
}

void SvgView::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setViewport(0, 0, width(), height());
    doc->render(&p);
}

QSize SvgView::sizeHint() const
{
    if (doc)
        return doc->defaultSize();
    return QWidget::sizeHint();
}

void SvgView::wheelEvent(QWheelEvent *e)
{
    const double diff = 0.1;
    QSize size = doc->defaultSize();
    int width  = size.width();
    int height = size.height();
    if (e->delta() > 0) {
        width = int(this->width()+this->width()*diff);
        height = int(this->height()+this->height()*diff);
    } else {
        width  = int(this->width()-this->width()*diff);
        height = int(this->height()-this->height()*diff);
    }
    resize(width, height);
}
