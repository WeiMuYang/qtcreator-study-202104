#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "ui_mainwindow.h"
class QLabel;

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
	bool			isUntitled;	
	QString			curFile;
	enum{MaxRecentFiles = 9};
	QAction*		recentFileActs[MaxRecentFiles];
	QAction*		separatorAct;
	QAction* actPrint;
	
	void 		iniDockWidget();
	void 		iniStatusBar();
	void 		iniConnect();
	void 		setCurrentFile(const QString&);
	bool 		saveFile(const QString&);
	bool		loadFile(const QString&);
	void		maybeSave();
	void		updateRecentFiles();
private slots:
	void doCursorChanged();
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
	void doModified();
	void openRecentFile();
	void doPrint();
};
#endif

