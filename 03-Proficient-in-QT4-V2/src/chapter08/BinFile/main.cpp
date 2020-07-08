#include <iostream>
#include <QtCore>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	
	QFile file("binary.file");
	file.open(QIODevice::WriteOnly | QIODevice::Truncate);
	QDataStream out(&file);   
	out << QString("caizhiming");   
	out << QDate::fromString("1986/01/03", "yyyy/MM/dd");
	out << (qint32)21;
	file.close();

	file.setFileName("binary.file");
	if(!file.open(QIODevice::ReadOnly)) {
		cout << "打开文件出错!";
		return 1;
	}
	QDataStream in(&file);
	QString name;
	QDate birthday;
	qint32 age;
	in >> name >> birthday >> age;
	qDebug() << name << birthday << age;
 	cout << qPrintable(name) << '\t' << qPrintable(birthday.toString("yyyy MMMM dd dddd")) << "\t" << age << endl;
	file.close();
	return 0;
}

