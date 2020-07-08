#ifndef MYSTYLE_H
#define MYSTYLE_H

#include <QWindowsStyle>

class MyStyle : public QWindowsStyle
{
    Q_OBJECT

public:
    MyStyle() {};

    void polish(QPalette &palette);
};

#endif
