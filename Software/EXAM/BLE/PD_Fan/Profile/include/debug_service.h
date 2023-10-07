/**************************************************************************************************
 
  Phyplus Microelectronics Limited confidential and proprietary. 
  All rights reserved.

  IMPORTANT: All rights of this software belong to Phyplus Microelectronics 
  Limited ("Phyplus"). Your use of this Software is limited to those 
  specific rights granted under  the terms of the business contract, the 
  confidential agreement, the non-disclosure agreement and any other forms 
  of agreements as a customer or a partner of Phyplus. You may not use this 
  Software unless you agree to abide by the terms of these agreements. 
  You acknowledge that the Software may not be modified, copied, 
  distributed or disclosed unless embedded on a Phyplus Bluetooth Low Energy 
  (BLE) integrated circuit, either as a product or is integrated into your 
  products.  Other than for the aforementioned purposes, you may not use, 
  reproduce, copy, prepare derivative works of, modify, distribute, perform, 
  display or sell this Software and/or its documentation for any purposes.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  PHYPLUS OR ITS SUBSIDIARIES BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
  
**************************************************************************************************/


/**************************************************************************************************
  Filename:       simpleGATTprofile.h
  Revised:         
  Revision:        

  Description:    This file contains the Simple GATT profile definitions and
                  prototypes.

 **************************************************************************************************/

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

