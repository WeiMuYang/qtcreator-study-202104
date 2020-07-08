#include <QtGui>

#include "mygl.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	MyGLWidget myglWidget;
	myglWidget.show();
	return app.exec();
}
