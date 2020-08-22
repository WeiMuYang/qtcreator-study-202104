#include "process.h"
#include "welldata.h"

Process::Process()
{

}

void Process::Process1(WellData * pdata)
{
    pdata->well.at(0)->setText("1");
}

void Process::Process2(WellData * pdata)
{
    pdata->well.at(0)->setText("2");
}


void Process::Process3(WellData * pdata)
{
    pdata->well.at(0)->setText("3");
}



void Process::Process4(WellData * pdata)
{
    pdata->well.at(0)->setText("4");
}

