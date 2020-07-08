#ifndef RTFEDIT_H_
#define RTFEDIT_H_

#include <QtGui>
#include <QtScript>

class RTFEdit : public QTextEdit
{
	Q_OBJECT
	
public:
	RTFEdit(QWidget *parent = 0);
	Q_INVOKABLE void insertTable(int row, int col);
	Q_INVOKABLE void moveCursor(int operation, int mode);
};

#endif /*RTFEDIT_H_*/
