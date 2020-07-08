#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow()
{
	resize(800,600);
	form = new Form(this);
	setCentralWidget(form);
	setWindowTitle(tr("Image Print"));
	
	createActions();
	createMenus();
	createToolBars();
	createStatusBar();
	createDockWindows();
}

void MainWindow::draw(QAction* action)
{
	if(action == lineAct)
		form->setShape(Form::Line);
	else if(action == polylineAct)
		form->setShape(Form::Polyline);
	else if(action == rectangleAct)
		form->setShape(Form::Rectangle);
	else if(action == polygonAct)
		form->setShape(Form::Polygon);
	else if(action == arcAct)
		form->setShape(Form::Arc);
	else if(action == pieAct)
		form->setShape(Form::Pie);
	else if(action == chordAct)
		form->setShape(Form::Chord);
	else if(action == ellipseAct)
		form->setShape(Form::Ellipse);
	else if((action == textAct))
		form->setShape(Form::Text);
}

void MainWindow::createActions()
{
    lineAct = new QAction(QIcon(":/images/line.png"), tr("&Line"), this);
	lineAct->setCheckable(true);

    polylineAct = new QAction(QIcon(":/images/polyline.png"), tr("&polyline"), this);
	polylineAct->setCheckable(true);

    rectangleAct = new QAction(QIcon(":/images/rectangle.png"), tr("&rectangle"), this);
	rectangleAct->setCheckable(true);

    polygonAct = new QAction(QIcon(":/images/polygon.png"), tr("&polygon"), this);
	polygonAct->setCheckable(true);

    arcAct = new QAction(QIcon(":/images/arc.png"), tr("&Arc"), this);
	arcAct->setCheckable(true);

    pieAct = new QAction(QIcon(":/images/pie.png"), tr("&Pie"), this);
	pieAct->setCheckable(true);

    chordAct = new QAction(QIcon(":/images/chord.png"), tr("&Chord"), this);
	chordAct->setCheckable(true);

    ellipseAct = new QAction(QIcon(":/images/ellipse.png"), tr("&Ellipse"), this);
	ellipseAct->setCheckable(true);
	ellipseAct->setChecked(true);

    textAct = new QAction(QIcon(":/images/text.png"), tr("&Text"), this);
	textAct->setCheckable(true);

    printAct = new QAction(QIcon(":/images/print.png"), tr("&Print..."), this);

	drawActGroup = new QActionGroup(this);
// 	drawActGroup->setExclusive(true);
	drawActGroup->addAction(lineAct);
	drawActGroup->addAction(polylineAct);
	drawActGroup->addAction(rectangleAct);
	drawActGroup->addAction(polygonAct);
	drawActGroup->addAction(arcAct);
	drawActGroup->addAction(pieAct);
	drawActGroup->addAction(chordAct);
	drawActGroup->addAction(ellipseAct);
	drawActGroup->addAction(textAct);
    connect(drawActGroup, SIGNAL(triggered(QAction*)), this, SLOT(draw(QAction*)));
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));	
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(printAct);

    drawMenu = menuBar()->addMenu(tr("&Draw"));
    drawMenu->addAction(lineAct);
    drawMenu->addAction(polylineAct);
    drawMenu->addAction(rectangleAct);
    drawMenu->addAction(polygonAct);
    drawMenu->addAction(arcAct);
    drawMenu->addAction(pieAct);
    drawMenu->addAction(chordAct);
    drawMenu->addAction(ellipseAct);
    drawMenu->addAction(textAct);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("Print"));
    fileToolBar->addAction(printAct);

    drawToolBar = addToolBar(tr("Draw"));
    drawToolBar->addAction(lineAct);
    drawToolBar->addAction(polylineAct);
    drawToolBar->addAction(rectangleAct);
    drawToolBar->addAction(polygonAct);
    drawToolBar->addAction(arcAct);
    drawToolBar->addAction(pieAct);
    drawToolBar->addAction(chordAct);
    drawToolBar->addAction(ellipseAct);
	drawToolBar->addSeparator();
    drawToolBar->addAction(textAct);
	fontCmb = new QFontComboBox(drawToolBar);
	drawToolBar->addWidget(fontCmb);
	connect(fontCmb, SIGNAL(currentFontChanged(const QFont&)), form, SLOT( fontChanged(const QFont&)));
	fontCmb->setCurrentFont(font());
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDockWindows()
{
    QDockWidget *dock = new QDockWidget(tr("Palette"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    paletteWidget = new Palette(dock);
    dock->setWidget(paletteWidget);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

	connect(paletteWidget, SIGNAL(penChanged(QPen&)), form, SLOT(penChanged(QPen&)));
	connect(paletteWidget, SIGNAL(brushChanged(QBrush&)), form, SLOT(brushChanged(QBrush&)));
}

void MainWindow::print()
{
	QPrinter printer;

	QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle(tr("Print Graphics"));
    if (dialog->exec() != QDialog::Accepted)
         return; 
     QPainter painter;
     painter.begin(&printer);
     QPixmap pixmap=QPixmap::grabWidget(form);
     painter.drawPixmap(0,0,pixmap);
     painter.end();    
}
