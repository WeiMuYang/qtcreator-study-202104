#include "threadwell.h"

#include "wellsdata.h"
#include "wellofprocess.h"
#include <QDebug>

ThreadWell::ThreadWell()
{
    m_WellStatus = 0;
    m_pWellData = NULL;

}

void ThreadWell::ThreadPause()
{
    m_mutex.lock();
    qDebug() << m_pWellData->m_WellNum << " Pause!";
}

void ThreadWell::ThreadContinue()
{
    m_mutex.unlock();
    qDebug() << m_pWellData->m_WellNum << " Continue ...";
}

void ThreadWell::ThreadStop()
{
    qDebug() << m_pWellData->m_WellNum << " Stop.";
    terminate();
    wait();
}

void ThreadWell::ThreadStart()
{
    qDebug() << m_pWellData->m_WellNum << " Start ...";
    start();
}

void ThreadWell::setThreadStatus(int s)
{
    m_WellStatus = s;
}


void ThreadWell::SetWellsData(WellsData * p)
{
    m_pWellData = p;
}

void ThreadWell::run()
{
    while(1){
        m_mutex.lock();
        switch (m_WellStatus) {
        case 0:
            ;
            break;
        case 1:
            m_process->MySleep(5);
            m_process->Process1(*m_pWellData);

            break;
        case 2:
            m_process->Process2(*m_pWellData);
            break;
        case 3:
            m_process->Process3(*m_pWellData);
            break;
        case 4:
            m_process->Process4(*m_pWellData);
            break;
        default:
            break;
        }
       m_mutex.unlock();
       ThreadPause();      // 每运行完一个流程暂停一下
    }
}
