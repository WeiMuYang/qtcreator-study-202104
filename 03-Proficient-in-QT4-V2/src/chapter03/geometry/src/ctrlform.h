#ifndef _CTRLFORM_H_
#define _CTRLFORM_H_

#include <QWidget>
#include "ui_ctrlform.h"

class QPushButton;

class CCtrlForm :	public QWidget,
					public Ui_CtrlForm
{

	Q_OBJECT
public:	
	CCtrlForm(QWidget* = 0);

private:
	QPushButton* 	btn;
	QWidget* 		m_pWidget;
	QPoint			m_Pos;
	QSize			m_Sz;
	
private slots:
	void doClicked();
	void doSpinBoxChanged(int);

};

#endif