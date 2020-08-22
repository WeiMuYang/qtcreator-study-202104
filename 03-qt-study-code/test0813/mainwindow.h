#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "welldata.h"
#include "threadwell.h"


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
    Ui::MainWindow *ui;

     QVector <WellData > m_Wells;
public:
     ThreadWell  m_threadwell;
};

#endif // MAINWINDOW_H
