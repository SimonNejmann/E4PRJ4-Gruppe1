/*******************************************************************************
* File Name: BackW.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BackW_H) /* Pins BackW_H */
#define CY_PINS_BackW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BackW_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} BackW_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   BackW_Read(void);
void    BackW_Write(uint8 value);
uint8   BackW_ReadDataReg(void);
#if defined(BackW__PC) || (CY_PSOC4_4200L) 
    void    BackW_SetDriveMode(uint8 mode);
#endif
void    BackW_SetInterruptMode(uint16 position, uint16 mode);
uint8   BackW_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void BackW_Sleep(void); 
void BackW_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(BackW__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define BackW_DRIVE_MODE_BITS        (3)
    #define BackW_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BackW_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the BackW_SetDriveMode() function.
         *  @{
         */
        #define BackW_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define BackW_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define BackW_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define BackW_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define BackW_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define BackW_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define BackW_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define BackW_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define BackW_MASK               BackW__MASK
#define BackW_SHIFT              BackW__SHIFT
#define BackW_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BackW_SetInterruptMode() function.
     *  @{
     */
        #define BackW_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define BackW_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define BackW_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define BackW_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(BackW__SIO)
    #define BackW_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(BackW__PC) && (CY_PSOC4_4200L)
    #define BackW_USBIO_ENABLE               ((uint32)0x80000000u)
    #define BackW_USBIO_DISABLE              ((uint32)(~BackW_USBIO_ENABLE))
    #define BackW_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define BackW_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define BackW_USBIO_ENTER_SLEEP          ((uint32)((1u << BackW_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << BackW_USBIO_SUSPEND_DEL_SHIFT)))
    #define BackW_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << BackW_USBIO_SUSPEND_SHIFT)))
    #define BackW_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << BackW_USBIO_SUSPEND_DEL_SHIFT)))
    #define BackW_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(BackW__PC)
    /* Port Configuration */
    #define BackW_PC                 (* (reg32 *) BackW__PC)
#endif
/* Pin State */
#define BackW_PS                     (* (reg32 *) BackW__PS)
/* Data Register */
#define BackW_DR                     (* (reg32 *) BackW__DR)
/* Input Buffer Disable Override */
#define BackW_INP_DIS                (* (reg32 *) BackW__PC2)

/* Interrupt configuration Registers */
#define BackW_INTCFG                 (* (reg32 *) BackW__INTCFG)
#define BackW_INTSTAT                (* (reg32 *) BackW__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define BackW_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(BackW__SIO)
    #define BackW_SIO_REG            (* (reg32 *) BackW__SIO)
#endif /* (BackW__SIO_CFG) */

/* USBIO registers */
#if !defined(BackW__PC) && (CY_PSOC4_4200L)
    #define BackW_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define BackW_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define BackW_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define BackW_DRIVE_MODE_SHIFT       (0x00u)
#define BackW_DRIVE_MODE_MASK        (0x07u << BackW_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins BackW_H */


/* [] END OF FILE */
