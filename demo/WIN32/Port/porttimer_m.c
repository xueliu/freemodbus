//
// Created by liu on 04.08.2020.
//

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mb_m.h"
#include "mbport.h"

/* ----------------------- Defines ------------------------------------------*/

/* ----------------------- Static variables ---------------------------------*/
DWORD           dwTimeOut;
BOOL            bTimeoutEnable;
DWORD           dwTimeLast;
extern HANDLE   g_hSerial;

/* ----------------------- Start implementation -----------------------------*/
BOOL
xMBMasterPortTimersInit( USHORT usTim1Timerout50us )
{
    dwTimeOut = usTim1Timerout50us / 20U;
    if( dwTimeOut == 0 )
        dwTimeOut = 1;

    return xMBPortSerialSetTimeout( dwTimeOut );
}

void
xMBMasterPortTimersClose(  )
{
    /* Does not use any hardware resources. */
}

void
vMBMasterPortTimerPoll(  )
{

    /* Timers are called from the serial layer because we have no high
     * res timer in Win32. */
    if( bTimeoutEnable )
    {
        DWORD           dwTimeCurrent = GetTickCount(  );

        if( ( dwTimeCurrent - dwTimeLast ) > dwTimeOut )
        {
            bTimeoutEnable = FALSE;
            ( void )pxMBPortCBTimerExpired(  );
        }
    }
}

void
vMBMasterPortTimersEnable(  )
{
    bTimeoutEnable = TRUE;
    dwTimeLast = GetTickCount(  );
}

void
vMBMasterPortTimersDisable(  )
{
    bTimeoutEnable = FALSE;
}