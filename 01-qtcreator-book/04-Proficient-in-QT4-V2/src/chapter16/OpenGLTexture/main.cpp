#include <QtGui>

#include "mygl.h"

int main(int argc, char **argv)
{
	Q_INIT_RESOURCE(texture);

	QApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
	MyGLWidget myglWidget;
	myglWidget.show();
	return app.exec();
}
