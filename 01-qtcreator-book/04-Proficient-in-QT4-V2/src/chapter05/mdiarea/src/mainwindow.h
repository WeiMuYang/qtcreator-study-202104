#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "ui_mainwindow.h"
class QLabel;
class QWorkspace;
class QSignalMapper;
class CMDITextEdit;
class QMdiArea;

class CMainWindow :	public QMainWindow,
						public Ui::MainWindow
{
	Q_OBJECT
public:
	CMainWindow(QWidget* = 0);	
	
private:
	QDockWidget*	dockWidget;
	QLabel*			label1;
	QLabel*			label2;	
	enum{MaxRecentFiles = 9};
	QAction*		recentFileActs[MaxRecentFiles];
	QAction*		separatorAct;
 	QWorkspace*		workspace;
 	QSignalMapper*	mapper;
	QMdiArea*		mdiArea;
	
	void 		iniDockWidget();
	void 		iniStatusBar();
	void 		iniConnect();
	CMDITextEdit* activeWindow();
	CMDITextEdit* createMDITextEdit(bool, const QString&);
private slots:
	void doNew();
	void doOpen();
	void doClose();
	void doSave();
	void doASave();
	void doQuit();
	void doUndo();
	void doCut();
	void doCopy();
	void doPast();
	void doAll();
	void doFind();
	void openRecentFile();	
	void updateRecentFiles();
	void updateMenu();
	void showCount(int);
};
#endif
