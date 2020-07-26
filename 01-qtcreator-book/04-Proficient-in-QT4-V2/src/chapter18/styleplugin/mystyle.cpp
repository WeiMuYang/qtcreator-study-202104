#include <QtGui>

#include "mystyle.h"

void MyStyle::polish(QPalette &palette)
{
    palette.setBrush(QPalette::Base, Qt::black);
    palette.setBrush(QPalette::Text, Qt::white);
}
