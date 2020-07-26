#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>
#include "undowidget.h"

class MainWindow : public QMainWindow
{
public:
	MainWindow(QWidget * parent = 0, Qt::WindowFlags flags = 0);
	virtual ~MainWindow();
	
private:
	UndoWidget *undoWidget;
	QAction *actUndo;
	QAction *actRedo;
	QToolBar *editToolbar;
	QUndoView *undoView;
	
	void createActions();
	void createToolbars();
};

#endif /*MAINWINDOW_H_*/
