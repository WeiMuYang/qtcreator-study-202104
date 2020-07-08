#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
	TableModel(QObject* parent = 0);
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::DropActions supportedDropActions() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QStringList mimeTypes() const;
    QMimeData* mimeData(const QModelIndexList &indexes) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, 
    		int row, int column, const QModelIndex &parent);
    
private:
	void populateTable();
	QStringList nameList;
	QStringList emperorList;
	QStringList dynastyList;
	QStringList yearList;
};

#endif
