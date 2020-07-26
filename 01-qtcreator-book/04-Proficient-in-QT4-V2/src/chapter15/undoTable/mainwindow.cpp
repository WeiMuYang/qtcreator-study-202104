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
    undoView->setWindowTitle(tr("�����б�"));
    undoView->show();
    undoView->setAttribute(Qt::WA_QuitOnClose, false);

	setCentralWidget(undoWidget);
	setWindowTitle(tr("�ɳ����༭��TableWidget"));
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
	actUndo = new QAction(QIcon(":/images/undo.png"), tr("����"), this);
	actUndo->setEnabled(false);
	actRedo = new QAction(QIcon(":/images/redo.png"), tr("����"), this);
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
	editToolbar = addToolBar(tr("�༭"));
	editToolbar->addAction(actUndo);
	editToolbar->addAction(actRedo);
}
