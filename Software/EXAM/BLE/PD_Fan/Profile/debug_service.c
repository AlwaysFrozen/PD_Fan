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
  Filename:       simpleGATTprofile_ota.c
  Revised:         
  Revision:       

  Description:    This file contains the Simple GATT profile sample GATT service 
                  profile for use with the BLE sample application.

 
**************************************************************************************************/

/*********************************************************************
 * INCLUDES
 */
#include "debug_service.h"
/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * CONSTANTS
 */


#define Debug_CHAR1_VALUE_POS            2
/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * GLOBAL VARIABLES
 */


/*********************************************************************
 * EXTERNAL VARIABLES
 */

/*********************************************************************
 * EXTERNAL FUNCTIONS
 */

/*********************************************************************
 * LOCAL VARIABLES
 */

static Debug_ProfileCBs_t *Debug_AppCBs = NULL;
/*********************************************************************
 * Profile Attributes - variables
 */
// Rawpass GATT Profile Service UUID
const uint8_t Debug_ServiceUUID[ATT_BT_UUID_SIZE] =
{LO_UINT16(PROFILE_BAD_UUID), HI_UINT16(PROFILE_BAD_UUID)};

// Characteristic 1 uuid
const uint8_t Debug_UUID1[ATT_BT_UUID_SIZE] =
{LO_UINT16(PROFILE_BAD1_UUID), HI_UINT16(PROFILE_BAD1_UUID)};

// Profile Service attribute
static const gattAttrType_t Debug_Service = { ATT_BT_UUID_SIZE, Debug_ServiceUUID };


// Profile Characteristic 1 Properties
static uint8_t Debug_Props1 = GATT_PROP_READ | GATT_PROP_WRITE | GATT_PROP_NOTIFY;  

// Characteristic 1 Value
static uint8_t Debug_Value1[DEBUG_BUFF_SIZE] = {0};

// Simple Profile Characteristic 4 User Description
static gattCharCfg_t Debug_TxCCCD1[GATT_MAX_NUM_CONN];

/*********************************************************************
 * Profile Attributes - Table
 */

static gattAttribute_t Debug_ProfileAttrTbl[] = 
{
  // Simple Profile Service
  { 
    { ATT_BT_UUID_SIZE, primaryServiceUUID }, /* type */
    GATT_PERMIT_READ,                         /* permissions */
    0,                                        /* handle */
    (uint8_t *)&Debug_Service            /* pValue */
  },

    // Characteristic 1 Declaration
    { 
      { ATT_BT_UUID_SIZE, characterUUID },
      GATT_PERMIT_READ, 
      0,
      &Debug_Props1 
    },

    // Characteristic Value 1
    { 
      { ATT_BT_UUID_SIZE, Debug_UUID1 },
      GATT_PERMIT_READ | GATT_PERMIT_WRITE, 
      0, 
      Debug_Value1
    },


    // Characteristic 6 User Description
    { 
      { ATT_BT_UUID_SIZE, clientCharCfgUUID },
      GATT_PERMIT_READ|GATT_PERMIT_WRITE, 
      0, 
      (uint8_t*)Debug_TxCCCD1 
    },      

};


/*********************************************************************
 * LOCAL FUNCTIONS
 */
static bStatus_t Debug_ReadAttrCB( uint16_t connHandle, gattAttribute_t *pAttr, 
                            uint8_t *pValue, uint16_t *pLen, uint16_t offset, uint16_t maxLen,uint8_t method );
static bStatus_t Debug_WriteAttrCB( uint16_t connHandle, gattAttribute_t *pAttr,
                                 uint8_t *pValue, uint16_t len, uint16_t offset ,uint8_t method);

static void Debug_HandleConnStatusCB ( uint16_t connHandle, uint8_t changeType );


/*********************************************************************
 * PROFILE CALLBACKS
 */
// Simple Profile Service Callbacks
gattServiceCBs_t Debug_ProfileCBs =
{
  Debug_ReadAttrCB,  // Read callback function pointer
  Debug_WriteAttrCB, // Write callback function pointer
  NULL                       // Authorization callback function pointer
};

