#include <QtGui>
#include <QDebug>

#include "ctrlform.h"

int main(int argc, char *argv[])
{
 	QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
	
	CCtrlForm form;
	form.show();
	return app.exec();
}
