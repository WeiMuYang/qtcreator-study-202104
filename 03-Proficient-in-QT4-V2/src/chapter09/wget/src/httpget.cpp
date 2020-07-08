
#include "httpget.h"

HttpGet::HttpGet(QObject *parent)
	: QObject(parent)
{
	http = new QHttp(this);
	connect(http,SIGNAL(done(bool)),this,SLOT(httpDone(bool)));
	connect(http, SIGNAL(requestFinished(int, bool)),
		this, SLOT(httpRequestFinished(int, bool)));
	connect(http, SIGNAL(dataReadProgress(int, int)),
		this, SLOT(updateDataReadProgress(int, int)));
	connect(http, SIGNAL(responseHeaderReceived(const QHttpResponseHeader &)),
		this, SLOT(readResponseHeader(const QHttpResponseHeader &)));
}

HttpGet::~HttpGet()
{

}

bool HttpGet::downloadFile(QUrl url)
{
	QFileInfo fileInfo(url.path());
	fileName = fileInfo.fileName();

	if (QFile::exists(fileName)) {
		qDebug()<<tr("��ǰ·�����ļ� %1 �Ѵ��ڡ�")
			.arg(fileName);
		httpRequestAborted = true;
		return false;
	}

	file = new QFile(fileName);
	if (!file->open(QIODevice::WriteOnly)) {
		qDebug()<<tr("�޷������ļ� %1: %2.")
			.arg(fileName).arg(file->errorString());
		delete file;
		file = 0;
		httpRequestAborted = true;
		return false;
	}

	http->setHost(url.host(), url.port() != -1 ? url.port() : 80);
	if (!url.userName().isEmpty())
		http->setUser(url.userName(), url.password());
	
	httpGetId = http->get(url.path(), file);
	httpRequestAborted = false;
	return true;
}

void HttpGet::httpRequestFinished(int requestId, bool error)
{
	if (httpRequestAborted) {
		if (file) {
			file->close();
			file->remove();
			delete file;
			file = 0;
		}
		return;
	}

	if (requestId != httpGetId)
		return;

	file->close();

	if (error) {
		file->remove();
		qDebug()<<tr("�����ļ�ʧ��: %1")
			.arg(http->errorString());
	} else {
		qDebug()<<tr("�ļ�%1 ������ϡ�").arg(fileName);
	}
	delete file;
	file = 0;
}

void HttpGet::readResponseHeader(const QHttpResponseHeader &responseHeader)
{
	qDebug()<<responseHeader.statusCode();
	if (responseHeader.statusCode() != 200) {//����ɹ���
		qDebug()<<tr("����ʧ�ܣ�%1��")
			.arg(responseHeader.reasonPhrase());
		httpRequestAborted = true;
		http->abort();
		return;
	}
}

void HttpGet::updateDataReadProgress(int bytesRead, int totalBytes)
{
	if (httpRequestAborted)
		return;
	qDebug()<<tr("�����أ�%1%").arg(100*bytesRead/totalBytes);
}

void HttpGet::httpDone(bool error)
{
	if(error){
		qDebug()<<tr("����:")<<qPrintable(http->errorString())<<endl;
	}
	emit done();
}
