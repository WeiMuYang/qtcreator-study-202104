
#include "GroupServer.h"
#include <QPushButton>
int main(int argc, char** argv)
{
	QApplication app(argc, argv);	
	GroupServer* serv = new GroupServer();
	serv->initSocket();
	QPushButton *button = new QPushButton("Quit");
	QObject::connect(button, SIGNAL(clicked()),&app, SLOT(quit()));
	button->show();
	return app.exec();
}

