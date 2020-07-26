#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow()
{
	clipboard = QApplication::clipboard();
	imageWidget = new ImageWidget;
    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
 	imageWidget->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    scrollArea->setWidget(imageWidget);
	scrollArea->widget()->setMinimumSize(320, 240);	
    setCentralWidget(scrollArea);

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
	setWindowTitle(tr("zeki"));
	setFocusPolicy(Qt::StrongFocus);

	index = 0;
	
	imageDir.setPath(QDir::currentPath());
	QStringList filter;
	filter << "*.jpg" << "*.bmp" << "*.jpeg" << "*.png" << "*.xpm";
	imageList = imageDir.entryList ( filter, QDir::Files );
	next();
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
	QRect childRect = scrollArea->childrenRect();
	imageWidget->resize(childRect.size());
}

void MainWindow::createActions()
{
    dirAct = new QAction(QIcon(":/images/open.png"), tr("Open"), this);
    dirAct->setShortcut(QKeySequence::Open);
    connect(dirAct, SIGNAL(triggered()), this, SLOT(selectDir()));

	prevAct = new QAction(QIcon(":/images/previous.png"), tr("Previous"), this);
    prevAct->setShortcut(QKeySequence::Back);
    connect(prevAct, SIGNAL(triggered()), this, SLOT(prev()));

	nextAct = new QAction(QIcon(":/images/next.png"), tr("Next"), this);
    nextAct->setShortcut(QKeySequence::Forward);
    connect(nextAct, SIGNAL(triggered()), this, SLOT(next()));

    leftAct = new QAction(QIcon(":/images/rotate_left.png"), tr("Left"), this);
    leftAct->setShortcut(tr("Ctrl+L"));
    connect(leftAct, SIGNAL(triggered()), this, SLOT(rotateLeft()));

    rightAct = new QAction(QIcon(":/images/rotate_right.png"), tr("Right"), this);
    rightAct->setShortcut(tr("Ctrl+R"));
    connect(rightAct, SIGNAL(triggered()), this, SLOT(rotateRight()));

    zoomInAct = new QAction(QIcon(":/images/zoomin.png"), tr("ZoomIn"), this);
    zoomInAct->setShortcut(QKeySequence::ZoomIn);

    connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn()));
    zoomOutAct = new QAction(QIcon(":/images/zoomout.png"), tr("ZoomOut"), this);
    zoomOutAct->setShortcut(QKeySequence::ZoomOut);
    connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut()));

    actualSizeAct = new QAction(QIcon(":/images/actualsize.png"), tr("Actual"), this);
    actualSizeAct->setShortcut(Qt::Key_Home);
    connect(actualSizeAct, SIGNAL(triggered()), this, SLOT(actualSize()));

    fitSizeAct = new QAction(QIcon(":/images/fitwindow.png"), tr("Fit"), this);
    fitSizeAct->setShortcut(Qt::Key_End);
    connect(fitSizeAct, SIGNAL(triggered()), this, SLOT(fitSize()));

    copyAct = new QAction(QIcon(":/images/copy.png"), tr("Copy"), this);
    copyAct->setShortcut(QKeySequence::Copy);
    connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));

    printAct = new QAction(QIcon(":/images/print.png"), tr("Print"), this);
    printAct->setShortcut(QKeySequence::Print);
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

    presentAct = new QAction(QIcon(":/images/present.png"), tr("Present"), this);
    presentAct->setShortcut(Qt::Key_F5);
    connect(presentAct, SIGNAL(triggered()), this, SLOT(present()));
}

void MainWindow::createMenus()
{
    naviMenu = menuBar()->addMenu(tr("Navigation"));
    naviMenu->addAction(prevAct);
    naviMenu->addAction(nextAct);

    operMenu = menuBar()->addMenu(tr("Operation"));
    operMenu->addAction(leftAct);
    operMenu->addAction(rightAct);
    operMenu->addAction(zoomInAct);
    operMenu->addAction(zoomOutAct);
    operMenu->addAction(actualSizeAct);
    operMenu->addAction(fitSizeAct);
    operMenu->addSeparator();
	operMenu->addAction(copyAct);
    operMenu->addAction(printAct);
    operMenu->addAction(presentAct);
}

void MainWindow::createToolBars()
{
    naviToolBar = addToolBar(tr("Navigation"));
    naviToolBar->addAction(dirAct);
    naviToolBar->addSeparator();
    naviToolBar->addAction(prevAct);
    naviToolBar->addAction(nextAct);

    operToolBar = addToolBar(tr("Operation"));
    operToolBar->addAction(leftAct);
    operToolBar->addAction(rightAct);
    operToolBar->addAction(zoomInAct);
    operToolBar->addAction(zoomOutAct);
    operToolBar->addAction(actualSizeAct);
    operToolBar->addAction(fitSizeAct);
    operToolBar->addSeparator();
	operToolBar->addAction(copyAct);
    operToolBar->addAction(printAct);
    operToolBar->addAction(presentAct);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::selectDir()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
											"/windows/E/Wife/USA photo/5.3",
											QFileDialog::ShowDirsOnly
											| QFileDialog::DontResolveSymlinks);
	if(dir.isEmpty())
		return;
	imageDir.setPath(dir);
	QStringList filter;
	filter << "*.jpg" << "*.bmp" << "*.jpeg" << "*.png" << "*.xpm";
	imageList = imageDir.entryList ( filter, QDir::Files );
	next();
}

void MainWindow::next()
{
	if(index < imageList.size())
	{
		imageWidget->setPixmap(imageDir.absolutePath() + QDir::separator() + imageList.at(index));
		statusBar()->showMessage(imageList.at(index));
		index++;
	}
}

void MainWindow::prev()
{
	if(index > 0)
	{
		imageWidget->setPixmap(imageDir.absolutePath() + QDir::separator() + imageList.at(index));
		statusBar()->showMessage(imageList.at(index));
		index--;
	} 	
}

void MainWindow::rotateLeft()
{
	imageWidget->setAngle(-90);
}

void MainWindow::rotateRight()
{
	imageWidget->setAngle(90);
}

void MainWindow::zoomIn()
{
	imageWidget->scale *= 1.25;
	zoomInAct->setEnabled(imageWidget->scale < 3);
	zoomOutAct->setEnabled(imageWidget->scale > 0.333);
	imageWidget->resize(imageWidget->scale * scrollArea->size());
}

void MainWindow::zoomOut()
{
	imageWidget->scale *= 0.8;
	zoomInAct->setEnabled(imageWidget->scale < 3);
	imageWidget->resize(imageWidget->scale * scrollArea->size());
}

void MainWindow::actualSize()
{
	imageWidget->scale = 1;
	imageWidget->bFit = false;
	imageWidget->update();
}

void MainWindow::fitSize()
{
	imageWidget->scale = 1;
	imageWidget->bFit = true;
	imageWidget->update();
}

void MainWindow::print()
{
	QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if (dialog.exec()) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = imageWidget->size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(imageWidget->rect());
        painter.drawPixmap(0, 0, QPixmap::grabWidget(imageWidget, imageWidget->rect()));
    }
}

void MainWindow::present()
{
	statusBar()->hide();
	menuBar()->hide();
	naviToolBar->hide();
	operToolBar->hide();
	showFullScreen();
}

void MainWindow::copy()
{
	QPixmap pix = imageWidget->getPixmap();
	clipboard->setImage(pix.toImage());	
}
