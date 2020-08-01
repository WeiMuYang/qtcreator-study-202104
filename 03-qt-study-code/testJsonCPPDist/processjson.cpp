#include "processjson.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

ProcessJson::ProcessJson()
{


    // createJson0();
}

void ProcessJson::ChangeToBytes(int i)
{
    if(i == 0)
        createJson0();
    QString jsonout ;
//  方法1. 从Json::Value转 QString  再转 QByteArray
    jsonout = m_RootJsonArr[0].toStyledString().c_str();


//   方法2.从 Json::FastWriter  转 QString  再转 QByteArray
//    Json::FastWriter fw;
//    jsonout = fw.write(m_RootJsonArr[0]).c_str();


    m_JsonBytes[i] = jsonout.toLatin1();

    AnalysisJsonByQJson();

}


void ProcessJson::createJson0()
{
    QDateTime time = QDateTime::currentDateTime();
    QString date = time.toString("yyyy-MM-dd hh:mm:ss");


    m_RootJsonArr[0]["type"] = "hakzt";
    m_RootJsonArr[0]["sbdw"] = "A01";

    Json::Value status;


    Json::Value deviceStatus;
    Json::Value mmjk;
    mmjk["code"] = "00001";
    mmjk["fsd"] = 1;
    mmjk["sdsj"] = 1;
    mmjk["status"] = 2;
    mmjk["type"] = 1;
    mmjk["tzy"] = 1;
    mmjk["updatetime"] = date.toStdString();
    deviceStatus["mmjk"] = mmjk;
    status["deviceStatus"] = deviceStatus;

    Json::Value lockStatus;
    Json::Value byb;
    byb["code"] = "02001";
    byb["mode"] = 0x00;
    byb["resultsqjg"] = 0x00;
    byb["resultzxjg"] = 0x00;
    byb["type"] = 2;
    byb["updatetime"] = date.toStdString();
    lockStatus["byb"] = byb;

    Json::Value dh;
    dh["code"] = "04001";
    dh["kxtd"] = 1;
    dh["mode"] = 0x00;
    dh["resultsqjg"] = 0x00;
    dh["resultzxjg"] = 0x00;
    dh["type"] = 4;
    dh["updatetime"] = date.toStdString();
    lockStatus["dh"] = dh;

    Json::Value djmb;
    djmb["code"] = "01001";
    djmb["resultdjmb"] = 0;
    djmb["type"] = 1;
    djmb["updatetime"] = date.toStdString();
    lockStatus["djmb"] = djmb;
    status["lockStatus"] = lockStatus;


    Json::Value weaponstatus;
    weaponstatus["bdnm"] = "A01B01C01D01E01F12";
    weaponstatus["weaponType"] = 3;
    weaponstatus["zbzt"] = 1;

    status["weaponstatus"] = weaponstatus;

    // 先有内部，再构造外部；次序变了，外部可能为空
    m_RootJsonArr[0]["status"] = status;

    QString jsonout = m_RootJsonArr[0].toStyledString().c_str();

    qDebug().noquote() << jsonout ;

}

void ProcessJson::AnalysisJsonByQJson()
{
    m_JsonBytes[0];

    QJsonArray json_array2 = QJsonDocument::fromJson(m_JsonBytes[0]).array();
    int tag = json_array2.at(0).toInt();





    QJsonObject json_object2 = QJsonDocument::fromJson(m_JsonBytes[0]).object();
    qDebug() << json_object2.value("type").toString();
    qDebug() << json_object2.value("sbdw").toString();
    QJsonObject status = json_object2.value("status").toObject();

    QJsonObject weaponstatus = status.value("weaponstatus").toObject();
    qDebug() << weaponstatus.value("bdnm").toString();
    qDebug() << weaponstatus.value("weaponType").toInt();
    qDebug() << weaponstatus.value("zbzt").toInt();


}


