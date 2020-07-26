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

private:
    QGraphicsScene *scene;
    RadarView *view;
    
    void createActions();
    void createMenus();
    void createToolbars();
};

#endif
