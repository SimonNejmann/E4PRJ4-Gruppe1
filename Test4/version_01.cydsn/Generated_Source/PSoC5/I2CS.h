/*******************************************************************************
* File Name: I2CS.h
* Version 2.0
*
* Description:
*  This is the header file for the EzI2C user module.  It contains function
*  prototypes and constants for the users convenience.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_EZI2C_I2CS_H)
#define CY_EZI2C_I2CS_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"

/* Check if required defines such as CY_PSOC5LP are available in cy_boot */
#if !defined (CY_PSOC5LP)
    #error Component EZI2C_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

/***************************************
*   Initial Parameter Constants
***************************************/

#define I2CS_DATA_RATE      (400u)
#define I2CS_BUS_PORT       (0u)
#define I2CS_ENABLE_WAKEUP  (0u)
#define I2CS_SUBADDR_WIDTH  (0u)
#define I2CS_ADDRESSES      (1u)
#define I2CS_DEFAULT_ADDR1  (8u)
#define I2CS_DEFAULT_ADDR2  (9u)


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define I2CS_WAKEUP_ENABLED (0u != I2CS_ENABLE_WAKEUP)

/* Number of addresses enum. */
#define I2CS_ONE_ADDRESS    (1u)
#define I2CS_TWO_ADDRESSES  (2u)

/* Sub-address size enum. */
#define I2CS_ANY   (0u)
#define I2CS_I2C0  (1u)
#define I2CS_I2C1  (2u)

/* Sub-address size enum. */
#define I2CS_SUBADDR_8BIT   (0u)
#define I2CS_SUBADDR_16BIT  (1u)


/***************************************
*       Type Definitions
***************************************/

/* Structure to store configuration before enter Sleep */
typedef struct
{
    uint8   enableState;
    uint8   xcfg;
    uint8   adr;
    uint8   cfg;
    uint8   clkDiv1;
    uint8   clkDiv2;

} I2CS_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void    I2CS_Init(void)     ;
void    I2CS_Enable(void)   ;
void    I2CS_Start(void)    ;
void    I2CS_Stop(void)     ;

#define I2CS_EnableInt()        CyIntEnable      (I2CS_ISR_NUMBER)
#define I2CS_DisableInt()       CyIntDisable     (I2CS_ISR_NUMBER)
#define I2CS_ClearPendingInt()  CyIntClearPending(I2CS_ISR_NUMBER)
#define I2CS_SetPendingInt()    CyIntSetPending  (I2CS_ISR_NUMBER)

void    I2CS_Sleep(void)            ;
void    I2CS_Wakeup(void)           ;
void    I2CS_SaveConfig(void)       ;
void    I2CS_RestoreConfig(void)    ;

uint8   I2CS_GetActivity(void)      ;

void    I2CS_SetBuffer1(uint16 bufSize, uint16 rwBoundary, volatile uint8 * dataPtr) ;
void    I2CS_SetAddress1(uint8 address) ;
uint8   I2CS_GetAddress1(void)          ;

#if (I2CS_ADDRESSES == I2CS_TWO_ADDRESSES)
    void    I2CS_SetBuffer2(uint16 bufSize, uint16 rwBoundary, volatile uint8 * dataPtr) ;
    void    I2CS_SetAddress2(uint8 address )    ;
    uint8   I2CS_GetAddress2(void)              ;
#endif /* (I2CS_ADDRESSES == I2CS_TWO_ADDRESSES) */

/* EZI2C interrupt handler */
CY_ISR_PROTO(I2CS_ISR);
#if (I2CS_WAKEUP_ENABLED)
    CY_ISR_PROTO(I2CS_WAKEUP_ISR);
#endif /* (I2CS_WAKEUP_ENABLED) */


/***************************************
*     Vars with External Linkage
***************************************/

extern uint8 I2CS_initVar;


/***************************************
*              API Constants
***************************************/

/* Status bit definition */
#define I2CS_STATUS_READ1   (0x01u) /* A read addr 1 operation occurred since last status check */
#define I2CS_STATUS_WRITE1  (0x02u) /* A Write addr 1 operation occurred since last status check */
#define I2CS_STATUS_READ2   (0x04u) /* A read addr 2 operation occurred since last status check */
#define I2CS_STATUS_WRITE2  (0x08u) /* A Write addr 2 operation occurred since last status check */
#define I2CS_STATUS_BUSY    (0x10u) /* A start has occurred, but a Stop has not been detected */
#define I2CS_STATUS_RD1BUSY (0x11u) /* Addr 1 read busy  */
#define I2CS_STATUS_WR1BUSY (0x12u) /* Addr 1 write busy */
#define I2CS_STATUS_RD2BUSY (0x14u) /* Addr 2 read busy  */
#define I2CS_STATUS_WR2BUSY (0x18u) /* Addr 2 write busy */
#define I2CS_STATUS_MASK    (0x1Fu) /* Mask for status bits */
#define I2CS_STATUS_ERR     (0x80u) /* An Error occurred since last read */

