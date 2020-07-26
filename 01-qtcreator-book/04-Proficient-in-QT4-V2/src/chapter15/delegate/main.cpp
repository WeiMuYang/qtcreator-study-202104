#include <QtGui>

#include "delegate.h"

void populateData(QTableWidget& table)
{
    table.setItem(0, 0, new QTableWidgetItem(QObject::tr("������")));
    table.setItem(1, 0, new QTableWidgetItem(QObject::tr("ʷ����")));
    table.setItem(2, 0, new QTableWidgetItem(QObject::tr("Ѧ����")));
    table.setItem(3, 0, new QTableWidgetItem(QObject::tr("��Ԫ��")));
	
    table.setItem(0, 1, new QTableWidgetItem(QObject::tr("1980/2/3")));
    table.setItem(1, 1, new QTableWidgetItem(QObject::tr("1981/10/24")));
    table.setItem(2, 1, new QTableWidgetItem(QObject::tr("1978/5/15")));
    table.setItem(3, 1, new QTableWidgetItem(QObject::tr("1979/8/29")));
	
    table.setItem(0, 2, new QTableWidgetItem(QObject::tr("165")));
    table.setItem(1, 2, new QTableWidgetItem(QObject::tr("168")));
    table.setItem(2, 2, new QTableWidgetItem(QObject::tr("162")));
    table.setItem(3, 2, new QTableWidgetItem(QObject::tr("163")));
	
    table.setItem(0, 3, new QTableWidgetItem(QObject::tr("����")));
    table.setItem(1, 3, new QTableWidgetItem(QObject::tr("�㽭")));
    table.setItem(2, 3, new QTableWidgetItem(QObject::tr("����")));
    table.setItem(3, 3, new QTableWidgetItem(QObject::tr("����")));    
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    QTableWidget table(3,4);
    QStringList labels;
    labels << QObject::tr("����") << QObject::tr("��������") << QObject::tr("���") << QObject::tr("����");  
    table.setHorizontalHeaderLabels(labels);
    
    EditorDelegate delegate;
    table.setItemDelegate(&delegate);
    
    populateData(table);

    table.setWindowTitle(QObject::tr("����ʾ��"));
    table.resize(640,480);
    table.show();
    return app.exec();
}
