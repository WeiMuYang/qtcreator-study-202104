// findfileform.cpp �ļ�.
#include <QtGui>
#include "findfileform.h"

CFindFileForm::CFindFileForm(QWidget* parent)
 :	QWidget(parent)
 {
 	ui.setupUi(this);	
	ui.statusLabel->setText(tr("����"));	
	ui.resultLabel->setText(tr("�ҵ�0���ļ�"));
	ui.nameComboBox->setEditText("*");
	ui.dirComboBox->setEditText(QDir::currentPath());
	ui.dirComboBox->addItem(QDir::currentPath());
	ui.sensitiveCheckBox->setEnabled(false);
	ui.stopPushBtn->setEnabled(false);
 
 }
