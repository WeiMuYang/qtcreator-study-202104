#include <iostream>
#include <QtCore>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	
	QStringList args = app.arguments();
	QString fileName;
	if (args.count() > 1)
		fileName = args[1];
	else {
		cout << "请提供文件名." << endl;
		return 1;
	}

	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		cout << "打开文件出错." << endl;
		return -2;
	}

	while (!file.atEnd()) {
		QByteArray line = file.readLine();
		for (int i = 0; i < line.size(); ++i)
			cout << line[i];	
	}
	
/*	QTextStream in(&file);
	while (!in.atEnd()) {
		QString line = in.readLine();
		cout << qPrintable(line) << endl;
	}
	return 0;*/
}

