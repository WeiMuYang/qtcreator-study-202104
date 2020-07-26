
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>

class DrawArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
protected:
    void closeEvent(QCloseEvent* event);
    void showEvent(QShowEvent* event);
    void hideEvent(QHideEvent* event);
    void timerEvent(QTimerEvent* event);
private:
    bool maybeSave();
    DrawArea *scribbleArea;
    int timeId;

};

#endif
