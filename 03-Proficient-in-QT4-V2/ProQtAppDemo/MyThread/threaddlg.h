#ifndef THREADDLG_H
#define THREADDLG_H

#include <QDialog>
#include "workthread.h"
#include <QDialogButtonBox>
#define MAXSIZE 5


class ThreadDlg : public QDialog
{
    Q_OBJECT
public:
    ThreadDlg(QWidget *parent = 0);
public slots:
    void start();
    void stop();
private:
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *stopButton;

    QDialogButtonBox *buttonBox;
    WorkThread* threadVector[MAXSIZE];



};

#endif // THREADDLG_H
