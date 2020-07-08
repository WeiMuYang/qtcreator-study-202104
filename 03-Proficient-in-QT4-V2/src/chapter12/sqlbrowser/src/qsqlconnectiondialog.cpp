
#include "qsqlconnectiondialog.h"
#include "ui_qsqlconnectiondialog.h"

#include <QSqlDatabase>
#include <QtSql>
ConnDlg::ConnDlg(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    QStringList drivers = QSqlDatabase::drivers();
//     if (!drivers.contains("QSQLITE"))
//         ui.dbCheckBox->setEnabled(false);

    ui.comboDriver->addItems(drivers);
    connect(ui.comboDriver,SIGNAL(currentIndexChanged( const QString & )),this,SLOT(driverChanged(const QString &)));
	ui.status_label->setText(tr("准备连接数据库！"));
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
		ui.status_label->setText(tr("请选择一个数据库驱动！"));
        ui.comboDriver->setFocus();
    } else if(ui.comboDriver->currentText() =="QSQLITE"){
		creatSqliteDB();
//         accept();
    }else{
    	QSqlError err = addConnection(driverName(), databaseName(), hostName(),
                           userName(), password(), port());
        if (err.type() != QSqlError::NoError)
		ui.status_label->setText(err.text());
	else
		ui.status_label->setText(tr("连接数据库成功!"));
// 	accept();
    }
}

QSqlError ConnDlg::addConnection(const QString &driver, const QString &dbName, const QString &host,const QString &user, const QString &passwd, int port)
{
    static int cCount = 0;

    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase(driver, QString("conn%1").arg(++cCount));
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setPort(port);
    if (!db.open(user, passwd)) {
        err = db.lastError();
        db = QSqlDatabase();
        QSqlDatabase::removeDatabase(QString("conn%1").arg(cCount));
    }
    return err;
}

void ConnDlg::driverChanged(const QString & text)
{
	qDebug()<<text;
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

void ConnDlg::creatSqliteDB()
{
    	QSqlDatabase::database("in_mem_db", false).close();
        QSqlDatabase::removeDatabase("in_mem_db");
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "in_mem_db");
        db.setDatabaseName(":memory:");
        if (!db.open())
			{
            	ui.status_label->setText(db.lastError().text());
				return;
			}
        QSqlQuery q("", db);
        q.exec("drop table Names");
        q.exec("create table Names (id integer primary key, Firstname varchar, Lastname varchar, City varchar)");
        q.exec("insert into Names values (0, 'Sala', 'Palmer', 'Morristown')");
        q.exec("insert into Names values (1, 'Christopher', 'Walker', 'Morristown')");
        q.exec("insert into Names values (2, 'Donald', 'Duck', 'Andeby')");
        q.exec("insert into Names values (3, 'Buck', 'Rogers', 'Paris')");
        q.exec("insert into Names values (4, 'Sherlock', 'Holmes', 'London')");

		ui.status_label->setText(tr("创建sqlite数据库成功!"));

}