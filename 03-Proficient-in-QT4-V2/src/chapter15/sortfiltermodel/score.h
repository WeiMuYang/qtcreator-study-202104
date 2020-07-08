#ifndef SCORE_H_
#define SCORE_H_

#include <QWidget>
#include <QStandardItemModel>
#include "ui_score.h"

class MySortFilterProxyModel;

class Score : public QWidget, private Ui_score
{
	Q_OBJECT
	
public:
	Score(QWidget * parent = 0, Qt::WindowFlags f = 0);
	virtual ~Score();
	
protected slots:
	void setFilter();
	
protected:
	void populateTable();
	
	MySortFilterProxyModel *proxyModel;
	QStandardItemModel *model;
};

#endif /*SCORE_H_*/
