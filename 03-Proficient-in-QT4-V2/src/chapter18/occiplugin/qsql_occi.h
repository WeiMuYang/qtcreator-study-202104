#ifndef QSQL_OCCI_H
#define QSQL_OCCI_H

#include <QtSql/qsqlresult.h>
#include <QtSql/qsqldriver.h>
#include <QtSql/private/qsqlcachedresult_p.h>

#include "occi.h"

using namespace oracle::occi;

class QOCCIResult : public QSqlCachedResult
{
    friend class QOCCIDriver;
public:
    QOCCIResult(const QOCCIDriver * db);
    ~QOCCIResult();
    bool prepare(const QString& query);
    bool exec();
    QVariant handle() const;

protected:
    bool gotoNext(ValueCache &values, int index);
    bool reset (const QString& query);
    int size();
    int numRowsAffected();
    QSqlRecord record() const;
    QVariant lastInsertId() const;
    void virtual_hook(int id, void *data);

private:
	Environment *env;		/// OCCI环境
	Connection *conn;		/// OCCI连接
	Statement *stmt;		/// OCCI语句
};


class QOCCIDriver : public QSqlDriver
{
    friend class QOCCIResultPrivate;
    friend class QOCCIPrivate;
public:
    explicit QOCCIDriver(QObject* parent = 0);
    ~QOCCIDriver();
    bool hasFeature(DriverFeature f) const;
    bool open(const QString & db,
              const QString & user,
              const QString & password,
              const QString & host,
              int port,
              const QString& connOpts);
    void close();
    QSqlResult *createResult() const;
    QStringList tables(QSql::TableType) const;
    QSqlRecord record(const QString& tablename) const;
    QSqlIndex primaryIndex(const QString& tablename) const;
    QString formatValue(const QSqlField &field,
                        bool trimStrings) const;
    QVariant handle() const;

protected:
    bool                beginTransaction();
    bool                commitTransaction();
    bool                rollbackTransaction();
private:
	Environment *env;		/// OCCI环境
	Connection *conn;		/// OCCI连接
	Statement *stmt;		/// OCCI语句
};

#endif // QSQL_OCCI_H
