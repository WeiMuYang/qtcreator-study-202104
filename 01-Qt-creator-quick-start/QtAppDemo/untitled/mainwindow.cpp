#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollArea>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);





    //给父窗体填充颜色
       QPalette palette = ui->widget_2->palette();
       palette.setBrush(QPalette::Window,QBrush(QColor(255,255,255)));
       ui->widget_2->setAutoFillBackground(true);
       ui->widget_2->setPalette(palette);

       QScrollArea *m_pScroll = new QScrollArea(ui->centralWidget);
       m_pScroll->setWidget(ui->widget_2);//给widget_2设置滚动条
       ui->widget_2->setMinimumSize(1500,1000);//这里注意，要比主窗体的尺寸要大，不然太小的话会留下一片空白

       QHBoxLayout *pLayout = new QHBoxLayout;
       pLayout->addWidget(m_pScroll);
       pLayout->setMargin(0);
       pLayout->setSpacing(0);
       ui->centralWidget->setLayout(pLayout);


}

MainWindow::~MainWindow()
{
    delete ui;
}
