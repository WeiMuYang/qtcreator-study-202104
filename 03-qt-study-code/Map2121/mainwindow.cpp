#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    grid = new QGridLayout(this);
    grid->addWidget(ui->sceneWidget);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1000,1000);
    QGraphicsView *view=new QGraphicsView(scene,ui->sceneWidget);
    MyItem *item=new MyItem;

    scene->addItem(item);


    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->resize(800,800);



    view->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
