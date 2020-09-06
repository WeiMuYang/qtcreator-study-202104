#ifndef CHANGESYNCSTATUS_H
#define CHANGESYNCSTATUS_H

#include "wellsdata.h"
#include <QMovie>


class ChangeSyncStatus
{
public:
    ChangeSyncStatus();

    //灯泡状态同步
    bool ChangeBulb(WellsData well, const QString bulbName, int status);
    void ChangePanBulb(WellsData well,int status);
    void ChangeLightBulb(WellsData well,int Num,int status);
    void ChangeSwitchBulb(WellsData well,int Num,int status);
    //  TableName: title   content
    bool ChangeTable(WellsData well, const QString TableName,
                     const int row, const int col, const QString text, QColor  background);
    bool ChangeLabel(WellsData well, const QString LabelName, const QString text);


private:
//    QMovie *m_MovieArr[100];
//    int m_indexOfMovieArr;
//    QSize m_si1;
//    QSize m_si2;



};
#endif // CHANGESYNCSTATUS_H
