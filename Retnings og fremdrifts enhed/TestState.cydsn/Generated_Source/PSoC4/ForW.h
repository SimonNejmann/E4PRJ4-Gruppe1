/*******************************************************************************
* File Name: ForW.h  
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

#if !defined(CY_PINS_ForW_H) /* Pins ForW_H */
#define CY_PINS_ForW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ForW_aliases.h"


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
} ForW_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ForW_Read(void);
void    ForW_Write(uint8 value);
uint8   ForW_ReadDataReg(void);
#if defined(ForW__PC) || (CY_PSOC4_4200L) 
    void    ForW_SetDriveMode(uint8 mode);
#endif
void    ForW_SetInterruptMode(uint16 position, uint16 mode);
uint8   ForW_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ForW_Sleep(void); 
void ForW_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ForW__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ForW_DRIVE_MODE_BITS        (3)
    #define ForW_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ForW_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ForW_SetDriveMode() function.
         *  @{
         */
        #define ForW_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ForW_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ForW_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ForW_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ForW_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ForW_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ForW_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ForW_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ForW_MASK               ForW__MASK
#define ForW_SHIFT              ForW__SHIFT
#define ForW_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ForW_SetInterruptMode() function.
     *  @{
     */
        #define ForW_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ForW_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ForW_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ForW_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ForW__SIO)
    #define ForW_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ForW__PC) && (CY_PSOC4_4200L)
    #define ForW_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ForW_USBIO_DISABLE              ((uint32)(~ForW_USBIO_ENABLE))
    #define ForW_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ForW_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ForW_USBIO_ENTER_SLEEP          ((uint32)((1u << ForW_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ForW_USBIO_SUSPEND_DEL_SHIFT)))
    #define ForW_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ForW_USBIO_SUSPEND_SHIFT)))
    #define ForW_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ForW_USBIO_SUSPEND_DEL_SHIFT)))
    #define ForW_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ForW__PC)
    /* Port Configuration */
    #define ForW_PC                 (* (reg32 *) ForW__PC)
#endif
/* Pin State */
#define ForW_PS                     (* (reg32 *) ForW__PS)
/* Data Register */
#define ForW_DR                     (* (reg32 *) ForW__DR)
/* Input Buffer Disable Override */
#define ForW_INP_DIS                (* (reg32 *) ForW__PC2)

/* Interrupt configuration Registers */
#define ForW_INTCFG                 (* (reg32 *) ForW__INTCFG)
#define ForW_INTSTAT                (* (reg32 *) ForW__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ForW_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ForW__SIO)
    #define ForW_SIO_REG            (* (reg32 *) ForW__SIO)
#endif /* (ForW__SIO_CFG) */

/* USBIO registers */
#if !defined(ForW__PC) && (CY_PSOC4_4200L)
    #define ForW_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ForW_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ForW_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ForW_DRIVE_MODE_SHIFT       (0x00u)
#define ForW_DRIVE_MODE_MASK        (0x07u << ForW_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ForW_H */


/* [] END OF FILE */
