#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class InvertWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    
private:
	InvertWidget *invertWidget;
};

#endif
