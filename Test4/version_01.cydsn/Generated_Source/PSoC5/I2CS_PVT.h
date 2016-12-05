/*******************************************************************************
* File Name: .h
* Version 2.0
*
* Description:
*  This file provides private constants and parameter values for the EZI2C
*  component.
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_EZI2C_PVT_I2CS_H)
#define CY_EZI2C_PVT_I2CS_H

#include "I2CS.h"


/***************************************
*     Vars with External Linkage
***************************************/

extern I2CS_BACKUP_STRUCT  I2CS_backup;

/* Status and state variables */
extern volatile uint8 I2CS_curStatus;
extern volatile uint8 I2CS_curState;

/* Primary slave address variables */
extern volatile uint8* I2CS_dataPtrS1;
extern volatile uint16 I2CS_bufSizeS1;
extern volatile uint16 I2CS_wrProtectS1;
extern volatile uint8 I2CS_rwOffsetS1;
extern volatile uint8 I2CS_rwIndexS1;

/* Secondary slave address variables */
#if (I2CS_ADDRESSES == I2CS_TWO_ADDRESSES)
    extern volatile uint8  I2CS_addrS1;
    extern volatile uint8  I2CS_addrS2;
    extern volatile uint8* I2CS_dataPtrS2;
    extern volatile uint16 I2CS_bufSizeS2;
    extern volatile uint16 I2CS_wrProtectS2;
    extern volatile uint8 I2CS_rwOffsetS2;
    extern volatile uint8 I2CS_rwIndexS2;
#endif  /* (I2CS_ADDRESSES == I2CS_TWO_ADDRESSES) */

#if (I2CS_WAKEUP_ENABLED)
    extern volatile uint8 I2CS_wakeupSource;
#endif /* (I2CS_WAKEUP_ENABLED) */

#endif /* CY_EZI2C_PVT_I2CS_H */


/* [] END OF FILE */
