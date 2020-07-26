#include "mainwindow.h"
#include "target.h"
#include "radar.h"

static const int TargetCount = 50;

MainWindow::MainWindow()
{
    createActions();
    createMenus();    
    createToolbars();
    statusBar()->showMessage(tr("Ready"));

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    scene = new QGraphicsScene;
    scene->setSceneRect(-400, -300, 800, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    for (int i = 0; i < TargetCount; ++i) {
        Target *target = new Target;
        target->setPos(qrand() % 800 - 400,
                       qrand() % 600 - 300);
		target->setVisible(true);
        scene->addItem(target);
    }

    view = new RadarView(scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(Qt::black);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    setCentralWidget(view);
   	setWindowTitle(tr("º£Õ½Ä£Äâ"));
}


void MainWindow::createActions()
{
    printAct = new QAction(QIcon(":/images/print.png"), tr("&Print..."), this);
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));	
	
}

void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(printAct);
	
}

void MainWindow::createToolbars()
{
	fileToolBar = addToolBar(tr("Print"));
    fileToolBar->addAction(printAct);
	
}

void MainWindow::print()
{
	QPrinter printer;
	if (QPrintDialog(&printer).exec() == QDialog::Accepted) {
    	QPainter painter(&printer);
    	painter.setRenderHint(QPainter::Antialiasing);
    	scene->render(&painter);
	}
}
