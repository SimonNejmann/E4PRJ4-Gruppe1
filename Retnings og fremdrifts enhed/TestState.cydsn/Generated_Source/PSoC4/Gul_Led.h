/*******************************************************************************
* File Name: Gul_Led.h  
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

#if !defined(CY_PINS_Gul_Led_H) /* Pins Gul_Led_H */
#define CY_PINS_Gul_Led_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Gul_Led_aliases.h"


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
} Gul_Led_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Gul_Led_Read(void);
void    Gul_Led_Write(uint8 value);
uint8   Gul_Led_ReadDataReg(void);
#if defined(Gul_Led__PC) || (CY_PSOC4_4200L) 
    void    Gul_Led_SetDriveMode(uint8 mode);
#endif
void    Gul_Led_SetInterruptMode(uint16 position, uint16 mode);
uint8   Gul_Led_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Gul_Led_Sleep(void); 
void Gul_Led_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Gul_Led__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Gul_Led_DRIVE_MODE_BITS        (3)
    #define Gul_Led_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Gul_Led_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Gul_Led_SetDriveMode() function.
         *  @{
         */
        #define Gul_Led_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Gul_Led_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Gul_Led_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Gul_Led_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Gul_Led_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Gul_Led_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Gul_Led_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Gul_Led_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Gul_Led_MASK               Gul_Led__MASK
#define Gul_Led_SHIFT              Gul_Led__SHIFT
#define Gul_Led_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Gul_Led_SetInterruptMode() function.
     *  @{
     */
        #define Gul_Led_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Gul_Led_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Gul_Led_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Gul_Led_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Gul_Led__SIO)
    #define Gul_Led_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Gul_Led__PC) && (CY_PSOC4_4200L)
    #define Gul_Led_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Gul_Led_USBIO_DISABLE              ((uint32)(~Gul_Led_USBIO_ENABLE))
    #define Gul_Led_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Gul_Led_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Gul_Led_USBIO_ENTER_SLEEP          ((uint32)((1u << Gul_Led_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Gul_Led_USBIO_SUSPEND_DEL_SHIFT)))
    #define Gul_Led_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Gul_Led_USBIO_SUSPEND_SHIFT)))
    #define Gul_Led_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Gul_Led_USBIO_SUSPEND_DEL_SHIFT)))
    #define Gul_Led_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Gul_Led__PC)
    /* Port Configuration */
    #define Gul_Led_PC                 (* (reg32 *) Gul_Led__PC)
#endif
/* Pin State */
#define Gul_Led_PS                     (* (reg32 *) Gul_Led__PS)
/* Data Register */
#define Gul_Led_DR                     (* (reg32 *) Gul_Led__DR)
/* Input Buffer Disable Override */
#define Gul_Led_INP_DIS                (* (reg32 *) Gul_Led__PC2)

/* Interrupt configuration Registers */
#define Gul_Led_INTCFG                 (* (reg32 *) Gul_Led__INTCFG)
#define Gul_Led_INTSTAT                (* (reg32 *) Gul_Led__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Gul_Led_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Gul_Led__SIO)
    #define Gul_Led_SIO_REG            (* (reg32 *) Gul_Led__SIO)
#endif /* (Gul_Led__SIO_CFG) */

/* USBIO registers */
#if !defined(Gul_Led__PC) && (CY_PSOC4_4200L)
    #define Gul_Led_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Gul_Led_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Gul_Led_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Gul_Led_DRIVE_MODE_SHIFT       (0x00u)
#define Gul_Led_DRIVE_MODE_MASK        (0x07u << Gul_Led_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Gul_Led_H */


/* [] END OF FILE */
