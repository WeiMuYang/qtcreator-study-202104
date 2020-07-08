#ifndef WEAPONMODEL_H
#define WEAPONMODEL_H

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QVariant>

class WeaponModel : public QAbstractTableModel
{
public:
	WeaponModel(QObject *parent = 0);
	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
	virtual int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	
private:
	QVector<short> army;
	QVector<short> weapon;
	QStringList type;
	QMap<short, QString> armyMap;
	QMap<short, QString> weaponMap;
	QStringList header;
	
	void populateModel();
};

#endif
