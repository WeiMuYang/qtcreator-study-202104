#include <QtGui>

#include "mapdelegate.h"


MapDelegate::MapDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

void MapDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex& index) const
{
	if(index.column() == 0)	// company
	{
        QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
        if (comboEditor) {
			int i = comboEditor->findText(index.model()->data(index, Qt::EditRole).toString());
			comboEditor->setCurrentIndex(i);
        }		
	}
	else
		return QItemDelegate::setEditorData(editor, index);
}

void MapDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex& index) const
{
	if(index.column() == 0)
	{
		QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
		if(comboBox)
		{
			model->setData(index, comboBox->currentText());
		}
	}
	else
		return QItemDelegate::setModelData(editor, model, index);
}
