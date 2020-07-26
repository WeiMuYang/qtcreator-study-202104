#ifndef MAPDELEGATE_H
#define MAPDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>

class MapDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    MapDelegate(QObject *parent = 0);

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
};

#endif
