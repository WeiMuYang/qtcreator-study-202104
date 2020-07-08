#include <iostream>
#include <QtCore>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    int pos;
    int index;
    QRegExp rx("(http://(?:[a-z0-9_\\.])+(?:com|cn|net|org|gov|mil)"
    	"|(ftp://(?:[a-z0-9_\\.])+(?:com|cn|net|org|gov|mil))"
    	"|(mailto:(?:[a-z0-9_\\.])+@(?:[a-z0-9\\.])+(?:com|cn|net|org|gov|mil)))");
    if(!rx.isValid())
    {
    	cout << qPrintable(rx.errorString());
    	return -1;
    }
    
    QFile file("index.html");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return -1;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString str = in.readLine();
	 	pos = 0;
	 	while ((pos = rx.indexIn(str, pos)) != -1) {
	 		for(index = 0; index <3; index++) {
	 			if(!rx.cap(index).isEmpty())	
					cout << qPrintable(rx.cap(index)) << endl;
	 		}
	     	pos += rx.matchedLength();
	 	}
    } 
    return 0;
}
