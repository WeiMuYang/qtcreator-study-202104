#ifndef _FINDFILEFORM_H_
#define _FINDFILEFORM_H_

#include "ui_findfileform.h"

class CFindFileForm :	public QWidget
{
	Q_OBJECT
public:
	CFindFileForm(QWidget* = 0);

private:
	Ui_FindFileForm ui;

};
#endif
