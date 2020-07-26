#ifndef _LOGINDLG_H_
#define _LOGINDLG_H_

#include <QtGui/QDialog>
class QLineEdit;
class CLoginDlg : public QDialog
{
 	Q_OBJECT
public:
	CLoginDlg(QWidget* = 0);
	virtual ~CLoginDlg();
public slots:	
	virtual void accept();		
private:
	QLineEdit*	usrLineEdit;
	QLineEdit*	pwdLineEdit;
};
#endif
