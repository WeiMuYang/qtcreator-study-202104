#ifndef SVGVIEW_H
#define SVGVIEW_H

#include <QWidget>
#include <QImage>

class QPaintEvent;
class QSvgRenderer;
class QWheelEvent;

class SvgView : public QWidget
{
    Q_OBJECT

public:
    SvgView(const QString &file, QWidget *parent=0);

    virtual QSize sizeHint() const;
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void wheelEvent(QWheelEvent *event);

private:
    QSvgRenderer *doc;
};

#endif
