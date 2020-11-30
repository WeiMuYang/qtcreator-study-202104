#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidget * right = new QListWidget();
    for ( int i=98; i<103; i++) {
        QListWidgetItem * item = new QListWidgetItem;
        item->setData(Qt::DisplayRole, i);
        right->addItem(item);
    }

    ui->listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr(":/icons/alarm-fill.svg")), QObject::tr("1-jkldsjf")));
    ui->listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr(":/icons/app-indicator.svg")), QObject::tr("2-adadsfadf")));
    ui->listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr(":/icons/arrow-down-left-square.svg")), QObject::tr("3-JLKJKLJK")));
    ui->listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr(":/icons/arrow-bar-left.svg")), QObject::tr("4-KL;EKJ")));
    ui->listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr(":/icons/arrows-angle-contract.svg")), QObject::tr("5-J;LDJF")));
    ui->listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr(":/icons/alt.svg")), QObject::tr("My Group1")));

    QListWidgetItem *newItem=new QListWidgetItem(QIcon(":/icons/arrow-90deg-left.svg"),"nnnnnnnnnnnnnnnnnnn");
    newItem->setSizeHint(QSize(this->width(),25));//设置宽度、高度
    ui->listWidget->addItem(newItem);
    newItem->setHidden(true);
    newItem->setBackground(QColor(252,240,0));



    QObject::connect(ui->listWidget, SIGNAL(currentTextChanged(QString)), this, SLOT(changeItem(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeItem(QString s)
{
    if(s == "My Group1"){
        ui->listWidget->findItems("nnnnnnnnnnnnnnnnnnn", Qt::MatchContains).at(0)->setHidden(false);
        // ui->listWidget->itemAt(0,6)->setHidden(false);

    }

}

