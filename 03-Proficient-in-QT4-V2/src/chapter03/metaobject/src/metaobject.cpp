#include <QDebug>
#include <QtGui>
#include <QtCore>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);	
	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
	
	QObject* obj = new QLabel;
	const QMetaObject* mo = obj->metaObject();
	qDebug() << QObject::tr("������%1").arg(mo->className());
	qDebug() << QObject::tr("�Ƿ�̳���QWidget��%1")
			.arg(obj->inherits("QWidget") ? QObject::tr("��") : QObject::tr("��") );	
    return 0;
}
