#ifndef SVGWINDOW_H
#define SVGWINDOW_H

#include <QPoint>
#include <QScrollArea>
#include <QString>

class QKeyEvent;
class QMouseEvent;

class SvgWindow : public QScrollArea
{
public:
    SvgWindow();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void openFile(const QString &file);
    void setRenderer();

private:
    QPoint mousePressPos;
    QPoint scrollBarValuesOnMousePress;
    QString currentPath;
};

#endif