/* Data send to master in case of read overflow */
#define I2CS_DUMMY_DATA         (0xFFu)

/* Address shift */
#define I2CS_ADDRESS_SHIFT      (1u)
#define I2CS_ADDRESS_LSB_SHIFT  (8u)

/* Component state enum. */
#define I2CS_ENABLED            (0x01u)
#define I2CS_DISABLED           (0x00u)

/* Return 1 if corresponding bit is set, otherwise 0 */
#define I2CS_IS_BIT_SET(value, mask) (((mask) == ((value) & (mask))) ? (1u) : (0u))


/***************************************
*              Registers
***************************************/

/* I2C Extended Configuration Register */
#define I2CS_XCFG_REG       (*(reg8 *) I2CS_I2C_Prim__XCFG)
#define I2CS_XCFG_PTR       ( (reg8 *) I2CS_I2C_Prim__XCFG)

/* I2C Slave Address Register */
#define I2CS_ADDR_REG       (*(reg8 *) I2CS_I2C_Prim__ADR)
#define I2CS_ADDR_PTR       ( (reg8 *) I2CS_I2C_Prim__ADR)

/* I2C Configuration Register */
#define I2CS_CFG_REG        (*(reg8 *) I2CS_I2C_Prim__CFG)
#define I2CS_CFG_PTR        ( (reg8 *) I2CS_I2C_Prim__CFG)

/* I2C Control and Status Register */
#define I2CS_CSR_REG        (*(reg8 *) I2CS_I2C_Prim__CSR)
#define I2CS_CSR_PTR        ( (reg8 *) I2CS_I2C_Prim__CSR)

/* I2C Data Register */
#define I2CS_DATA_REG       (*(reg8 *) I2CS_I2C_Prim__D)
#define I2CS_DATA_PTR       ( (reg8 *) I2CS_I2C_Prim__D)

/*  8 LSB bits of the 10-bit Clock Divider */
#define I2CS_CLKDIV1_REG    (*(reg8 *) I2CS_I2C_Prim__CLK_DIV1)
#define I2CS_CLKDIV1_PTR    ( (reg8 *) I2CS_I2C_Prim__CLK_DIV1)

/* 2 MSB bits of the 10-bit Clock Divider */
#define I2CS_CLKDIV2_REG    (*(reg8 *) I2CS_I2C_Prim__CLK_DIV2)
#define I2CS_CLKDIV2_PTR    ( (reg8 *) I2CS_I2C_Prim__CLK_DIV2)

/* Power System Control Register 1 */
#define I2CS_PWRSYS_CR1_REG (*(reg8 *) CYREG_PWRSYS_CR1)
#define I2CS_PWRSYS_CR1_PTR ( (reg8 *) CYREG_PWRSYS_CR1)

/* I2C operation in Active Mode */
#define I2CS_PM_ACT_CFG_REG (*(reg8 *) I2CS_I2C_Prim__PM_ACT_CFG)
#define I2CS_PM_ACT_CFG_PTR ( (reg8 *) I2CS_I2C_Prim__PM_ACT_CFG)
#define I2CS_ACT_PWR_EN     ( (uint8)  I2CS_I2C_Prim__PM_ACT_MSK)

/* I2C operation in Alternate Active (Standby) Mode */
#define I2CS_PM_STBY_CFG_REG    (*(reg8 *) I2CS_I2C_Prim__PM_STBY_CFG)
#define I2CS_PM_STBY_CFG_PTR    ( (reg8 *) I2CS_I2C_Prim__PM_STBY_CFG)
#define I2CS_STBY_PWR_EN        ( (uint8)  I2CS_I2C_Prim__PM_STBY_MSK)


/***************************************
*       Register Constants
***************************************/

/* I2C backup regulator */
#define I2CS_PWRSYS_CR1_I2C_BACKUP  (0x04u)

/* Interrupt number and priority */
#define I2CS_ISR_NUMBER         (I2CS_isr__INTC_NUMBER)
#define I2CS_ISR_PRIORITY       (I2CS_isr__INTC_PRIOR_NUM)

/* Block reset constants */
#define I2CS_CLEAR_REG          (0x00u)
#define I2CS_BLOCK_RESET_DELAY  (2u)

