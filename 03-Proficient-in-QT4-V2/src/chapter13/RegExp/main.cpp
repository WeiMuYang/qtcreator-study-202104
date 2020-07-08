#include <iostream>
#include <QtCore>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QStringList capList;
    int pos;
    bool matched;
    //QRegExp rx("[A-Za-z_]+[A-Za-z_0-9]*");
    QRegExp rx("\\b(\\w+)\\W+\\1\\b");
    if(!rx.isValid())
    {
    	cout << qPrintable(rx.errorString());
    	return -1;
    }
    
    QFile file("main.cpp");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return -1;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString str = in.readLine();
	 	pos = 0;
	 	matched = false;
	 	while ((pos = rx.indexIn(str, pos)) != -1) {
	 		capList = rx.capturedTexts();
 			cout << qPrintable(capList.at(0)) << "\t"; 			
	     	pos += rx.matchedLength();
	     	matched = true;
	 	}
 		if(matched)
 			cout << endl;
    } 
    return 0;
}
