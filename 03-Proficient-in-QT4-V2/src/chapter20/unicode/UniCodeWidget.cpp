#include <QtGui>
#include "UniCodeWidget.h"

UniCodeWidget::UniCodeWidget()
{
	txtEdit = new QLineEdit;
	lblUnicode = new QLabel;
	layout = new QVBoxLayout;
	layout->addWidget(txtEdit);
	layout->addWidget(lblUnicode);
	setLayout(layout);
	connect(txtEdit, SIGNAL(textChanged(const QString&)), this, SLOT(showUniCode(const QString&)));
}

UniCodeWidget::~UniCodeWidget()
{
}

void UniCodeWidget::showUniCode(const QString& text)
{
	QChar unicodeChar;
	QString unicodeNum;
	int i;
	for(i=0; i<text.size(); i++)
	{
		unicodeChar = text[i];
		unicodeNum.push_back(QString("0x%1,").arg(unicodeChar.unicode(), 0, 16));
	}
	if(i>0)
		unicodeNum.chop(1);
	lblUnicode->setText(unicodeNum);
}
