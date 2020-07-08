#ifndef HTTPGET_H
#define HTTPGET_H

#include <QObject>
#include <QtNetwork>
class QFile;
class HttpGet : public QObject
{
	Q_OBJECT

public:
    HttpGet(QObject *parent =0);
    ~HttpGet();
    bool downloadFile(QUrl);
signals:
	void done();
private slots:
    void httpRequestFinished(int requestId, bool error);
	void readResponseHeader(const QHttpResponseHeader &responseHeader);
	void updateDataReadProgress(int bytesRead, int totalBytes);
	void httpDone(bool error);
private:
	QHttp *http;
	QFile *file;
	int httpGetId;
	bool httpRequestAborted;
	QString fileName;
};

#endif // HTTPGET_H
