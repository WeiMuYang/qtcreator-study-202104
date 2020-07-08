#include <QtGui>

#include "weaponmodel.h"

WeaponModel::WeaponModel(QObject *parent)
	: QAbstractTableModel(parent)
{
	armyMap[1] = tr("�վ�");
	armyMap[2] = tr("����");
	armyMap[3] = tr("½��");
	armyMap[4] = tr("����½ս��");
	
	weaponMap[1] = tr("��ը��");
	weaponMap[2] = tr("ս����");
	weaponMap[3] = tr("����ĸ��");
	weaponMap[4] = tr("����");
	weaponMap[5] = tr("ֱ����");
	weaponMap[6] = tr("̹��");
	weaponMap[7] = tr("���ܹ�����");
	weaponMap[8] = tr("����ս��");
	
	populateModel();
}

void WeaponModel::populateModel()
{
	header << tr("����") << tr("����") << tr("����");
	army << 1 << 2 << 3 << 4 << 2 << 4 << 3 << 1;
	weapon << 1 << 3 << 5 << 7 << 4 << 8 << 6 << 2;
	type << tr("B-2") << tr("�����ȼ�") << tr("������") << tr("�Ʒ伶") 
		<< tr("�������˼�") << tr("AAAV") << tr("M1A1") << tr("F-22") ;
}

int WeaponModel::columnCount(const QModelIndex& parent) const
{
	return 3;
}

int WeaponModel::rowCount(const QModelIndex& parent) const
{
	return army.size();
}

QVariant WeaponModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();
	qDebug() << index;
	if(role == Qt::DisplayRole)
	{
		switch(index.column())
		{
		case 0:
			return armyMap[army[index.row()]];
			break;
		case 1:
			return weaponMap[weapon[index.row()]];
			break;
		case 2:
			return type[index.row()];
		default:
			return QVariant();			
		}
	}
	return QVariant();
}

QVariant WeaponModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
		return header[section];
	return QAbstractTableModel::headerData(section, orientation, role);
}

