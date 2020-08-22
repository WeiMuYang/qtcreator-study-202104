#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&threadA,SIGNAL(started()),this,SLOT(onthreadA_started()));
    connect(&threadA,SIGNAL(finished()),this,SLOT(onthreadA_finished()));

    connect(&mTimer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{//窗口关闭时
    if (threadA.isRunning())
    {
        threadA.stopThread();
        threadA.wait();
    }
    event->accept();
}





void MainWindow::onthreadA_started()
{
    ui->LabA->setText("Thread状态：thread started");
}

void MainWindow::onthreadA_finished()
{
    ui->LabA->setText("Thread状态：thread finished");
}

void MainWindow::onTimeOut()
{ //定时器到时处理槽函数
    int tmpSeq=0,tmpValue=0;
    bool  valid=threadA.readValue(&tmpSeq,&tmpValue); //读取数值
    if (valid && (tmpSeq!=mSeq)) //有效，并且是新数据
    {
        mSeq=tmpSeq;
        mDiceValue=tmpValue;
        QString  str=QString::asprintf("第 %d 次掷骰子，点数为：%d",mSeq,mDiceValue);
        ui->plainTextEdit->appendPlainText(str);
        QPixmap pic;
        QString filename=QString::asprintf(":/dice/images/d%d.jpg",mDiceValue);
        pic.load(filename);
        ui->LabPic->setPixmap(pic);
    }
}

void MainWindow::on_btnClear_clicked()
{//清空文本
    ui->plainTextEdit->clear();
}

void MainWindow::on_btnDiceEnd_clicked()
{//暂停掷骰子
    threadA.diceEnd(); //
    mTimer.stop();//定时器暂停

    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

void MainWindow::on_btnDiceBegin_clicked()
{//开始掷骰子
    threadA.diceBegin();
    mTimer.start(100); //定时器100读取一次数据
    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(true);
}

void MainWindow::on_btnStopThread_clicked()
{//结束线程
    threadA.stopThread();//结束线程的run()函数执行
    threadA.wait();//

    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);

    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(false);
}

void MainWindow::on_btnStartThread_clicked()
{//启动线程
    mSeq=0;
    threadA.start();

    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);

    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}
