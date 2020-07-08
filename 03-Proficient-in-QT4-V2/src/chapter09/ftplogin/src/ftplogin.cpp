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
		qDebug()<<tr("错误:无效 URL")<<endl;
		return false;
	}
	if(url.scheme() !="ftp"){
		qDebug()<<tr("错误: URL 必须以 'ftp:'开始")<<endl;
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
		qDebug()<<QObject::tr("连接中....")<<endl;
	}else if(id == loginId){
		qDebug()<<QObject::tr("登陆中...")<<endl;
	}else if(id == closeId){
		qDebug()<<QObject::tr("关闭中...")<<endl;
	}
}

void FtpLogin::ftpcommandFinished(int id,bool error)
{
	if(error){
		qDebug()<<QObject::tr("操作错误，程序退出！");
		return;
	}

	if(id == connectId){
		qDebug()<<QObject::tr("已连接")<<endl;
	}else if(id == loginId){
		qDebug()<<QObject::tr("已登陆")<<endl;
	}else if(id == closeId){
		qDebug()<<QObject::tr("已关闭")<<endl;
	}
}
void FtpLogin::ftpDone(bool error)
{
	if(error){
		qDebug()<<tr("错误:")<<qPrintable(ftp.errorString())<<endl;
	}
	emit done();
}
