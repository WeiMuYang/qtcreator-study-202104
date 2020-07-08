#include <QtGui>

#include "invertwidget.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
	resize(800,600);
	invertWidget = new InvertWidget(this);
	setCentralWidget(invertWidget);	
}

