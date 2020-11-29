#ifndef FILEFILTER_H
#define FILEFILTER_H

#include <QObject>

class FileFilter : public QObject
{
    Q_OBJECT
public:
    explicit FileFilter(QObject *parent = nullptr);

signals:

};

#endif // FILEFILTER_H
