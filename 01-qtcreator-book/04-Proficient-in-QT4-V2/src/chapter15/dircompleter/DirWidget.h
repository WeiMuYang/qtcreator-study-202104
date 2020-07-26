#ifndef DIRWIDGET_H_
#define DIRWIDGET_H_

#include <QtGui>

class DirWidget : public QWidget
{
	Q_OBJECT
	
public:
	DirWidget();
	virtual ~DirWidget();
	
private slots:
	void pathChanged();

private:
	QModelIndex index;
	QVBoxLayout *layout;
    QDirModel *model;
    QTreeView *tree;
    QLineEdit *dirEdit;
    QCompleter *completer;
};

#endif /*DIRWIDGET_H_*/
