#include <QtGui>
#include "mywidget.h"

MyWidget::MyWidget(QWidget* parent)
	: QWidget(parent)
{
	QStringList strList;
	strList << "test" << "itemactivated";
	list = new QListWidget;
	list->addItems(strList);
	connect(list, SIGNAL(itemActivated(QListWidget*)), this, SLOT(test(QListWidgetItem*)));
	layout = new QVBoxLayout;
	layout->addWidget(list);
	setLayout(layout);
}

void MyWidget::test(QListWidgetItem* item)
{
	QMessageBox::information(this, "text", item->text());
}


