#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

class TestWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    
protected slots:
	void setMode(QAction *action);
	
private:
	TestWidget *testWidget;
	QActionGroup* testGroup;
    QAction* penStyleAct;
    QAction* penCapStyleAct;
    QAction* penJoinStyleAct;
    QAction* brushStyleAct;
    QAction* gradientAct;
    QToolBar* testToolBar;
	
	void createActions();
	void createToolBars();
};

#endif
