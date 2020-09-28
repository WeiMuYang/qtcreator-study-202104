#ifndef WIDGET_H
#define WIDGET_H

/**
* Copyright (c) 2020 MYWB. All rights reserved
* @projectName   qtdll
* @file          widget.h
* @brief         Widget的子类，用于展示界面
* @author        YWB
* @date          2020-09-28 21:15:16
*/

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected slots:
    void btnClicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
