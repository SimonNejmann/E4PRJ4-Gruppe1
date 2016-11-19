/*******************************************************************************
* File Name: C_front.h  
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

#if !defined(CY_PINS_C_front_H) /* Pins C_front_H */
#define CY_PINS_C_front_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "C_front_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 C_front__PORT == 15 && ((C_front__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    C_front_Write(uint8 value);
void    C_front_SetDriveMode(uint8 mode);
uint8   C_front_ReadDataReg(void);
uint8   C_front_Read(void);
void    C_front_SetInterruptMode(uint16 position, uint16 mode);
uint8   C_front_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the C_front_SetDriveMode() function.
     *  @{
     */
        #define C_front_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define C_front_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define C_front_DM_RES_UP          PIN_DM_RES_UP
        #define C_front_DM_RES_DWN         PIN_DM_RES_DWN
        #define C_front_DM_OD_LO           PIN_DM_OD_LO
        #define C_front_DM_OD_HI           PIN_DM_OD_HI
        #define C_front_DM_STRONG          PIN_DM_STRONG
        #define C_front_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define C_front_MASK               C_front__MASK
#define C_front_SHIFT              C_front__SHIFT
#define C_front_WIDTH              1u

/* Interrupt constants */
#if defined(C_front__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in C_front_SetInterruptMode() function.
     *  @{
     */
        #define C_front_INTR_NONE      (uint16)(0x0000u)
        #define C_front_INTR_RISING    (uint16)(0x0001u)
        #define C_front_INTR_FALLING   (uint16)(0x0002u)
        #define C_front_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define C_front_INTR_MASK      (0x01u) 
#endif /* (C_front__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define C_front_PS                     (* (reg8 *) C_front__PS)
/* Data Register */
#define C_front_DR                     (* (reg8 *) C_front__DR)
/* Port Number */
#define C_front_PRT_NUM                (* (reg8 *) C_front__PRT) 
/* Connect to Analog Globals */                                                  
#define C_front_AG                     (* (reg8 *) C_front__AG)                       
/* Analog MUX bux enable */
#define C_front_AMUX                   (* (reg8 *) C_front__AMUX) 
/* Bidirectional Enable */                                                        
#define C_front_BIE                    (* (reg8 *) C_front__BIE)
/* Bit-mask for Aliased Register Access */
#define C_front_BIT_MASK               (* (reg8 *) C_front__BIT_MASK)
/* Bypass Enable */
#define C_front_BYP                    (* (reg8 *) C_front__BYP)
/* Port wide control signals */                                                   
#define C_front_CTL                    (* (reg8 *) C_front__CTL)
/* Drive Modes */
#define C_front_DM0                    (* (reg8 *) C_front__DM0) 
#define C_front_DM1                    (* (reg8 *) C_front__DM1)
#define C_front_DM2                    (* (reg8 *) C_front__DM2) 
/* Input Buffer Disable Override */
#define C_front_INP_DIS                (* (reg8 *) C_front__INP_DIS)
/* LCD Common or Segment Drive */
#define C_front_LCD_COM_SEG            (* (reg8 *) C_front__LCD_COM_SEG)
/* Enable Segment LCD */
#define C_front_LCD_EN                 (* (reg8 *) C_front__LCD_EN)
/* Slew Rate Control */
#define C_front_SLW                    (* (reg8 *) C_front__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define C_front_PRTDSI__CAPS_SEL       (* (reg8 *) C_front__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define C_front_PRTDSI__DBL_SYNC_IN    (* (reg8 *) C_front__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define C_front_PRTDSI__OE_SEL0        (* (reg8 *) C_front__PRTDSI__OE_SEL0) 
#define C_front_PRTDSI__OE_SEL1        (* (reg8 *) C_front__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define C_front_PRTDSI__OUT_SEL0       (* (reg8 *) C_front__PRTDSI__OUT_SEL0) 
#define C_front_PRTDSI__OUT_SEL1       (* (reg8 *) C_front__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define C_front_PRTDSI__SYNC_OUT       (* (reg8 *) C_front__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(C_front__SIO_CFG)
    #define C_front_SIO_HYST_EN        (* (reg8 *) C_front__SIO_HYST_EN)
    #define C_front_SIO_REG_HIFREQ     (* (reg8 *) C_front__SIO_REG_HIFREQ)
    #define C_front_SIO_CFG            (* (reg8 *) C_front__SIO_CFG)
    #define C_front_SIO_DIFF           (* (reg8 *) C_front__SIO_DIFF)
#endif /* (C_front__SIO_CFG) */

/* Interrupt Registers */
#if defined(C_front__INTSTAT)
    #define C_front_INTSTAT            (* (reg8 *) C_front__INTSTAT)
    #define C_front_SNAP               (* (reg8 *) C_front__SNAP)
    
	#define C_front_0_INTTYPE_REG 		(* (reg8 *) C_front__0__INTTYPE)
#endif /* (C_front__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_C_front_H */


/* [] END OF FILE */
