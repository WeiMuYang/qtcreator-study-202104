/*******************************************************************************
Copyright (c) 1983-2016 Advantech Co., Ltd.
********************************************************************************
THIS IS AN UNPUBLISHED WORK CONTAINING CONFIDENTIAL AND PROPRIETARY INFORMATION
WHICH IS THE PROPERTY OF ADVANTECH CORP., ANY DISCLOSURE, USE, OR REPRODUCTION,
WITHOUT WRITTEN AUTHORIZATION FROM ADVANTECH CORP., IS STRICTLY PROHIBITED.

================================================================================
REVISION HISTORY
--------------------------------------------------------------------------------
$Log:  $

--------------------------------------------------------------------------------
$NoKeywords:  $
*/

/******************************************************************************
*
* Windows Example:
*    StaticDO.cpp
*
* Example Category:
*    DIO
*
* Description:
*    This example demonstrates how to use Static DO function.
*
* Instructions for Running:
*    1. Set the 'deviceDescription' for opening the device.
*	 2. Set the 'profilePath' to save the profile path of being initialized device.
*    3. Set the 'startPort'as the first port for Do .
*    4. Set the 'portCount'to decide how many sequential ports to operate Do.
*
* I/O Connections Overview:
*    Please refer to your hardware reference manual.
*
******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <QTime>
#include <QCoreApplication>
#include "compatibility.h"
#include "bdaqctrl.h"
using namespace Automation::BDaq;
//-----------------------------------------------------------------------------------
// Configure the following parameters before running the demo
//-----------------------------------------------------------------------------------
typedef unsigned char byte;

#define  deviceDescription  L"USB-5830,BID#0"
const wchar_t* profilePath = L"";
int32    startPort = 0;
int32    portCount = 1;

inline void waitAnyKey()
{
    do{SLEEP(1);} while(!kbhit());
}

void MySleep(double sec){ // 延迟sec秒
    int msec = sec * 1000;
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

int main(int argc, char* argv[])
{
    ErrorCode        ret = Success;
    // Step 1: Create a instantDoCtrl for DO function.
    InstantDoCtrl * instantDoCtrl = InstantDoCtrl::Create();
    // Step 2: Select a device by device number or device description and specify the access mode.
    // in this example we use ModeWrite mode so that we can fully control the device, including configuring, sampling, etc.
    DeviceInformation devInfo(deviceDescription);
    do{  // 因为CHK_RESULT(ret);中包含break，所以必须放在循环中
        ret = instantDoCtrl->setSelectedDevice(devInfo);
        CHK_RESULT(ret);
        ret = instantDoCtrl->LoadProfile(profilePath);//Loads a profile to initialize the device.
        CHK_RESULT(ret);


        byte  bufferForWriting[64] = {0};//the first element is used for start port
        uint32 inputVal = 0;

        bufferForWriting[0] = (byte)inputVal;
//        ret = instantDoCtrl->Write(0, 0, bufferForWriting );  // 第0行等都灭
//        ret = instantDoCtrl->Write(1, 0, bufferForWriting );  // 第1行等都灭
        for(int i = 0; i < 8; ++i){
            ret = instantDoCtrl->WriteBit(startPort, (byte)i, 0);  // 第一行
            ret = instantDoCtrl->WriteBit(1, (byte)i, 0);          // 第二行
        }



        // Step 3: Write DO ports
        uint32 data = 0;//the data is used to the 'WriteBit';
        int bit = 1;//the bit is used to the 'WriteBit';

        for(int i = 0; i < 10; ++i){
            ret = instantDoCtrl->WriteBit(startPort, 0x02, 1);
            MySleep(0.8);
            ret = instantDoCtrl->WriteBit(startPort, 0x02, 0);
            MySleep(0.8);
            ret = instantDoCtrl->WriteBit(startPort, 0x02, 1);
            MySleep(0.8);
        }

        CHK_RESULT(ret);
        printf("\n DO output completed !");

    }while(false);
    // Step 4: Close device and release any allocated resource.
    instantDoCtrl->Dispose();

    // If something wrong in this execution, print the error code on screen for tracking.
    if(BioFailed(ret))
    {
        wchar_t enumString[256];
        AdxEnumToString(L"ErrorCode", (int32)ret, 256, enumString);
        printf("Some error occurred. And the last error code is 0x%X. [%ls]\n", ret, enumString);
    }
    // waitAnyKey();
    return 0;
}
