#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include "json.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    m_UDPSocketSending = new QUdpSocket();
    m_JsonProcess = new ProcessJson();

    SendUDPString(0);


//    Json::Value root;
//    Json::Value arrayObj;
//    Json::Value item;


//    item["uid"]=Json::Value("http://www.cnblogs.com/chechen/");
//    item["fileName"]=Json::Value("mzixi.txt");
//    item["time"]=Json::Value("2017.07.28 10:55:22");
//    item["type"]=Json::Value("Libcurl HTTP POST JSON");
//    item["authList"]=Json::Value("weidong0925@126.com");
//    arrayObj.append(item);


//    root  = arrayObj;

//    QString jsonout = root.toStyledString().c_str();
//    QString jsonout1 = item.toStyledString().c_str();

//    qDebug().noquote() << jsonout ;
//    qDebug().noquote() << jsonout1 ;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QString ip = "192.168.1.101";
    quint16 port = 8000;
    QString str = "close window";
    QByteArray byte = str.toLatin1();
    m_JsonProcess->ChangeToBytes(0);
    m_UDPSocketSending->writeDatagram(byte, (QHostAddress)ip, port);
}

void MainWindow::SendUDPString(int i)
{
    QString ip = "192.168.1.101";
    quint16 port = 8000;
    m_JsonProcess->ChangeToBytes(0);
    m_UDPSocketSending->writeDatagram(m_JsonProcess->m_JsonBytes[i], (QHostAddress)ip, port);
}
