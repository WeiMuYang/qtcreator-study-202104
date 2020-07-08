
#include "connectdlg.h"
#include "ui_connectdlg.h"

#include <QSqlDatabase>
#include <QtSql>
ConnDlg::ConnDlg(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    QStringList drivers = QSqlDatabase::drivers();
    ui.comboDriver->addItems(drivers);
    connect(ui.comboDriver,SIGNAL(currentIndexChanged( const QString & )),this,SLOT(driverChanged(const QString &)));
		ui.status_label->setText(tr("׼���������ݿ⣡"));
}

ConnDlg::~ConnDlg()
{
}

QString ConnDlg::driverName() const
{
    return ui.comboDriver->currentText();
}

QString ConnDlg::databaseName() const
{
    return ui.editDatabase->text();
}

QString ConnDlg::userName() const
{
    return ui.editUsername->text();
}

QString ConnDlg::password() const
{
    return ui.editPassword->text();
}

QString ConnDlg::hostName() const
{
    return ui.editHostname->text();
}

int ConnDlg::port() const
{
    return ui.portSpinBox->value();
}


void ConnDlg::on_okButton_clicked()
{
    if (ui.comboDriver->currentText().isEmpty()) {
		ui.status_label->setText(tr("��ѡ��һ�����ݿ�������"));
		ui.comboDriver->setFocus();
    } else if(ui.comboDriver->currentText() =="QSQLITE"){
		addSqliteConnection();
//�������ݿ�����Դ���������ִ�С�
//     	creatDB();
		accept();
    }else{
    QSqlError err = addConnection(driverName(), databaseName(), hostName(),
                           userName(), password(), port());
    if (err.type() != QSqlError::NoError)
			ui.status_label->setText(err.text());
		else
			ui.status_label->setText(tr("�������ݿ�ɹ�!"));
//�������ݿ�����Դ���������ִ�С�
// 			creatDB();
			accept();
    }
}

QSqlError ConnDlg::addConnection(const QString &driver, const QString &dbName, const QString &host,const QString &user, const QString &passwd, int port)
{

    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setPort(port);
    if (!db.open(user, passwd)) {
        err = db.lastError();
    }
    return err;
}

void ConnDlg::driverChanged(const QString & text)
{
	if(text =="QSQLITE")
	{
		ui.editDatabase->setEnabled(false);
		ui.editUsername->setEnabled(false);
		ui.editPassword->setEnabled(false);
		ui.editHostname->setEnabled(false);
		ui.portSpinBox->setEnabled(false);
	}
	else{
		ui.editDatabase->setEnabled(true);
		ui.editUsername->setEnabled(true);
		ui.editPassword->setEnabled(true);
		ui.editHostname->setEnabled(true);
		ui.portSpinBox->setEnabled(true);
	}
}

void ConnDlg::addSqliteConnection()
{
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("databasefile");
		if (!db.open())
		{
						ui.status_label->setText(db.lastError().text());
			return;
		}

		ui.status_label->setText(tr("����sqlite���ݿ�ɹ�!"));

}

void ConnDlg::creatDB()
{
	 QSqlQuery query;
   query.exec("create table factory (id int primary key, "
                                     "manufactory varchar(40), "
                                     "address varchar(40))");
    query.exec(QObject::tr("insert into factory values(1, 'һ������', '����')"));
    query.exec(QObject::tr("insert into factory values(2, '��������', '�人')"));
    query.exec(QObject::tr("insert into factory values(3, '�Ϻ�����', '�Ϻ�')"));

// 		query.exec("create table cars (carid int primary key, "
// 																	"name varchar(50), "
// 																	"factoryid int, "
// 																	"year int)");

    query.exec("create table cars (carid int primary key, "
                                     "name varchar(50), "
                                     "factoryid int, "
                                     "year int, "
																		 "foreign key(factoryid) references factory)");
    query.exec(QObject::tr("insert into cars values(1, '�µ�A6', 1, 2005)"));
    query.exec(QObject::tr("insert into cars values(2, '�ݴ�', 1, 1993)"));
    query.exec(QObject::tr("insert into cars values(3, '����', 1, 2000)"));
    query.exec(QObject::tr("insert into cars values(4, '�ϼ���', 2, 1999)"));
    query.exec(QObject::tr("insert into cars values(5, '����', 2, 2004)"));
    query.exec(QObject::tr("insert into cars values(6, '����307', 2, 2001)"));
    query.exec(QObject::tr("insert into cars values(7, 'ɣ����', 3, 1995)"));
    query.exec(QObject::tr("insert into cars values(8, '������', 3, 2000)"));
}