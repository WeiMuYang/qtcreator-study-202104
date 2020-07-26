#include <vector>
#include <iostream>

#include <QtCore>
#include <QtSql>

#include "qsql_occi.h"

using namespace std;

QOCCIResult::QOCCIResult(const QOCCIDriver * db)
: QSqlCachedResult(db)
{
}

QOCCIResult::~QOCCIResult()
{
}

QVariant QOCCIResult::handle() const
{
    return QVariant();
}

bool QOCCIResult::reset (const QString& query)
{
    if (!prepare(query))
        return false;
    return exec();
}

bool QOCCIResult::gotoNext(QSqlCachedResult::ValueCache &values, int index)
{
	return true;
}

int QOCCIResult::size()
{
    return -1;
}

int QOCCIResult::numRowsAffected()
{
    return 1;
}

bool QOCCIResult::prepare(const QString& query)
{
    return true;
}

QSqlRecord QOCCIResult::record() const
{
    QSqlRecord inf;
    return inf;
}

QVariant QOCCIResult::lastInsertId() const
{
    return QVariant();
}

void QOCCIResult::virtual_hook(int id, void *data)
{
}

/**
 * QOCCIDriver构造函数.
*/
QOCCIDriver::QOCCIDriver(QObject* parent)
    : QSqlDriver(parent)
{
	try {
		env = Environment::createEnvironment();
	}
	catch (SQLException &e)
	{
//		setLastError(QSqlError(tr("创建环境错误:"), e.getMessage().c_str(), QSqlError::ConnectionError, e.getErrorCode());
		Environment::terminateEnvironment(env);
    }
}

/**
 * QOCCIDriver析构函数.
*/
QOCCIDriver::~QOCCIDriver()
{
    if (isOpen())
        close();

	try {
		Environment::terminateEnvironment(env);
	}
	catch (SQLException &e)
	{
//		setLastError(QSqlError(tr("释放环境误:"), e.getMessage().c_str(), QSqlError::ConnectionError, e.getErrorCode());
    }
}

bool QOCCIDriver::hasFeature(DriverFeature f) const
{
    switch (f) {
    case Transactions:
    case LastInsertId:
    case BLOB:
    case PreparedQueries:
    case NamedPlaceholders:
    case BatchOperations:
        return true;
    case QuerySize:
    case PositionalPlaceholders:
        return false;
    case Unicode:
        //return d->serverVersion >= 9;
		return true;
    }
    return false;
}

static void qParseOpts(const QString &options, QOCCIPrivate *d)
{
}

bool QOCCIDriver::open(const QString & db,
                       const QString & user,
                       const QString & password,
                       const QString & ,
                       int ,
                       const QString &opts)
{

    if (isOpen())
        close();

	try {
		env = Environment::createEnvironment();
		conn = env->createConnection((string)user.toLocal8Bit().constData(), (string)password.toLocal8Bit().constData());
//		Unicode version
//		conn = env->createConnection((UString)user.toLocal8bit().constData(), (UString)password.toLocal8bit().constData());
	}
	catch (SQLException &e)
	{
		//setLastError(QSqlError(tr("连接错误"), e.getMessage().c_str(), QSqlError::ConnectionError, e.getErrorCode());
        setOpenError(true);
		env->terminateConnection(conn);
        return false;
    }

    // get server version
	MetaData metaData = conn->getMetaData((char *)"ora91", MetaData::PTYPE_DATABASE);
	string version = metaData.getString(MetaData::ATTR_VERSION);
	cout << "Oracle version:" << version << endl;

/*	QRegExp vers(QLatin1String("([0-9]+)\\.[0-9\\.]+[0-9]"));
        if (vers.indexIn(version) >= 0)
            d->serverVersion = vers.cap(1).toInt();
        if (d->serverVersion == 0)
            d->serverVersion = -1;
    }*/

    setOpen(true);
    setOpenError(false);

    return true;
}

void QOCCIDriver::close()
{
    if (!isOpen())
        return;

	try {
		env->terminateConnection(conn);
	}
	catch (SQLException &e) {

	}

    setOpen(false);
    setOpenError(false);
}

QSqlResult *QOCCIDriver::createResult() const
{
	QSqlResult *r = new QOCCIResult(this); 
    return r;
}

bool QOCCIDriver::beginTransaction()
{
    if (!isOpen()) {
        qWarning("QOCCIDriver::beginTransaction: Database not open");
        return false;
    }

	// OCCI没有开始Transaction的函数
	return true;
}

bool QOCCIDriver::commitTransaction()
{
    return true;
}

bool QOCCIDriver::rollbackTransaction()
{
    return true;
}

QStringList QOCCIDriver::tables(QSql::TableType type) const
{
	return QStringList();
}

void qSplitTableAndOwner(const QString & tname, QString * tbl,
                          QString * owner)
{
    int i = tname.indexOf(QLatin1Char('.')); // prefixed with owner?
    if (i != -1) {
        *tbl = tname.right(tname.length() - i - 1).toUpper();
        *owner = tname.left(i).toUpper();
    } else {
        *tbl = tname.toUpper();
    }
}

QSqlRecord QOCCIDriver::record(const QString& tablename) const
{
    QSqlRecord fil;
    return fil;
}

QSqlIndex QOCCIDriver::primaryIndex(const QString& tablename) const
{
    return QSqlIndex();
}

QString QOCCIDriver::formatValue(const QSqlField &field, bool) const
{
    return QSqlDriver::formatValue(field);
}

QVariant QOCCIDriver::handle() const
{
    return QVariant();
}

