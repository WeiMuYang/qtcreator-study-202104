// chapter15/variant/exam1.
#include <QDebug>
#include <QVariant>
#include <QColor>

int main(int argc, char *argv[])
{
	QVariant v(709);
	qDebug() <<  v.toInt();
	v = QVariant("How are you!");
	qDebug() << v.toString();
	QMap <QString, QVariant> map;
	map["int"] = 709;
	map["double"] = 709.709;
	map["string"] = "How are you!";
	map["color"] = QColor(255, 0, 0);
	qDebug() << map["int"] << map["int"].toInt();
	qDebug() << map["double"] << map["double"].toDouble();
	qDebug() << map["string"] << map["string"].toString();
	qDebug() << map["color"] << map["color"].value<QColor>();
	QStringList sl;
	sl << "A" << "B" << "C" << "D";
	QVariant slv(sl);
	if(slv.type() == QVariant::StringList)
	{
		QStringList list = slv.toStringList();
		for(int i=0; i<list.size(); ++i)
			qDebug() << list.at(i);
	}
    return 0;
}

