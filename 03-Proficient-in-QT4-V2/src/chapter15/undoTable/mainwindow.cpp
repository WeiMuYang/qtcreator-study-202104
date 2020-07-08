#include <QtGui>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	undoWidget = new UndoWidget(this);
	resize(640,480);
	createActions();
	createToolbars();

	undoView = new QUndoView(undoWidget->undoStack);
    undoView->setWindowTitle(tr("命令列表"));
    undoView->show();
    undoView->setAttribute(Qt::WA_QuitOnClose, false);

	setCentralWidget(undoWidget);
	setWindowTitle(tr("可撤消编辑的TableWidget"));
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
	actUndo = new QAction(QIcon(":/images/undo.png"), tr("撤消"), this);
	actUndo->setEnabled(false);
	actRedo = new QAction(QIcon(":/images/redo.png"), tr("重做"), this);
	actRedo->setEnabled(false);
	connect(actUndo, SIGNAL(triggered()), undoWidget, SLOT(undo()));
	connect(actRedo, SIGNAL(triggered()), undoWidget, SLOT(redo()));
    connect(undoWidget->undoStack, SIGNAL(canRedoChanged(bool)),
    		actRedo, SLOT(setEnabled(bool)));
    connect(undoWidget->undoStack, SIGNAL(canUndoChanged(bool)),
    		actUndo, SLOT(setEnabled(bool)));

}

void MainWindow::createToolbars()
{
	editToolbar = addToolBar(tr("编辑"));
	editToolbar->addAction(actUndo);
	editToolbar->addAction(actRedo);
}
