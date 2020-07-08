// objtree/exam1.
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
	dlg->exec();
	delete dlg;

	Q_ASSERT(dlg != NULL);
	Q_ASSERT(tbl != NULL);

	qDebug() << "after delete parent";
	delete tbl;

	return 0;
}
