#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "processjson.h"
#include <QUdpSocket>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent *event);

    void SendUDPString(int i);

private:
    Ui::MainWindow *ui;

    QUdpSocket *m_UDPSocketSending;
    ProcessJson *m_JsonProcess;
};

#endif // MAINWINDOW_H
