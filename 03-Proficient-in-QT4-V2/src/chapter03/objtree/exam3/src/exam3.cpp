// objtree/exam3.
#include <QtGui>
#include <QDebug>

int main(int argc, char *argv[])
{	
	QApplication app(argc, argv);
	
	QDialog* dlg = new QDialog(0);	
	QTableWidget* tbl = new QTableWidget(dlg);
	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(tbl);
	dlg->setLayout(layout);
	
	QList<QObject*> list = dlg->children();
	qDebug() << "dialog's children: ";
	for(int i=0; i<list.size(); ++i)
		qDebug() << list.at(i);	


	list = layout->children();
	qDebug() << "layout's children: ";
	for(int i=0; i<list.size(); ++i)
		qDebug() << list.at(i);
	delete tbl;	
	list = dlg->children();
	qDebug() << "afterdelete tablewidget, dialog's children: ";
	for(int i=0; i<list.size(); ++i)
		qDebug() << list.at(i);
	
	return 0;
}
