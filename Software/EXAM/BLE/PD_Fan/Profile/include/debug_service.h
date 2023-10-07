#ifndef _BATT_AIR_DEBUG_SERVICE_H
#define _BATT_AIR_DEBUG_SERVICE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stdint.h"
#include "stdio.h"
#include "stdarg.h"
#include "stdbool.h"
#include "CONFIG.h"


#define DEBUG_BUFF_SIZE                     200

#define PROFILE_BAD_UUID                    0xDB00
#define PROFILE_BAD1_UUID                   0xDB01

typedef void (*Debug_Write_CB)(uint16_t uuid,uint8_t *data,uint16_t len);
typedef void (*Debug_Read_CB)(uint16_t uuid,uint8_t *data,uint16_t *len);

typedef struct
{
  Debug_Write_CB        pWrite;
  Debug_Read_CB         pRead;
} Debug_ProfileCBs_t;





bStatus_t Debug_AddService(Debug_ProfileCBs_t *cbs);
bStatus_t Debug_Notify_LowLevel( uint16_t connHandle, attHandleValueNoti_t *pNoti);
void Debug_Notify(uint16_t connHandle,uint8_t *buffer, uint8_t len);
void Debug_Print(uint16_t connHandle,char * _Format,...);

// #define Debug_Print(fmt, ...)     do {\
//     char Buf[DEBUG_BUFF_SIZE] = {0}; \
//     uint8_t len = 0;\
//     len = snprintf(Buf,DEBUG_BUFF_SIZE,""fmt"", ##__VA_ARGS__);\
//     Debug_Notify((char *)Buf,len);} while(0)
/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _BLE_UART_SERVICE_H */

