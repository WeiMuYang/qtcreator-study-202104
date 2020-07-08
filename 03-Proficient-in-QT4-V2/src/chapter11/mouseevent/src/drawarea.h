
#ifndef _DRAWAREA_H
#define _DRAWAREA_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

class DrawArea : public QWidget
{
    Q_OBJECT

public:
    DrawArea(QWidget *parent = 0);
    bool isModified() const { return modified; }
    void clearImage();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);

    bool modified;
    bool scribbling;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
};

#endif
