#ifndef _LAYOUTDLG_H_
#define _LAYOUTDLG_H_

#include "ui_layoutdlg.h"
class CLayoutDlg :	public QDialog,
					public Ui_LayoutDlg
{
	Q_OBJECT
public:
	CLayoutDlg(QWidget* = 0);
	virtual QSize minimumSizeHint() const;	
private:
	void	init();
	
	QAction*	actDefaultConstraint;
	QAction*	actFixedSize;
	QAction*	actMinimumSize;
	QAction*	actMaximumSize;
	QAction*	actMinAndMaxSize;
	QAction*	actNoConstraint;
	QAction*	actLFixed;
	QAction*	actLMinimum;
	QAction*	actLMaximum;
	QAction*	actLPreferred;
	QAction*	actLExpanding;
	QAction*	actLMinimumExpanding;
	QAction*	actLIgnored;
	QAction*	actLStretch0;
	QAction*	actLStretch1;
	QAction*	actLStretch2;
	QAction*	actLStretch4;
	QAction*	actRFixed;
	QAction*	actRMinimum;
	QAction*	actRMaximum;
	QAction*	actRPreferred;
	QAction*	actRExpanding;
	QAction*	actRMinimumExpanding;
	QAction*	actRIgnored;
	QAction*	actRStretch0;
	QAction*	actRStretch1;
	QAction*	actRStretch2;
	QAction*	actRStretch4;	
private slots:
	void doActConstraint();
	void doActLPolicy();
	void doActRPolicy();
	void doActLStretch();
	void doActRStretch();
	void doPushBtnShow(bool);
};
#endif
