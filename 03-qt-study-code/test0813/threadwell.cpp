#include "threadwell.h"
#include "welldata.h"
#include "process.h"

ThreadWell::ThreadWell()
{

}

void ThreadWell::SetPdata(WellData *p)
{
    m_pWelldata = p;
}

void ThreadWell::run()
{
    m_ProcessFun.Process1(m_pWelldata);
    msleep(500);

    m_ProcessFun.Process2(m_pWelldata);
    msleep(500);


    m_ProcessFun.Process3(m_pWelldata);
    msleep(500);


    m_ProcessFun.Process4(m_pWelldata);
    msleep(500);

}
