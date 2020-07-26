#include <QtGui>
#include "layoutdlg.h"

CLayoutDlg::CLayoutDlg(QWidget* parent)
 :	QDialog(parent)
{
	setupUi(this);
	
	init();
}
void CLayoutDlg::init()
{
	showPushBtn->setCheckable(true);
	showPushBtn->setChecked(true);
	groupBox->setVisible(showPushBtn->isChecked());
	connect(showPushBtn, SIGNAL(toggled(bool)), this, SLOT(doPushBtnShow(bool)));
	
	QMenu*	constraintMenu	= new QMenu(constraintPushBtn);
	actDefaultConstraint	=
	constraintMenu->addAction(tr("QLayout::SetDefaultConstraint"));
	actFixedSize	= constraintMenu->addAction(tr("QLayout::SetFixedSize"));
	actMinimumSize	= constraintMenu->addAction(tr("QLayout::SetMinimumSize"));
	actMaximumSize	=
	constraintMenu->addAction(tr("QLayout::SetMaximumSize"));
	actMinAndMaxSize	=
	constraintMenu->addAction(tr("QLayout::SetMinAndMaxSize"));
	actNoConstraint	= constraintMenu->addAction(tr("QLayout::SetNoConstraint"));
	connect(actDefaultConstraint, SIGNAL(triggered()), this, SLOT(doActConstraint()));
	connect(actFixedSize, SIGNAL(triggered()), this, SLOT(doActConstraint()));
	connect(actMinimumSize, SIGNAL(triggered()), this, SLOT(doActConstraint()));
	connect(actMaximumSize, SIGNAL(triggered()), this, SLOT(doActConstraint()));
	connect(actMinAndMaxSize, SIGNAL(triggered()), this, SLOT(doActConstraint()));
	connect(actNoConstraint, SIGNAL(triggered()), this, SLOT(doActConstraint()));
	constraintPushBtn->setMenu(constraintMenu);
	
	QMenu*	lpolicyMenu	= new QMenu(lpolicyPushBtn);
	actLFixed	= lpolicyMenu->addAction(tr("QSizePolicy::Fixed"));
	actLMinimum	= lpolicyMenu->addAction(tr("QSizePolicy::Minimum"));	
	actLMaximum	= lpolicyMenu->addAction(tr("QSizePolicy::Maximum"));
	actLPreferred= lpolicyMenu->addAction(tr("QSizePolicy::Preferred"));
	actLExpanding= lpolicyMenu->addAction(tr("QSizePolicy::Expanding"));
	actLMinimumExpanding =
		lpolicyMenu->addAction(tr("QSizePolicy::MinmumExpanding"));
	actLIgnored	= lpolicyMenu->addAction(tr("QSizePolicy::Ignored"));
	connect(actLFixed, SIGNAL(triggered()), this, SLOT(doActLPolicy()));
	connect(actLMinimum, SIGNAL(triggered()), this, SLOT(doActLPolicy()));
	connect(actLMaximum, SIGNAL(triggered()), this, SLOT(doActLPolicy()));
	connect(actLPreferred, SIGNAL(triggered()), this, SLOT(doActLPolicy()));
	connect(actLExpanding, SIGNAL(triggered()), this, SLOT(doActLPolicy()));
	connect(actLMinimumExpanding, SIGNAL(triggered()), this, SLOT(doActLPolicy()));
	connect(actLIgnored, SIGNAL(triggered()), this, SLOT(doActLPolicy()));
	lpolicyPushBtn->setMenu(lpolicyMenu);	
	
	QMenu*	rpolicyMenu	= new QMenu(rpolicyPushBtn);
	actRFixed			= rpolicyMenu->addAction(tr("QSizePolicy::Fixed"));
	actRMinimum		= rpolicyMenu->addAction(tr("QSizePolicy::Minimum"));	
	actRMaximum		= rpolicyMenu->addAction(tr("QSizePolicy::Maximum"));
	actRPreferred		= rpolicyMenu->addAction(tr("QSizePolicy::Preferred"));
	actRExpanding		= rpolicyMenu->addAction(tr("QSizePolicy::Expanding"));
	actRMinimumExpanding =
	lpolicyMenu->addAction(tr("QSizePolicy::MinmumExpanding"));
	actRIgnored			= rpolicyMenu->addAction(tr("QSizePolicy::Ignored"));
	connect(actRFixed, SIGNAL(triggered()), this, SLOT(doActRPolicy()));
	connect(actRMinimum, SIGNAL(triggered()), this, SLOT(doActRPolicy()));
	connect(actRMaximum, SIGNAL(triggered()), this, SLOT(doActRPolicy()));
	connect(actRPreferred, SIGNAL(triggered()), this, SLOT(doActRPolicy()));
	connect(actRExpanding, SIGNAL(triggered()), this, SLOT(doActRPolicy()));
	connect(actRMinimumExpanding, SIGNAL(triggered()), this, SLOT(doActRPolicy()));
	connect(actRIgnored, SIGNAL(triggered()), this, SLOT(doActRPolicy()));
	rpolicyPushBtn->setMenu(rpolicyMenu);	
	
	QMenu*	lstretchMenu= new QMenu(lstretchPushBtn);
	actLStretch0		= lstretchMenu->addAction(tr("ÉìËõ±ÈÀý 0"));
	actLStretch1		= lstretchMenu->addAction(tr("ÉìËõ±ÈÀý 1"));	
	actLStretch2		= lstretchMenu->addAction(tr("ÉìËõ±ÈÀý 2"));
	actLStretch4		= lstretchMenu->addAction(tr("ÉìËõ±ÈÀý 4"));
	connect(actLStretch0, SIGNAL(triggered()), this, SLOT(doActLStretch()));
	connect(actLStretch1, SIGNAL(triggered()), this, SLOT(doActLStretch()));
	connect(actLStretch2, SIGNAL(triggered()), this, SLOT(doActLStretch()));
	connect(actLStretch4, SIGNAL(triggered()), this, SLOT(doActLStretch()));
	lstretchPushBtn->setMenu(lstretchMenu);
	
	QMenu*	rstretchMenu= new QMenu(rstretchPushBtn);
	actRStretch0		= rstretchMenu->addAction(tr("ÉìËõ±ÈÀý 0"));
	actRStretch1		= rstretchMenu->addAction(tr("ÉìËõ±ÈÀý 1"));	
	actRStretch2		= rstretchMenu->addAction(tr("ÉìËõ±ÈÀý 2"));
	actRStretch4		= rstretchMenu->addAction(tr("ÉìËõ±ÈÀý 4"));
	connect(actRStretch0, SIGNAL(triggered()), this, SLOT(doActRStretch()));
	connect(actRStretch1, SIGNAL(triggered()), this, SLOT(doActRStretch()));
	connect(actRStretch2, SIGNAL(triggered()), this, SLOT(doActRStretch()));
	connect(actRStretch4, SIGNAL(triggered()), this, SLOT(doActRStretch()));
	rstretchPushBtn->setMenu(rstretchMenu);
	
	groupBox->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

void CLayoutDlg::doActConstraint()
{
	QAction* act = qobject_cast<QAction*>(sender());
	if(act == actDefaultConstraint)
		layout()->setSizeConstraint(QLayout::SetDefaultConstraint);
	else if(act == actFixedSize)
		layout()->setSizeConstraint(QLayout::SetFixedSize);
	else if(act == actMinimumSize)
		layout()->setSizeConstraint(QLayout::SetMinimumSize);
	else if(act == actMaximumSize)
		layout()->setSizeConstraint(QLayout::SetMaximumSize);
	else if(act == actNoConstraint)
		layout()->setSizeConstraint(QLayout::SetNoConstraint);
	constraintPushBtn->setText(act->text());
}

void CLayoutDlg::doActLPolicy()
{
	QAction* act = qobject_cast<QAction*>(sender());
	QSizePolicy policy = lTextEdit->sizePolicy();
	if(act == actLFixed)		
		policy.setHorizontalPolicy(QSizePolicy::Fixed);
	else if(act == actLMinimum)
		policy.setHorizontalPolicy(QSizePolicy::Minimum);
	else if(act == actLMaximum)
		policy.setHorizontalPolicy(QSizePolicy::Maximum);
	else if(act == actLPreferred)
		policy.setHorizontalPolicy(QSizePolicy::Preferred);
	else if(act == actLExpanding)
		policy.setHorizontalPolicy(QSizePolicy::Expanding);
	else if(act == actLMinimumExpanding)
		policy.setHorizontalPolicy(QSizePolicy::MinimumExpanding);
	else if(act == actLIgnored)
		policy.setHorizontalPolicy(QSizePolicy::Ignored);	
	lTextEdit->setSizePolicy(policy);
	lpolicyPushBtn->setText(act->text());
}
void CLayoutDlg::doActRPolicy()
{
	QAction* act = qobject_cast<QAction*>(sender());
	QSizePolicy policy = rTextEdit->sizePolicy();
	if(act == actRFixed)		
		policy.setHorizontalPolicy(QSizePolicy::Fixed);
	else if(act == actRMinimum)
		policy.setHorizontalPolicy(QSizePolicy::Minimum);
	else if(act == actRMaximum)
		policy.setHorizontalPolicy(QSizePolicy::Maximum);
	else if(act == actRPreferred)
		policy.setHorizontalPolicy(QSizePolicy::Preferred);
	else if(act == actRExpanding)
		policy.setHorizontalPolicy(QSizePolicy::Expanding);
	else if(act == actRMinimumExpanding)
		policy.setHorizontalPolicy(QSizePolicy::MinimumExpanding);
	else if(act == actRIgnored)
		policy.setHorizontalPolicy(QSizePolicy::Ignored);	
	rTextEdit->setSizePolicy(policy);
	rpolicyPushBtn->setText(act->text());
}
void CLayoutDlg::doActLStretch()
{
	QAction* act = qobject_cast<QAction*>(sender());
	QSizePolicy policy = rTextEdit->sizePolicy();
	if(act == actLStretch0)
		policy.setHorizontalStretch(0);
	else if(act == actLStretch1)
		policy.setHorizontalStretch(1);
	else if(act == actLStretch2)
		policy.setHorizontalStretch(2);
	else if(act == actLStretch4)
		policy.setHorizontalStretch(4);
	lTextEdit->setSizePolicy(policy);
	lstretchPushBtn->setText(act->text());
}
void CLayoutDlg::doActRStretch()
{
	QAction* act = qobject_cast<QAction*>(sender());
	QSizePolicy policy = rTextEdit->sizePolicy();
	if(act == actRStretch0)
		policy.setHorizontalStretch(0);
	else if(act == actRStretch1)
		policy.setHorizontalStretch(1);
	else if(act == actRStretch2)
		policy.setHorizontalStretch(2);
	else if(act == actRStretch4)
		policy.setHorizontalStretch(4);
	rTextEdit->setSizePolicy(policy);
	rstretchPushBtn->setText(act->text());
}

QSize CLayoutDlg::minimumSizeHint() const
{
	qDebug() << "xxxxxxxxxx";
	return QSize(1000, 400);
}

void CLayoutDlg::doPushBtnShow(bool checked)
{
//	resize(500, 400);
	hide();
	show();
	groupBox->setVisible(checked);
}	

