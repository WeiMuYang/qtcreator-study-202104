#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ArrowWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    
private:
	ArrowWidget *arrowWidget;
};

#endif
