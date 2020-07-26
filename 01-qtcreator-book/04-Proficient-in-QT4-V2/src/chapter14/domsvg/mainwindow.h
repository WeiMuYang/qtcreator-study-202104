#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

class DrawWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void open();
    void saveAs();
    void about();

private:
    void createActions();
    void createMenus();

    DrawWidget *drawWidget;

    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *openAct;
    QAction *saveAsAct;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
};

#endif
