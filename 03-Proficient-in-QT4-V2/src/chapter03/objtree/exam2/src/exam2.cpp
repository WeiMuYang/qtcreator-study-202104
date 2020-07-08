// objtree/exam2.
#include <QtGui>
#include <QDebug>

int main(int argc, char *argv[])
{	
	QApplication app(argc, argv);
	
	QDialog* dlg = new QDialog(0);
	qDebug() << "dlg(1) = " << dlg;
	
	QTableWidget* tbl = new QTableWidget(dlg);
	qDebug() << "tbl(1) = " << tbl;
	
	dlg->exec();	
	qDebug() << "dlg(2) = " << dlg;
	qDebug() << "tbl(2) = " << tbl;
	
	delete tbl;		
	dlg->exec();

	Q_ASSERT(dlg != NULL);
	Q_ASSERT(tbl != NULL);
	qDebug() << "after delete child";
	delete dlg;

	return 0;
}
