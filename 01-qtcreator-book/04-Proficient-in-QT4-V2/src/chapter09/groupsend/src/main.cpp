
#include "GroupSend.h"
#include <QPushButton>
int main(int argc, char** argv)
{
	QApplication app(argc, argv);	
	GroupSend* send = new GroupSend();
	send->initSocket();
	QPushButton *button = new QPushButton("Quit");
	QObject::connect(button, SIGNAL(clicked()),&app, SLOT(quit()));
	button->show();
	return app.exec();
}

