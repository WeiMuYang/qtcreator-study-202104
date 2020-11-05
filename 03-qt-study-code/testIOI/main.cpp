#include <QCoreApplication>

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
*    StaticDI.cpp
*
* Example Category:
*    DIO
*
* Description:
*    This example demonstrates how to use Static DI function.
*
* Instructions for Running:
*    1. Set the 'deviceDescription' for opening the device.
*	 2. Set the 'profilePath' to save the profile path of being initialized device.
*    3. Set the 'startPort' as the first port for Di scanning.
*    4. Set the 'portCount' to decide how many sequential ports to operate Di scanning.
*
* I/O Connections Overview:
*    Please refer to your hardware reference manual.
*
******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bdaqctrl.h"
#include "compatibility.h"
using namespace Automation::BDaq;
//-----------------------------------------------------------------------------------
// Configure the following parameters before running the demo
//-----------------------------------------------------------------------------------
typedef unsigned char byte;
#define  deviceDescription  L"USB-5830,BID#0"
const wchar_t* profilePath = L"";
int32    startPort = 1;
int32    portCount = 1;

inline void waitAnyKey()
{
    do{SLEEP(1);} while(!kbhit());
}

int main(int argc, char* argv[])
{
    ErrorCode        ret = Success;
    // Step 1: Create a 'InstantDiCtrl' for DI function.
    InstantDiCtrl * instantDiCtrl = InstantDiCtrl::Create();
    do
    {
        // Step 2: select a device by device number or device description and specify the access mode.
        // in this example we use ModeWrite mode so that we can fully control the device, including configuring, sampling, etc.
        DeviceInformation devInfo(deviceDescription);
        ret = instantDiCtrl->setSelectedDevice(devInfo);
        CHK_RESULT(ret);
        ret = instantDiCtrl->LoadProfile(profilePath);//Loads a profile to initialize the device.
        CHK_RESULT(ret);
        uint8 data = 0;//data is used to the 'ReadBit'.
        do{
            for(int i = 0; i < 8; ++i){
                // 第startPort端口号的第bit个灯是data的状态
                ret = instantDiCtrl->ReadBit(startPort, i, &data);
                CHK_RESULT(ret);
                if(data == 0x01)
                    printf("DI row: %d   bit:%d    value: 0x%X\n\n", startPort, i, data);// for 'ReadBit'
            }
            SLEEP(0.5);
        }while(!kbhit());
    }while(false);

    // Step 4: Close device and release any allocated resource.
    instantDiCtrl->Dispose();

    // If something wrong in this execution, print the error code on screen for tracking.
    if(BioFailed(ret))
    {
        wchar_t enumString[256];
        AdxEnumToString(L"ErrorCode", (int32)ret, 256, enumString);
        printf("Some error occurred. And the last error code is 0x%X. [%ls]\n", ret, enumString);
        waitAnyKey();
    }
    return 0;
}
