#ifndef THREADWELL_H
#define THREADWELL_H

#include <QThread>

class WellData;
class Process;


class ThreadWell:public QThread
{
public:
    ThreadWell();

    void SetPdata(WellData *);

    Process m_ProcessFun;

protected:
    void run();

private:

    WellData *m_pWelldata;





};

#endif // THREADWELL_H
