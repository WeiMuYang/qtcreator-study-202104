#include <QtGui>

#include "tablemodel.h"

TableModel::TableModel(QObject* parent)
	: QAbstractTableModel(parent)
{
	populateTable();
}

void TableModel::populateTable()
{
	nameList << tr("ÖìÔªè°") << tr("ÖìÔÊžÉ") << tr("Öìé¦");
	emperorList << tr("Ã÷Ì«×æ") << tr("»ÝµÛ") << tr("³É×æ");
	dynastyList << tr("ºéÎä") << tr("½¨ÎÄ") << tr("ÓÀÀÖ");
	yearList << tr("1368") << tr("1399") << tr("1403");
}

int TableModel::rowCount(const QModelIndex & parent) const
{
	return nameList.size();
}

int TableModel::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant TableModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

	switch(index.column())
	{
	case 0:
		return nameList[index.row()];
	case 1:
		return emperorList[index.row()];
	case 2:
		return dynastyList[index.row()];
	case 3:
		return yearList[index.row()];
	}
	return QVariant();
}

Qt::DropActions TableModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
} 

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags defaultFlags = QAbstractTableModel::flags(index);

    if (index.isValid())
        return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | defaultFlags;
    else
        return Qt::ItemIsDropEnabled | defaultFlags;
}

QStringList TableModel::mimeTypes() const
{
    QStringList types;
    types << "text/plain";
    return types;
} 

QMimeData *TableModel::mimeData(const QModelIndexList &indexes) const
{
    QMimeData *mimeData = new QMimeData();

    QModelIndex idx = indexes[0];
    if (idx.isValid()) {
        QString text = data(idx, Qt::DisplayRole).toString();
        mimeData->setText(text);
    }

    return mimeData;
} 

bool TableModel::dropMimeData(const QMimeData *data,
     Qt::DropAction action, int row, int column, const QModelIndex &parent)
{	
    if (action == Qt::IgnoreAction)
        return true;

    if (!data->hasFormat("text/plain"))
        return false;

    if (parent.isValid())
    	setData(parent, data->text());
    else
    	return false;

    return true;
}
     
bool TableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	int row = index.row();
	if(row > rowCount())
	{
		return false;
	}
	switch(index.column())
	{
	case 0:
		nameList[row] = value.toString();
		break;
	case 1:
		emperorList[row] = value.toString();
		break;
	case 2:
		dynastyList[row] = value.toString();
		break;		
	case 3:
		yearList[row] = value.toString();
		break;
	}
	return true;
}

