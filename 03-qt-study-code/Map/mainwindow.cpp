
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QGraphicsScene scene;
    scene.setSceneRect(-300,-300,600,600);
    QPolygonF myPolygon1;
    myPolygon1 << QPointF(0,10) << QPointF(20,10);
    QPolygonF myPolygon2;
    myPolygon2 << QPointF(10,0) << QPointF(10,20);
    QPixmap pixmap(20, 20);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);

    QVector<qreal> dashes;//line style--虚线
    qreal space = 2;
    dashes << 2 << space << 2 <<space;
    QPen pen(Qt::lightGray,1);
    pen.setDashPattern(dashes);
    pen.setWidth(1);

    painter.setPen(pen);
    painter.translate(0, 0);
    painter.drawPolyline(myPolygon1);
    painter.drawPolyline(myPolygon2);
    scene.setBackgroundBrush(pixmap);


    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    QGraphicsView view(&scene);

    view.setRenderHint(QPainter::Antialiasing);

    view.setCacheMode(QGraphicsView::CacheBackground);

    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    view.setDragMode(QGraphicsView::ScrollHandDrag);

    view.resize(400,300);

    view.show();





}

MainWindow::~MainWindow()
{
    delete ui;
}
