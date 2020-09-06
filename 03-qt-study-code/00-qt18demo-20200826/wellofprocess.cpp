#include "wellofprocess.h"
#include <QElapsedTimer>
#include <QTime>
#include <QCoreApplication>
#include "changesyncstatus.h"
#include <QMetaType>


enum PanType{
    GrayP = 0, Green30 = 1, Green60 = 2, Green100 = 3, Red100 = 4
};

enum SwitchType{
    GrayClose = 0, GreenOpen = 1, RedClose = 2
};


enum LightType{
    GrayL = 0,  Green = 1, Yellow = 2, Red = 3
};


QString WellOfProcess::getTimeNowMDHMS(){

    QDateTime time= QDateTime::currentDateTime();
    QString date=time.toString("MM-dd hh:mm:ss");

    return date;
}

QString WellOfProcess::getTimeNowHMS(){

    QDateTime time= QDateTime::currentDateTime();
    QString date=time.toString(" hh:mm:ss");

    return date;
}





WellOfProcess::WellOfProcess()
{
    qRegisterMetaType < QVector<int> >("QVector<int>");
}

void WellOfProcess::MySleep(double sec)
{
    int msec = sec * 1000;
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void WellOfProcess::Process1(WellsData wellData)
{
        m_ChangeStatus.ChangeTable(wellData, "title", 0, 0, "阵地编号：" + wellData.m_WellNum,QColor(0, 0, 0));


        wellData.m_LabelOfWell_22.at(1)->setText("集控(主机)");


        m_ChangeStatus.ChangeBulb(wellData,"D-15", Green);
        wellData.m_DetailLabelOfWell_04.at(3)->setText("：指令启动未定");
        // D 29
        m_ChangeStatus.ChangeBulb(wellData,"D-29", Yellow);
        wellData.m_DetailLabelOfWell_09.at(3)->setText("闭锁");


        MySleep(2);
        // D 9
        m_ChangeStatus.ChangeBulb(wellData,"D-9", Green);
        wellData.m_DetailLabelOfWell_02.at(3)->setText("：自检正常");
        wellData.m_DetailLabelOfWell_02.at(5)->setText("：主链路工作");
        // D 18
        m_ChangeStatus.ChangeBulb(wellData,"D-18", Yellow);
        wellData.m_DetailLabelOfWell_05.at(3)->setText("：正常");
        wellData.m_DetailLabelOfWell_05.at(5)->setText("：未建立");


        MySleep(2);

        // D 12
        m_ChangeStatus.ChangeBulb(wellData,"D-12", Green);

        wellData.m_DetailLabelOfWell_03.at(3)->setText("：自检正常");
        wellData.m_DetailLabelOfWell_03.at(5)->setText("：主链路工作");

        // D 30
        m_ChangeStatus.ChangeBulb(wellData,"D-30", RedClose);
        wellData.m_DetailLabelOfWell_10.at(3)->setText("：闭锁");


        // D 21
        m_ChangeStatus.ChangeBulb(wellData,"D-21", Yellow);
        wellData.m_DetailLabelOfWell_06.at(3)->setText("：0");
        wellData.m_DetailLabelOfWell_06.at(5)->setText("：正常");
        wellData.m_DetailLabelOfWell_06.at(7)->setText("：未建立");



        MySleep(1);     // D 25    -------------------------------------------------------------------    D-25 不变黄
        // m_ChangeStatus.ChangeBulb(wellData,"D-25", Yellow);

        wellData.m_DetailLabelOfWell_07.at(3)->setText("：0");
        wellData.m_DetailLabelOfWell_07.at(5)->setText("：未建立");


        MySleep(5);     //D 1

        m_ChangeStatus.ChangeBulb(wellData,"D-1", Yellow);
        wellData.m_DetailLabelOfWell_01.at(3)->setText("：心跳正常(当班)");
        wellData.m_DetailLabelOfWell_01.at(5)->setText("：自检正常");

        // D 28
        m_ChangeStatus.ChangeBulb(wellData,"D-28", Red100);
        wellData.m_DetailLabelOfWell_08.at(3)->setText("：未验证");
}

void WellOfProcess::Process2(WellsData wellData)
{
    // 修改 title 第3个单元
       m_ChangeStatus.ChangeTable(wellData, "title", 0, 2, "热戒备",QColor(255, 170, 0));
       wellData.m_DetailTableOfWell_2.at(0)->item(0,2)->setText("进入热戒备");
       wellData.m_DetailLabelOfWell_00.at(4)->setText("发送热戒备指令成功");


       MySleep(0.5);

       wellData.m_DetailLabelOfWell_00.at(4)->setText("发送可行通道建立许可指令成功");

       MySleep(2.5);     //D 18
       m_ChangeStatus.ChangeBulb(wellData,"D-18", Green);
       wellData.m_DetailLabelOfWell_05.at(5)->setText("：已建立");

       // D 21
       m_ChangeStatus.ChangeBulb(wellData,"D-21", Green);

       wellData.m_DetailLabelOfWell_06.at(7)->setText("：已建立");

       MySleep(1);      // D 1

       m_ChangeStatus.ChangeBulb(wellData,"D-1", Green);


       MySleep(0.5);
       wellData.m_DetailLabelOfWell_00.at(4)->setText("收到可行通道建立结果");
}

void WellOfProcess::Process3(WellsData wellData)
{
    if(0 == wellData.m_Pattern){
         wellData.m_DetailTextLineOfWell_3.at(2)->setText("下达完成");
         wellData.m_DetailTextLineOfWell_3.at(0)->setText("1");
     }else{
         wellData.m_DetailTextLineOfWell_3.at(2)->setText("下达完成");
         wellData.m_DetailTextLineOfWell_3.at(0)->setText("1");
         wellData.m_DetailTextLineOfWell_3.at(1)->setText("1");
     }
     wellData.m_DetailLabelOfWell_00.at(4)->setText("发送体诸元数据完成");
     MySleep(0.1);

     wellData.m_DetailLabelOfWell_00.at(4)->setText("收到体诸元接受结果");



     if(0 == wellData.m_Pattern){
         wellData.m_DetailLabelOfWell_01.at(9)->setText("：模飞诸元接受正确");
     }else{
         wellData.m_DetailLabelOfWell_01.at(9)->setText("：作战诸元接受正确");
     }
     MySleep(5);
     // D 28
     m_ChangeStatus.ChangeBulb(wellData,"D-28", Green30);

     wellData.m_DetailLabelOfWell_08.at(3)->setText("：诸元验证量计算成功");

}

void WellOfProcess::Process4(WellsData wellData)
{
   //  SendUDPString("Process4 Start");   20200812

       // 修改 title 第3个单元  -----------------------------------------------第4步  进入发射，和测试  作战无关

       m_ChangeStatus.ChangeTable(wellData, "title", 0, 2, "发射",QColor(255, 170, 0));


       wellData.m_DetailTableOfWell_2.at(1)->setItem(3,2,new QTableWidgetItem("  " + getTimeNowMDHMS())); // 7-09 19:
       wellData.m_DetailTableOfWell_2.at(1)->setItem(4,1,new QTableWidgetItem(" 下达成功 " + getTimeNowHMS()));
       wellData.m_DetailTableOfWell_2.at(1)->setItem(4,2,new QTableWidgetItem(" 下达成功 " + getTimeNowHMS()));
       wellData.m_DetailTableOfWell_2.at(1)->setItem(4,3,new QTableWidgetItem(" 下达成功 "+ getTimeNowHMS()));


       wellData.m_TableOfWell_2.at(1)->setItem(2,1,new QTableWidgetItem(" 下达成功 "));
       wellData.m_TableOfWell_2.at(1)->setItem(2,2,new QTableWidgetItem(" 下达成功 "));
       wellData.m_TableOfWell_2.at(1)->setItem(2,3,new QTableWidgetItem(" 下达成功 "));


       MySleep(0.7);

       wellData.m_DetailTableOfWell_2.at(1)->setItem(5,1,new QTableWidgetItem(" 通过 " + getTimeNowHMS()));
       wellData.m_DetailTableOfWell_2.at(1)->setItem(5,2,new QTableWidgetItem(" 通过 " + getTimeNowHMS()));
       wellData.m_DetailTableOfWell_2.at(1)->setItem(5,3,new QTableWidgetItem(" 通过 " + getTimeNowHMS()));



       if(0 == wellData.m_Pattern){
           wellData.m_DetailLabelOfWell_01.at(11)->setText("：测试授权指令验证正确");
           wellData.m_DetailLabelOfWell_01.at(13)->setText("：测试授权指令验证正确");
           wellData.m_DetailLabelOfWell_01.at(15)->setText("：测试授权指令验证正确");
       }else{
           wellData.m_DetailLabelOfWell_01.at(11)->setText("：作战授权指令验证正确");
           wellData.m_DetailLabelOfWell_01.at(13)->setText("：作战授权指令验证正确");
           wellData.m_DetailLabelOfWell_01.at(15)->setText("：作战授权指令验证正确");
       }

       if(0 == wellData.m_Pattern)
           wellData.m_DetailLabelOfWell_00.at(0)->setText("授权指令成功(测试)");
       else
           wellData.m_DetailLabelOfWell_00.at(0)->setText("授权指令成功(作战)");

       wellData.m_LabelOfWell_22.at(8)->setText("授权指令");


       MySleep(3);
       // D 28

       m_ChangeStatus.ChangeBulb(wellData,"D-28", Green60);

       wellData.m_DetailLabelOfWell_08.at(3)->setText("：诸元验证成功");

       MySleep(2);
       // D 25

       m_ChangeStatus.ChangeBulb(wellData,"D-25", Green);

       wellData.m_DetailLabelOfWell_07.at(3)->setText("：11121");
       wellData.m_DetailLabelOfWell_07.at(5)->setText("：已建立");

       MySleep(1);



       // D 28

       m_ChangeStatus.ChangeBulb(wellData,"D-28", Green100);

       wellData.m_DetailLabelOfWell_08.at(3)->setText("：弹上下传诸元验证通过");

       // D 29
       if(0 == wellData.m_Pattern)
           wellData.m_DetailLabelOfWell_09.at(3)->setText("：指令执行正确(测试)");
       else
           wellData.m_DetailLabelOfWell_09.at(3)->setText("：指令执行正确(作战)");

       MySleep(0.5);

       // D 29

       m_ChangeStatus.ChangeBulb(wellData,"D-29", GreenOpen);

       wellData.m_DetailLabelOfWell_09.at(3)->setText("：开锁");

       MySleep(1);
       // D 29  -----------------------------------------------------------------------------------开锁后  不用闭锁
       //    m_ChangeStatus.ChangeBulb(wellData,"D-29", RedClose);
       //    wellData.m_DetailLabelOfWell_09.at(3)->setText("闭锁");

       if(0 == wellData.m_Pattern)
       {

           wellData.m_LabelOfWell_22.at(8)->setText("授权成功(测试)");


       }
       else{

           wellData.m_LabelOfWell_22.at(8)->setText("授权成功(作战)");

       }

       wellData.m_DetailTableOfWell_2.at(1)->setItem(6,2,new QTableWidgetItem(" 下达成功 " + getTimeNowHMS()));

       MySleep(2);
       // D 30

       m_ChangeStatus.ChangeBulb(wellData,"D-30", GreenOpen);

       wellData.m_DetailLabelOfWell_10.at(3)->setText("：开锁");

       MySleep(1);
       // D 30   -----------------------------------------------------------------------------------开锁后  不用闭锁
       //    m_ChangeStatus.ChangeBulb(wellData,"D-30", RedClose);
       //    wellData.m_DetailLabelOfWell_10.at(3)->setText("闭锁");
       wellData.m_DetailTableOfWell_2.at(1)->setItem(6,1,new QTableWidgetItem(" 下达成功 " + getTimeNowHMS()));

     //    m_aixLabel->setText("发送HAK准备好消息");    20200812
}
