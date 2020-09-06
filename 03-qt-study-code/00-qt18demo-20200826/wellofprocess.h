#ifndef WELLOFPROCESS_H
#define WELLOFPROCESS_H

#include "wellsdata.h"

#include "changesyncstatus.h"


class WellOfProcess
{
public:
    WellOfProcess();

     void MySleep(double sec);

    void Process1(WellsData wellData);
    // 由按钮C2触发，或者通过指令
    void Process2(WellsData wellData);
    // 由按钮C3触发，或者通过指令
    void Process3(WellsData wellData);
    // 通过指令
    void Process4(WellsData wellData);

    QString getTimeNowHMS();
    QString getTimeNowMDHMS();

private:
    ChangeSyncStatus m_ChangeStatus;



};

#endif // WELLOFPROCESS_H
