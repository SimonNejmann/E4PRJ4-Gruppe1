/*******************************************************************************
* File Name: Dir.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Dir_H) /* Pins Dir_H */
#define CY_PINS_Dir_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dir_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dir__PORT == 15 && ((Dir__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dir_Write(uint8 value);
void    Dir_SetDriveMode(uint8 mode);
uint8   Dir_ReadDataReg(void);
uint8   Dir_Read(void);
void    Dir_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dir_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dir_SetDriveMode() function.
     *  @{
     */
        #define Dir_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dir_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dir_DM_RES_UP          PIN_DM_RES_UP
        #define Dir_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dir_DM_OD_LO           PIN_DM_OD_LO
        #define Dir_DM_OD_HI           PIN_DM_OD_HI
        #define Dir_DM_STRONG          PIN_DM_STRONG
        #define Dir_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dir_MASK               Dir__MASK
#define Dir_SHIFT              Dir__SHIFT
#define Dir_WIDTH              1u

/* Interrupt constants */
#if defined(Dir__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dir_SetInterruptMode() function.
     *  @{
     */
        #define Dir_INTR_NONE      (uint16)(0x0000u)
        #define Dir_INTR_RISING    (uint16)(0x0001u)
        #define Dir_INTR_FALLING   (uint16)(0x0002u)
        #define Dir_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dir_INTR_MASK      (0x01u) 
#endif /* (Dir__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dir_PS                     (* (reg8 *) Dir__PS)
/* Data Register */
#define Dir_DR                     (* (reg8 *) Dir__DR)
/* Port Number */
#define Dir_PRT_NUM                (* (reg8 *) Dir__PRT) 
/* Connect to Analog Globals */                                                  
#define Dir_AG                     (* (reg8 *) Dir__AG)                       
/* Analog MUX bux enable */
#define Dir_AMUX                   (* (reg8 *) Dir__AMUX) 
/* Bidirectional Enable */                                                        
#define Dir_BIE                    (* (reg8 *) Dir__BIE)
/* Bit-mask for Aliased Register Access */
#define Dir_BIT_MASK               (* (reg8 *) Dir__BIT_MASK)
/* Bypass Enable */
#define Dir_BYP                    (* (reg8 *) Dir__BYP)
/* Port wide control signals */                                                   
#define Dir_CTL                    (* (reg8 *) Dir__CTL)
/* Drive Modes */
#define Dir_DM0                    (* (reg8 *) Dir__DM0) 
#define Dir_DM1                    (* (reg8 *) Dir__DM1)
#define Dir_DM2                    (* (reg8 *) Dir__DM2) 
/* Input Buffer Disable Override */
#define Dir_INP_DIS                (* (reg8 *) Dir__INP_DIS)
/* LCD Common or Segment Drive */
#define Dir_LCD_COM_SEG            (* (reg8 *) Dir__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dir_LCD_EN                 (* (reg8 *) Dir__LCD_EN)
/* Slew Rate Control */
#define Dir_SLW                    (* (reg8 *) Dir__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dir_PRTDSI__CAPS_SEL       (* (reg8 *) Dir__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dir_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dir__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dir_PRTDSI__OE_SEL0        (* (reg8 *) Dir__PRTDSI__OE_SEL0) 
#define Dir_PRTDSI__OE_SEL1        (* (reg8 *) Dir__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dir_PRTDSI__OUT_SEL0       (* (reg8 *) Dir__PRTDSI__OUT_SEL0) 
#define Dir_PRTDSI__OUT_SEL1       (* (reg8 *) Dir__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dir_PRTDSI__SYNC_OUT       (* (reg8 *) Dir__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dir__SIO_CFG)
    #define Dir_SIO_HYST_EN        (* (reg8 *) Dir__SIO_HYST_EN)
    #define Dir_SIO_REG_HIFREQ     (* (reg8 *) Dir__SIO_REG_HIFREQ)
    #define Dir_SIO_CFG            (* (reg8 *) Dir__SIO_CFG)
    #define Dir_SIO_DIFF           (* (reg8 *) Dir__SIO_DIFF)
#endif /* (Dir__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dir__INTSTAT)
    #define Dir_INTSTAT            (* (reg8 *) Dir__INTSTAT)
    #define Dir_SNAP               (* (reg8 *) Dir__SNAP)
    
	#define Dir_0_INTTYPE_REG 		(* (reg8 *) Dir__0__INTTYPE)
#endif /* (Dir__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dir_H */


/* [] END OF FILE */
