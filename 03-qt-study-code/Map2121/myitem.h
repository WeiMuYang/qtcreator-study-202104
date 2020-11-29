#ifndef MYITEM_H
#define MYITEM_H

#include <QObject>

class MyItem : public QObject
{
    Q_OBJECT
public:
    explicit MyItem(QObject *parent = 0);

signals:

public slots:
};

#endif // MYITEM_H