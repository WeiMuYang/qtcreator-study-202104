#ifndef USESERIAL_H
#define USESERIAL_H

#include <QObject>

class UseSerial : public QObject
{
    Q_OBJECT
public:
    explicit UseSerial(QObject *parent = 0);

signals:

public slots:
};

#endif // USESERIAL_H