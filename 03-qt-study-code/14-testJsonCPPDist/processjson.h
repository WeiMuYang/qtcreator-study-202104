#ifndef PROCESSJSON_H
#define PROCESSJSON_H


#include "json.h"
#include <QDate>
#include <QString>
#include <QByteArray>

class ProcessJson
{
public:
    ProcessJson();

    Json::Value m_RootJsonArr[30];
    QByteArray m_JsonBytes[30];

    void ChangeToBytes(int i);

    void createJson0();

    void AnalysisJsonByQJson();

};

#endif // PROCESSJSON_H
