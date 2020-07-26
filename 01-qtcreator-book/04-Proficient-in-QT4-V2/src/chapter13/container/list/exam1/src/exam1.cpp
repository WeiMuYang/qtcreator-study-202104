// chapter15/container/list/exam1.
#include <QDebug>

int main(int argc, char *argv[])
{
	QList<QString> list;
	{
		QString str("This is a test string");
		list << str << "How are you!";
	}
	qDebug() << list[0];
			
    return 0;
}