/*********************************************************************
 * PUBLIC FUNCTIONS
 */

/*********************************************************************
 * @fn      Debug_AddService
 *
 * @brief   Initializes the Simple Profile service by registering
 *          GATT attributes with the GATT server.
 *
 * @param   services - services to add. This is a bit map and can
 *                     contain more than one service.
 *
 * @return  Success or Failure
 */
bStatus_t Debug_AddService(Debug_ProfileCBs_t *cbs)
{
	PRINT("Debug_AddService \n");
  uint8_t status = SUCCESS;

  // Initialize Client Characteristic Configuration attributes
  GATTServApp_InitCharCfg( INVALID_CONNHANDLE, Debug_TxCCCD1 );

  // Register with Link DB to receive link status change callback
  linkDB_Register( Debug_HandleConnStatusCB  );  
  
    
  // Register GATT attribute list and CBs with GATT Server App
  status = GATTServApp_RegisterService( Debug_ProfileAttrTbl, 
                                        GATT_NUM_ATTRS( Debug_ProfileAttrTbl ),
                                        GATT_MAX_ENCRYPT_KEY_SIZE,
                                        &Debug_ProfileCBs );

  if(cbs != NULL)
  {
    PRINT("Debug_AddService Register\n");
    Debug_AppCBs = cbs;
  }

  return ( status );
}

/*********************************************************************
 * @fn          Debug_ReadAttrCB
 *
 * @brief       Read an attribute.
 *
 * @param       connHandle - connection message was received on
 * @param       pAttr - pointer to attribute
 * @param       pValue - pointer to data to be read
 * @param       pLen - length of data to be read
 * @param       offset - offset of the first octet to be read
 * @param       maxLen - maximum length of data to be read
 *
 * @return      Success or Failure
 */
static bStatus_t Debug_ReadAttrCB( uint16_t connHandle, gattAttribute_t *pAttr, 
                            uint8_t *pValue, uint16_t *pLen, uint16_t offset, uint16_t maxLen,uint8_t method )
{
    bStatus_t status = SUCCESS;
    // If attribute permissions require authorization to read, return error
    if ( gattPermitAuthorRead( pAttr->permissions ) )
    {
        // Insufficient authorization
        return ( ATT_ERR_INSUFFICIENT_AUTHOR );
    }
    
    if ( offset > 0 )
    {
        return ( ATT_ERR_ATTR_NOT_LONG );
    }

    if ( pAttr->type.len == ATT_BT_UUID_SIZE )
    {
        // 16-bit UUID
        uint16_t uuid = BUILD_UINT16( pAttr->type.uuid[0], pAttr->type.uuid[1]);
        
        switch ( uuid )
        {
          case GATT_CLIENT_CHAR_CFG_UUID:
            *pLen = 2;
            tmos_memcpy(pValue, pAttr->pValue, 2);
            break;

          case PROFILE_BAD1_UUID:
            Debug_AppCBs->pRead(uuid,pAttr->pValue,pLen);
            tmos_memcpy(pValue, pAttr->pValue, *pLen);
            break;

          default:
            // Should never get here!
            *pLen = 0;
            status = ATT_ERR_ATTR_NOT_FOUND;
            break;
        }
    }
    else
    {
        *pLen = 0;
        status = ATT_ERR_INVALID_HANDLE;
    }

    return ( status );
}

/*********************************************************************
 * @fn      Debug_WriteAttrCB
 *
 * @brief   Validate attribute data prior to a write operation
 *
 * @param   connHandle - connection message was received on
 * @param   pAttr - pointer to attribute
 * @param   pValue - pointer to data to be written
 * @param   len - length of data
 * @param   offset - offset of the first octet to be written
 *
 * @return  Success or Failure
 */
