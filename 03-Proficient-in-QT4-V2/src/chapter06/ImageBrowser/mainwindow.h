#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QDir>
#include <QClipboard>

#include "imagewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
	void selectDir();
	void next();
	void prev();
	void rotateLeft();
    void rotateRight();
    void zoomIn();
    void zoomOut();
    void actualSize();
    void fitSize();
	void copy();
    void print();
    void present();

protected:
	void resizeEvent(QResizeEvent * event);

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();

	QScrollArea *scrollArea;
    ImageWidget *imageWidget;

    QMenu *naviMenu;
    QMenu *operMenu;
    
    QToolBar *naviToolBar;
    QToolBar *operToolBar;
    
    QAction *dirAct;
    QAction *nextAct;
    QAction *prevAct;
    QAction *leftAct;
    QAction *rightAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *actualSizeAct;
    QAction *fitSizeAct;
	QAction *copyAct;
    QAction *printAct;
    QAction *presentAct;

	QStringList imageList;
	int index;
	QDir imageDir;
	QClipboard *clipboard;
};

#endif
