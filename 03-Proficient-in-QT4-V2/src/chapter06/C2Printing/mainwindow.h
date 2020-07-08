#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

class RadarView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   MainWindow();

private slots:
	void print();

private:
    QGraphicsScene *scene;
    RadarView *view;
    QMenu *fileMenu;
    QToolBar *fileToolBar;
    QAction *printAct;
    
    void createActions();
    void createMenus();
    void createToolbars();
};

#endif
