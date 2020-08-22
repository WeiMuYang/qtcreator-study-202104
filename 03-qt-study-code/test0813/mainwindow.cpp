
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    WellData temp;

    temp.well.append(ui->label_1);
    m_Wells.append(temp);
    temp.well.clear();


    temp.well.append(ui->label_2);
    m_Wells.append(temp);
    temp.well.clear();

    temp.well.append(ui->label_3);
    m_Wells.append(temp);
    temp.well.clear();


    temp.well.append(ui->label_4);
    m_Wells.append(temp);
    temp.well.clear();


    m_threadwell.SetPdata(&(m_Wells[0]));




}

MainWindow::~MainWindow()
{
    delete ui;
}








