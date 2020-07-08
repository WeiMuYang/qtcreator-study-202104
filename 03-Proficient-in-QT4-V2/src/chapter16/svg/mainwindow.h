#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

#include "svgwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void openFile(const QString &path = QString());

private:
    QString currentPath;
    SvgWindow *area;
};

#endif
