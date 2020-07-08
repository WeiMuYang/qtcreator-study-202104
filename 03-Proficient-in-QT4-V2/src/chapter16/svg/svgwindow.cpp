#include <QtGui>

#include "svgview.h"
#include "svgwindow.h"

SvgWindow::SvgWindow()
    : QScrollArea()
{
    QWidget *view = new QWidget(this);
    setWidget(view);
}

void SvgWindow::openFile(const QString &file)
{
    currentPath = file;
    setRenderer();
}

void SvgWindow::setRenderer()
{
    QWidget *view;

    view = new SvgView(currentPath, this);

    setWidget(view);
    view->show();
}

void SvgWindow::mousePressEvent(QMouseEvent *event)
{
    mousePressPos = event->pos();
    scrollBarValuesOnMousePress.rx() = horizontalScrollBar()->value();
    scrollBarValuesOnMousePress.ry() = verticalScrollBar()->value();
    event->accept();
}

void SvgWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (mousePressPos.isNull()) {
        event->ignore();
        return;
    }

    horizontalScrollBar()->setValue(scrollBarValuesOnMousePress.x() - event->pos().x() + mousePressPos.x());
    verticalScrollBar()->setValue(scrollBarValuesOnMousePress.y() - event->pos().y() + mousePressPos.y());
    horizontalScrollBar()->update();
    verticalScrollBar()->update();
    event->accept();
}

void SvgWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mousePressPos = QPoint();
    event->accept();
}
