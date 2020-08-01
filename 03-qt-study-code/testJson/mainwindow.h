#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QJsonObject>
#include <QJsonDocument>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QJsonObject m_JsonData;
    QJsonObject m_CS;
    QJsonObject m_CCS;
    void CreateJson();
    QJsonDocument m_document;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
