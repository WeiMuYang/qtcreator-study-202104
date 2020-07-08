#include <QtGui>

#include "testwidget.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
	resize(800,600);
	testWidget = new TestWidget(this);
	createActions();
	createToolBars();
	setCentralWidget(testWidget);	
}

void MainWindow::createActions()
{
    penStyleAct = new QAction(QIcon(":/images/pen.png"), tr("&Pen Style"), this);
    penStyleAct->setCheckable(true);
    
    penCapStyleAct = new QAction(QIcon(":/images/pencapstyle.png"), tr("Pen &CapStyle"), this);
    penCapStyleAct->setCheckable(true);
    
    penJoinStyleAct = new QAction(QIcon(":/images/penjoinstyle.png"), tr("Pen &JoinStyle"), this);
    penJoinStyleAct->setCheckable(true);
    
    brushStyleAct = new QAction(QIcon(":/images/brush.png"), tr("&Brush Style"), this);
    brushStyleAct->setCheckable(true);
    
    gradientAct = new QAction(QIcon(":/images/gradient.png"), tr("&Gradient"), this);
    gradientAct->setCheckable(true);
    gradientAct->setChecked(true);
    
    testGroup = new QActionGroup(this);
    testGroup->setExclusive(true);
    testGroup->addAction(penStyleAct);
    testGroup->addAction(penCapStyleAct);
    testGroup->addAction(penJoinStyleAct);
    testGroup->addAction(brushStyleAct);
    testGroup->addAction(gradientAct);
    connect(testGroup, SIGNAL(triggered(QAction *)), this, SLOT(setMode(QAction *)));
}

void MainWindow::createToolBars()
{
	testToolBar = addToolBar(tr("test"));
	testToolBar->addAction(penStyleAct);
	testToolBar->addAction(penCapStyleAct);
	testToolBar->addAction(penJoinStyleAct);
	testToolBar->addAction(brushStyleAct);
	testToolBar->addAction(gradientAct);
}

void MainWindow::setMode(QAction *action)
{
	if(action == penStyleAct)
		testWidget->setMode(TestWidget::PenStyle);
	else if(action == penCapStyleAct)
		testWidget->setMode(TestWidget::PenCapStyle);
	else if(action == penJoinStyleAct)
		testWidget->setMode(TestWidget::PenJoinStyle);
	else if(action == brushStyleAct)
		testWidget->setMode(TestWidget::BrushStyle);
	else /* gradient */
		testWidget->setMode(TestWidget::Gradient);
}
