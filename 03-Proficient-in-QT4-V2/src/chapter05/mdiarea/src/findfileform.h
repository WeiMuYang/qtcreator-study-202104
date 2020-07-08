// findfileform.h
#ifndef _FINDFILEFORM_H_
#define _FINDFILEFORM_H_

#include <QStringList>
#include <QDir>
#include "ui_findfileform.h"

class CFindFileForm :	public QWidget,
						public Ui_FindFileForm
{
	Q_OBJECT
public:
	CFindFileForm(QWidget* = 0);
	
private:
	QStringList findFiles(const QDir&, const QString&, const QString&);
     void 	showFiles(const QDir&, const QStringList&);
	 void 	tranvFolder(const QDir&, const QString& , const QString );
	 bool 	m_bStoped;
	 bool	m_bSubfolder;
	 bool	m_bSensitive;
	 int	m_nCount;
	 
private slots:
     void 	browse();
     void 	find();
	 void 	stop();
	 void	doTxtChange(const QString&);
};
#endif

