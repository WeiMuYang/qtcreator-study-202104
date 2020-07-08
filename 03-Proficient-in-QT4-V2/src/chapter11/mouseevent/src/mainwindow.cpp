

#include <QtGui>
#include "mainwindow.h"
#include "drawarea.h"

MainWindow::MainWindow()
{
    scribbleArea = new DrawArea;
    setCentralWidget(scribbleArea);
    setWindowTitle(tr("鼠标与定时器事件"));
    resize(480, 320);
		timeId = 0;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

bool MainWindow::maybeSave()
{
    if (scribbleArea->isModified()) 
			return true;
		else
			return false;
}

void MainWindow::showEvent(QShowEvent* event)
{
	timeId = startTimer(10000);
}
void MainWindow::hideEvent(QHideEvent* event)
{
	killTimer(timeId);
}

void MainWindow::timerEvent(QTimerEvent* event)
{
	if(event->timerId() == timeId)
		scribbleArea->clearImage();
}


