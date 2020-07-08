// chapter2/builtin/src/builtindlg.h.
#ifndef _BUILTINDLG_H_
#define _BUILTINDLG_H_
#include <QtGui/QDialog>
class QTextEdit;
class QPushButton;
class CBuiltinDlg : public QDialog
{
 	Q_OBJECT
public:
	CBuiltinDlg(QWidget* = 0);
	virtual ~CBuiltinDlg() { }	
private:
	QTextEdit*	displayTextEdit;
	QPushButton*	colorPushBtn;
	QPushButton*	errorPushBtn;
	QPushButton*	filePushBtn;
	QPushButton*	fontPushBtn;
	QPushButton*	inputPushBtn;
	QPushButton*	pagePushBtn;
	QPushButton*	progressPushBtn;
	QPushButton*	printPushBtn;	
private slots:
	void doPushBtn();
};
#endif
