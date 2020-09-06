#ifndef SETTINGCONFIG_H
#define SETTINGCONFIG_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <QVector>
#include <qtextcodec.h>
#include <qtextstream.h>

class SettingConfig
{
public:
    SettingConfig();

    QVector<QString> SelectWell;
    QVector<QString> SelectPosition;
    QVector<QString> ASelect;
    QVector<QString> B1Select;
    QVector<QString> B2Select;
    QVector<QString> B3Select;
    QVector<QString> B4Select;
    QVector<QString> B5Select;
    QVector<QString> B6Select;
    QVector<QString> CSelect;
    QVector<QString> DSelect;
    QVector<QString> SSelect;
    void Read(QString path);
    void Write(QString Cname);
    void test();
};

#endif // SETTINGCONFIG_H
