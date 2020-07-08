// findfileform.cpp 文件.
#include <QtGui>
#include "findfileform.h"

CFindFileForm::CFindFileForm(QWidget* parent)
 :	QWidget(parent)
 {
 	ui.setupUi(this);	
	ui.statusLabel->setText(tr("就绪"));	
	ui.resultLabel->setText(tr("找到0个文件"));
	ui.nameComboBox->setEditText("*");
	ui.dirComboBox->setEditText(QDir::currentPath());
	ui.dirComboBox->addItem(QDir::currentPath());
	ui.sensitiveCheckBox->setEnabled(false);
	ui.stopPushBtn->setEnabled(false);
 
 }
