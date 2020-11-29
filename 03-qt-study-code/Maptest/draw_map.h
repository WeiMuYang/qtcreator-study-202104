#ifndef DRAWMAP_H
#define DRAWMAP_H

#include <QObject>

class DrawMap : public QObject
{
    Q_OBJECT
public:
    explicit DrawMap(QObject *parent = 0);

signals:

public slots:
};

#endif // DRAWMAP_H