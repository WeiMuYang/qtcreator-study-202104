#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_d->m_pLabelVector.append(ui->label_1);

    m_d->m_pLabelVector.append(ui->label_2);

    m_thread->m_d =




}

MainWindow::~MainWindow()
{
    delete ui;
}