/* XCFG I2C Extended Configuration Register */
#define I2CS_XCFG_CLK_EN        (0x80u) /* Clock enable */
#define I2CS_XCFG_I2C_ON        (0x40u) /* Set before entering sleep mode */
#define I2CS_XCFG_SLEEP_READY   (0x20u) /* Ready to sleep */
#define I2CS_XCFG_FORCE_NACK    (0x10u) /* Force nack */
#define I2CS_XCFG_HDWR_ADDR_EN  (0x01u) /* Hardware address comparison */

/* Data I2C Slave Data Register */
#define I2CS_SADDR_MASK         (0x7Fu)
#define I2CS_DATA_MASK          (0xFFu)
#define I2CS_READ_FLAG          (0x01u)

/* CFG I2C Configuration Register */
#define I2CS_CFG_SIO_SELECT    (0x80u) /* Pin Select for SCL/SDA lines */
#define I2CS_CFG_PSELECT       (0x40u) /* Pin Select */
#define I2CS_CFG_BUS_ERR_IE    (0x20u) /* Bus Error Interrupt Enable */
#define I2CS_CFG_STOP_ERR_IE   (0x10u) /* Enable Interrupt on STOP condition */
#define I2CS_CFG_STOP_IE       (0x10u) /* Enable Interrupt on STOP condition */
#define I2CS_CFG_CLK_RATE      (0x04u) /* Clock rate mask. 1 for 50K, 0 for 100K and 400K */
#define I2CS_CFG_EN_SLAVE      (0x01u) /* Enable Slave operation */

/* CSR I2C Control and Status Register */
#define I2CS_CSR_BUS_ERROR     (0x80u) /* Active high when bus error has occurred */
#define I2CS_CSR_LOST_ARB      (0x40u) /* Set to 1 if lost arbitration in host mode */
#define I2CS_CSR_STOP_STATUS   (0x20u) /* Set to 1 if Stop has been detected */
#define I2CS_CSR_ACK           (0x10u) /* ACK response */
#define I2CS_CSR_NAK           (0x00u) /* NAK response */
#define I2CS_CSR_LRB_ACK       (0x00u) /* Last received bit was an ACK */
#define I2CS_CSR_ADDRESS       (0x08u) /* Set in firmware 0 = status bit, 1 Address is slave */
#define I2CS_CSR_TRANSMIT      (0x04u) /* Set in firmware 1 = transmit, 0 = receive */
#define I2CS_CSR_LRB           (0x02u) /* Last received bit */
#define I2CS_CSR_LRB_NAK       (0x02u) /* Last received bit was an NAK */
#define I2CS_CSR_BYTE_COMPLETE (0x01u) /* Informs that last byte has been sent */

/* I2C state machine constants */
#define  I2CS_SM_IDLE              (0x00u) /* Wait for Start */

/* Primary slave address states */
#define  I2CS_SM_DEV1_WR_ADDR      (0x01u) /* Wait for sub-address */
#define  I2CS_SM_DEV1_WR_ADDR_MSB  (0x01u) /* Wait for sub-address MSB */
#define  I2CS_SM_DEV1_WR_ADDR_LSB  (0x02u) /* Wait for sub-address LSB */
#define  I2CS_SM_DEV1_WR_DATA      (0x04u) /* Get data from Master */
#define  I2CS_SM_DEV1_RD_DATA      (0x08u) /* Send data to Master */

/* Secondary slave address states */
#define  I2CS_SM_DEV2_WR_ADDR      (0x11u) /* Wait for sub-address */
#define  I2CS_SM_DEV2_WR_ADDR_MSB  (0x11u) /* Wait for sub-address MSB */
#define  I2CS_SM_DEV2_WR_ADDR_LSB  (0x12u) /* Wait for sub-address LSB */
#define  I2CS_SM_DEV2_WR_DATA      (0x14u) /* Get data from Master */
#define  I2CS_SM_DEV2_RD_DATA      (0x18u) /* Send data to Master */


/***************************************
*    Initialization Register Settings
***************************************/

/* Oversampling rate for data date 50kpbs and less is 32, 16 for others */
#define I2CS_OVS_32_LIM      (50u)
#define I2CS_OVERSAMPLE_RATE ((I2CS_DATA_RATE <= I2CS_OVS_32_LIM) ? (32u) : (16u))

/* Return default bits depends on configuration */
#define I2CS_DEFAULT_HDWR_ADDR  ((I2CS_ONE_ADDRESS == I2CS_ADDRESSES) ? (1u) : (0u))

#define I2CS_DEFAULT_PSELECT    ((I2CS_ANY  != I2CS_BUS_PORT) ? (1u) : (0u))
#define I2CS_DEFAULT_SIO_SELECT ((I2CS_I2C1 == I2CS_BUS_PORT) ? (1u) : (0u))
#define I2CS_DEFUALT_CLK_RATE   ((I2CS_DATA_RATE <= I2CS_OVS_32_LIM) ? (1u) : (0u))

