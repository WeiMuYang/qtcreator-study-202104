#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QMainWindow>
class QTextEdit;

class CMainWindow :	public QMainWindow
{
	Q_OBJECT
public:
	CMainWindow(QWidget* = 0);	
private:
	QMenu*		menu_F;
	QMenu*		menu_E;
	QMenu*		menu_T;
	QToolBar*	fileToolBar;
	QToolBar*	editToolBar;
	QAction*	actNew;
	QAction*	actOpen;
	QAction*	actClose;
	QAction*	actSave;
	QAction*	actASave;
	QAction*	actQuit;
	QAction*	actUndo;
	QAction*	actCut;
	QAction*	actCopy;
	QAction*	actPast;
	QAction*	actAll;
	QAction*	actFind;
	QTextEdit*	textEdit;
	
	void 		iniMenu();
	void 		iniToolBar();
	void 		iniCentralWidget();
};
#endif
