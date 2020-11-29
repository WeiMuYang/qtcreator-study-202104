#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include "myitem.h"
#include <QPainter>
#include <QGraphicsView>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);





    MainWindow w;
    w.setLayout(w.grid);
    w.resize(800,680);

//    QGraphicsScene scene;
//    scene.setSceneRect(-300,-300,600,600);
//    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

//    MyItem *item=new MyItem;

//    scene.addItem(item);

//    QGraphicsView view(&scene);

//    view.setRenderHint(QPainter::Antialiasing);
//    view.setCacheMode(QGraphicsView::CacheBackground);
//    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//    view.setDragMode(QGraphicsView::ScrollHandDrag);
//    view.resize(400,300);
//    view.show();

     w.show();

    return a.exec();
}