static bStatus_t Debug_WriteAttrCB( uint16_t connHandle, gattAttribute_t *pAttr,
                                 uint8_t *pValue, uint16_t len, uint16_t offset ,uint8_t method)
{
    bStatus_t status = SUCCESS;
    // If attribute permissions require authorization to write, return error
    if ( gattPermitAuthorWrite( pAttr->permissions ) )
    {
        // Insufficient authorization
        return ( ATT_ERR_INSUFFICIENT_AUTHOR );
    }
  
    if ( pAttr->type.len == ATT_BT_UUID_SIZE )
    {
        // 16-bit UUID
        uint16_t uuid = BUILD_UINT16( pAttr->type.uuid[0], pAttr->type.uuid[1]);
        
        switch ( uuid )
        {
          case GATT_CLIENT_CHAR_CFG_UUID:
            status = GATTServApp_ProcessCCCWriteReq( connHandle, pAttr, pValue, len,
                                                   offset, GATT_CLIENT_CFG_NOTIFY );
            break;

          case PROFILE_BAD1_UUID:
              Debug_AppCBs->pWrite(uuid,pValue,len);
              break;
          
          default:
            // Should never get here!
            status = ATT_ERR_ATTR_NOT_FOUND;
            break;
        }
    }
    else
    {
      // 128-bit UUID
      status = ATT_ERR_INVALID_HANDLE;
    }
    return ( status );
}

/*********************************************************************
 * @fn          Debug_HandleConnStatusCB
 *
 * @brief       Simple Profile link status change handler function.
 *
 * @param       connHandle - connection handle
 * @param       changeType - type of change
 *
 * @return      none
 */
static void Debug_HandleConnStatusCB ( uint16_t connHandle, uint8_t changeType )
{ 
    // Make sure this is not loopback connection
    if ( connHandle != LOOPBACK_CONNHANDLE )
    {
        // Reset Client Char Config if connection has dropped
        if ( ( changeType == LINKDB_STATUS_UPDATE_REMOVED )      ||
                ( ( changeType == LINKDB_STATUS_UPDATE_STATEFLAGS ) && 
                ( !linkDB_Up( connHandle ) ) ) )
        { 
            GATTServApp_InitCharCfg( INVALID_CONNHANDLE, Debug_TxCCCD1 );
            PRINT("clear client configuration\n");
        }
    }
}

bStatus_t Debug_Notify_LowLevel( uint16_t connHandle, attHandleValueNoti_t *pNoti)
{
  uint16_t value = GATTServApp_ReadCharCfg( connHandle, Debug_TxCCCD1 );
  // If notifications enabled
  if ( value & GATT_CLIENT_CFG_NOTIFY )
  {
    // Set the handle
    pNoti->handle = Debug_ProfileAttrTbl[Debug_CHAR1_VALUE_POS].handle;

    // Send the Indication
    return GATT_Notification( connHandle, pNoti, FALSE);
  }
  return bleIncorrectMode;
}

void Debug_Notify(uint16_t connHandle,uint8_t *buffer, uint8_t len)
{
	uint8_t flg = 0 ;
	attHandleValueNoti_t notify_data={0};
	notify_data.pValue = GATT_bm_alloc( connHandle, ATT_HANDLE_VALUE_NOTI, len, NULL, 0 );
	tmos_memcpy(notify_data.pValue,buffer,len);
	notify_data.len = len;
	flg = Debug_Notify_LowLevel(connHandle, &notify_data);
	if(flg != SUCCESS)
	{
		GATT_bm_free( (gattMsg_t *)&notify_data, ATT_HANDLE_VALUE_NOTI );
	}
}

void Debug_Print(uint16_t connHandle,char * _Format,...)
{
  char buffer[BLE_BUFF_MAX_LEN] = {0};
  uint8_t len = 0;
  uint8_t mtu = 0;

  mtu = ATT_GetMTU(connHandle) - 3;

  va_list list;
  va_start(list,_Format);
  len = vsprintf(buffer,_Format,list);
  va_end(list);
  if(len > mtu)
  {
    len = mtu;
  }

  Debug_Notify(connHandle,buffer,len);
}
