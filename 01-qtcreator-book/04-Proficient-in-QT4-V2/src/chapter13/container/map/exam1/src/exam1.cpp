// chapter15/container/map/exam1.
#include <QDebug>

int main(int argc, char *argv[])
{
	QMap<QString, QString> map;
	map.insert("beijing", "111");
	map.insert("shanghai", "021");
	map.insert("tianjin", "022");
	map.insert("chongqing", "023");
	map.insert("jinan", "0531");
	map.insert("wuhan", "027");
	QMapIterator<QString, QString> i(map);
	for( ; i.hasNext(); )
		qDebug() << "	" << i.peekNext().key() <<"		" << i.next().value();	
	QMutableMapIterator<QString, QString> mi(map);
	if(mi.findNext("111"))
		mi.setValue("010");
	QMapIterator<QString, QString> modi(map);
	qDebug() << "";
	for( ; modi.hasNext(); )
		qDebug() << modi.peekNext().key() << modi.next().value();	
			
    return 0;
}