/* Return bits within registers position */
#define I2CS_GET_XCFG_HDWR_ADDR_EN(hwAddr) ((0u != (hwAddr)) ? (I2CS_XCFG_HDWR_ADDR_EN) : (0u))
#define I2CS_GET_XCFG_I2C_ON(wakeup)       ((0u != (wakeup)) ? (I2CS_XCFG_I2C_ON) : (0u))

#define I2CS_GET_CFG_PSELECT(pSel)      ((0u != (pSel)) ? (I2CS_CFG_PSELECT) : (0u))
#define I2CS_GET_CFG_SIO_SELECT(sioSel) ((0u != (sioSel)) ? (I2CS_CFG_SIO_SELECT) : (0u))
#define I2CS_GET_CFG_CLK_RATE(clkRate)  ((0u != (clkRate)) ? (I2CS_CFG_CLK_RATE) : (0u))

/* Initial registers settings */
#define I2CS_DEFAULT_CFG    (I2CS_GET_CFG_SIO_SELECT (I2CS_DEFAULT_SIO_SELECT) | \
                                         I2CS_GET_CFG_PSELECT(I2CS_DEFAULT_PSELECT)        | \
                                         I2CS_GET_CFG_CLK_RATE(I2CS_DEFUALT_CLK_RATE)      | \
                                         I2CS_CFG_EN_SLAVE)

#define I2CS_DEFAULT_XCFG   (I2CS_GET_XCFG_HDWR_ADDR_EN(I2CS_DEFAULT_HDWR_ADDR) | \
                                         I2CS_GET_XCFG_I2C_ON(I2CS_ENABLE_WAKEUP)           | \
                                         I2CS_XCFG_CLK_EN)

#define I2CS_DEFAULT_ADDR   (I2CS_DEFAULT_ADDR1)

/* Divide factor calculation */
#define I2CS_DIVIDE_FACTOR_WITH_FRACT_BYTE \
    (((uint32) BCLK__BUS_CLK__KHZ << 8u) / ((uint32) I2CS_DATA_RATE * I2CS_OVERSAMPLE_RATE))

#define I2CS_DEFAULT_DIVIDE_FACTOR  (((uint32) I2CS_DIVIDE_FACTOR_WITH_FRACT_BYTE) >> 8u)

#define I2CS_DEFAULT_CLKDIV1    LO8(I2CS_DEFAULT_DIVIDE_FACTOR)
#define I2CS_DEFAULT_CLKDIV2    HI8(I2CS_DEFAULT_DIVIDE_FACTOR)


/***************************************
* The following code is DEPRECATED and
* should not be used in new projects.
***************************************/

#define I2CS_BUS_SPEED_50KHZ    (50u)
#define I2CS_BUS_SPEED          I2CS_DATA_RATE
#define I2CS_OVER_SAMPLE_RATE   I2CS_OVERSAMPLE_RATE

#define I2CS_I2C_MASTER_MASK    (0xDDu)

#define I2CS__ANY    I2CS_ANY
#define I2CS__I2C0   I2CS_I2C0
#define I2CS__I2C1   I2CS_I2C1

#define I2CS_DIVIDE_FACTOR  I2CS_DEFAULT_DIVIDE_FACTOR

#if (I2CS_ONE_ADDRESS == I2CS_ADDRESSES)
    void I2CS_SlaveSetSleepMode(void)   ;
    void I2CS_SlaveSetWakeMode(void)    ;
#endif /* (I2CS_ONE_ADDRESS == I2CS_ADDRESSES) */

#define I2CS_State          I2CS_curState
#define I2CS_Status         I2CS_curStatus
#define I2CS_DataPtr        I2CS_dataPtrS1

#define I2CS_RwOffset1      I2CS_rwOffsetS1
#define I2CS_RwIndex1       I2CS_rwIndexS1
#define I2CS_WrProtect1     I2CS_wrProtectS1
#define I2CS_BufSize1       I2CS_bufSizeS1

#if (I2CS_TWO_ADDRESSES == I2CS_ADDRESSES)
    #define I2CS_DataPtr2   I2CS_dataPtrS2
    #define I2CS_Address1   I2CS_addrS1
    #define I2CS_Address2   I2CS_addrS2

    #define I2CS_RwOffset2  I2CS_rwOffsetS2
    #define I2CS_RwIndex2   I2CS_rwIndexS2
    #define I2CS_WrProtect2 I2CS_wrProtectS2
    #define I2CS_BufSize2   I2CS_bufSizeS2
#endif /* (I2CS_TWO_ADDRESSES == I2CS_ADDRESSES) */

#endif /* CY_EZI2C_I2CS_H */


/* [] END OF FILE */
