#ifndef PROCESSJOSN_H
#define PROCESSJOSN_H

#include <QString>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QDebug>


class ProcessJosn
{
public:
    ProcessJosn();

    void analysisJson(QString Input, QString Output);
    void createView();


    QJsonObject createView1(QString JsonStr);



private:

    QString m_JsonString;

};

#endif // PROCESSJOSN_H
