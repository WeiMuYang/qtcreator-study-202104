#include <iostream>
#include <QtCore>

using namespace std;

qint64 du(const QString &path)
{
	QDir dir(path);
	qint64 size = 0;
	foreach (QFileInfo fileInfo, dir.entryInfoList(QDir::Files))
		size += fileInfo.size();
	foreach (QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
		size += du(path + QDir::separator() + subDir);
	char unit = 'B';
	quint64 curSize = size;
	if(curSize > 1024) {
		curSize /= 1024;
		unit = 'K';
		if(curSize > 1024) {
			curSize /= 1024;
			unit = 'M';
			if(curSize > 1024) {
				curSize /= 1024;
				unit = 'G';
			}
		}
	}	
	cout << curSize << unit << "\t" << qPrintable(path) << endl;
	return size;
} 

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	
	QStringList args = app.arguments();
	QString path;
	if (args.count() > 1)
		path = args[1];
	else
		path = QDir::currentPath();
	du(path);
	return 0;
}

