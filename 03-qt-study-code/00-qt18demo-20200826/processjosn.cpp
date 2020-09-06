#include "processjosn.h"






ProcessJosn::ProcessJosn()
{
    m_JsonString = " {\n \"name\" :\"value\",\n \"secondName\":{\"thirdName\":\"thirdValue\"},\n"
                   " \"recoveryPrimaryNode\":[ \n"
                   "{\"id\":\"1\",\"iconTxt\":\"Picture\",\"iconName\":\"1.jpg\"},\n"
                   "{\"id\":\"2\",\"iconTxt\":\"Video\",\"iconName\":\"2.jpg\"},\n"
                   "{\"id\":\"3\",\"iconTxt\":\"TXT\",\"iconName\":\"3.jpg\"},\n"
                   "{\"id\":\"4\",\"iconTxt\":\"RAR\",\"iconName\":\"4.jpg\"}]\n}";


            qDebug().noquote() << m_JsonString;




            createView1(m_JsonString);

}

void ProcessJosn::analysisJson(QString Input, QString Output)
{

}


void ProcessJosn::createView()
{
    /*解析json文件*/
    QFile file(":/test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString value = file.readAll();
    file.close();

    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(),&parseJsonErr);
    if(!(parseJsonErr.error == QJsonParseError::NoError))
    {
        qDebug() << "解析json文件错误！";
        return;
    }
    QJsonObject jsonObject = document.object();
    qDebug()<<"jsonObject[name]=="<<jsonObject["name"].toString();

    if(jsonObject.contains(QStringLiteral("secondName")))
    {
        QJsonValue jsonValueList = jsonObject.value(QStringLiteral("secondName"));
        QJsonObject item = jsonValueList.toObject();
        qDebug()<<"item[thirdName]=="<<item["thirdName"].toString();
    }

    if(jsonObject.contains(QStringLiteral("recoveryPrimaryNode")))
    {
        QJsonValue arrayValue = jsonObject.value(QStringLiteral("recoveryPrimaryNode"));
        if(arrayValue.isArray())
        {
            QJsonArray array = arrayValue.toArray();
            for(int i=0;i<array.size();i++)
            {
                QJsonValue iconArray = array.at(i);
                QJsonObject icon = iconArray.toObject();
                QString id = icon["id"].toString();
                QString iconTxt = icon["iconTxt"].toString();
                QString iconName = icon["iconName"].toString();
                qDebug()<<"id="<<id<<"iconTxt="<<iconTxt<<"iconName="<<iconName;
            }
        }
    }
}


QJsonObject ProcessJosn::createView1(QString JsonStr)
{
     QJsonDocument jsondoc = QJsonDocument::fromJson(JsonStr.toLocal8Bit().data());
     if(jsondoc.isNull()){
         qDebug() << "Sring NULL" << JsonStr.toLocal8Bit().data();
     }
     QJsonObject jsonObj = jsondoc.object();


    qDebug() << jsonObj;


    return jsonObj;
}


