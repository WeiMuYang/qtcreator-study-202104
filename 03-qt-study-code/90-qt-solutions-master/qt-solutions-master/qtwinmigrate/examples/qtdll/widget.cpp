#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Test Dll for Viual Studio");

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::btnClicked()
{
    ui->label->setText(ui->lineEdit->text());
}
