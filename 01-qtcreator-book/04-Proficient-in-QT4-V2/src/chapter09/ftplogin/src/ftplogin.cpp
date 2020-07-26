#include "ftplogin.h"

FtpLogin::FtpLogin(QObject *parent)
	: QObject(parent)
{
	connect(&ftp,SIGNAL(done(bool)),this,SLOT(ftpDone(bool)));
	connect(&ftp,SIGNAL(commandStarted(int)),this,SLOT(ftpcommandStarted(int)));
	connect(&ftp,SIGNAL(commandFinished(int,bool)),this,SLOT(ftpcommandFinished(int,bool)));
}

FtpLogin::~FtpLogin()
{

}

bool FtpLogin::logIn(const QUrl &url)
{
	if(!url.isValid()){
		qDebug()<<tr("����:��Ч URL")<<endl;
		return false;
	}
	if(url.scheme() !="ftp"){
		qDebug()<<tr("����: URL ������ 'ftp:'��ʼ")<<endl;
		return false;
	}

	connectId = ftp.connectToHost(url.host(),url.port(21));
	loginId = ftp.login();
	closeId = ftp.close();
	return true;
}

void FtpLogin::ftpcommandStarted(int id)
{
	if(id == connectId){
		qDebug()<<QObject::tr("������....")<<endl;
	}else if(id == loginId){
		qDebug()<<QObject::tr("��½��...")<<endl;
	}else if(id == closeId){
		qDebug()<<QObject::tr("�ر���...")<<endl;
	}
}

void FtpLogin::ftpcommandFinished(int id,bool error)
{
	if(error){
		qDebug()<<QObject::tr("�������󣬳����˳���");
		return;
	}

	if(id == connectId){
		qDebug()<<QObject::tr("������")<<endl;
	}else if(id == loginId){
		qDebug()<<QObject::tr("�ѵ�½")<<endl;
	}else if(id == closeId){
		qDebug()<<QObject::tr("�ѹر�")<<endl;
	}
}
void FtpLogin::ftpDone(bool error)
{
	if(error){
		qDebug()<<tr("����:")<<qPrintable(ftp.errorString())<<endl;
	}
	emit done();
}
