#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <hled.h>


int g_dscale = 1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    HLed led;
    led.turnOn();
    led.paintEvent(NULL);


}

MainWindow::~MainWindow()
{
    delete ui;
}
