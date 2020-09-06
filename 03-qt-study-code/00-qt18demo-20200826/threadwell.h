#ifndef THREADWELL_H
#define THREADWELL_H

// #include <QObject>
#include <QThread>
#include <QMutex>


class WellsData;
class WellOfProcess;

class ThreadWell : public QThread
{
public:
    ThreadWell();

    void ThreadPause();
    void ThreadContinue();
    void ThreadStop();
    void ThreadStart();

    void setThreadStatus(int s);

    void SetWellsData(WellsData *);


protected:
    void run();

private:

    WellsData *m_pWellData;
    // bool m_stop;

    int m_WellStatus; // 0:初始化  1：Process1   2： Process2   3： Process3   4： Process
    WellOfProcess *m_process;

    QMutex m_mutex;
};

#endif // THREADWELL_H
