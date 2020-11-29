#ifndef DRAWMAP_H
#define DRAWMAP_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPoint>

class DrawMap : public QObject
{
    Q_OBJECT
public:
    explicit DrawMap(QObject *parent = 0);

signals:

public slots:
protected:
    void paintEvent(QPaintEvent *event)  ;
    void mousePressEvent(QMouseEvent *event)  ;
    void mouseMoveEvent(QMouseEvent *event)  ;
    void mouseReleaseEvent(QMouseEvent *event)  ;
    void resizeEvent(QResizeEvent *event)  ;
    void enterEvent(QEvent *event)  ;
    void leaveEvent(QEvent *event)  ;
    void wheelEvent(QWheelEvent *event)  ;

private:
    double CalcPaperWidthOfPerPixel(double scale_value,
                                                            int paper_width,
                                                            int widget_width);
    void UpdatePaperWidthOfPerPixel();
    void DrawPaper(QPainter &painter);

    int PaperWidth2DrawWidth(int paper_width);
    int DrawWidth2PaperWidth(int draw_width);
    void OnWheelValueChanged(QPoint mouse_pos, QPoint step);

    QPoint MousePoint2PaperPoint(QPoint point);
    void CentenThePaper();


private:
    QColor editor_bg_color_;
    QColor editor_paper_bg_color_;

    int paper_x_;
    int paper_y_;
    int paper_width_;
    int paper_height_;


    double scale_value_;
    double paper_width_of_per_pixel_;

    bool is_mouse_left_btn_down_;
    bool is_mouse_right_btn_down_;

    QPoint mouse_down_pos_;
    int orgin_dif_x_;
    int orgin_dif_y_;

    const double SCALE_VALUE_MAX = 20.0;
    const double SCALE_VALUE_MIN = 0.5;

    QRect draw_paper_rect_;
};

#endif // DRAWMAP_H
