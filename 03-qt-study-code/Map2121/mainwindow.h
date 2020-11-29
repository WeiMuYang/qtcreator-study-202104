#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "myitem.h"
#include <QPainter>
#include <QGraphicsView>
#include <QGridLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    QGridLayout *grid;
    QGraphicsScene *scene;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
