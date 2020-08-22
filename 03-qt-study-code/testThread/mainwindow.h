#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qdicethread.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    int mSeq,mDiceValue;

    QDiceThread   threadA;
    QTimer  mTimer;//定时器
protected:
    void    closeEvent(QCloseEvent *event);

private slots:
    void    onthreadA_started();
    void    onthreadA_finished();

    void    onTimeOut(); //定期器处理槽函数

    void on_btnClear_clicked();

    void on_btnDiceEnd_clicked();

    void on_btnDiceBegin_clicked();

    void on_btnStopThread_clicked();

    void on_btnStartThread_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
