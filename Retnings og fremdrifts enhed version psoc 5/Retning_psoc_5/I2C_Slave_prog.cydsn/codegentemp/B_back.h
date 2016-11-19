/*******************************************************************************
* File Name: B_back.h  
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

#if !defined(CY_PINS_B_back_H) /* Pins B_back_H */
#define CY_PINS_B_back_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "B_back_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 B_back__PORT == 15 && ((B_back__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    B_back_Write(uint8 value);
void    B_back_SetDriveMode(uint8 mode);
uint8   B_back_ReadDataReg(void);
uint8   B_back_Read(void);
void    B_back_SetInterruptMode(uint16 position, uint16 mode);
uint8   B_back_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the B_back_SetDriveMode() function.
     *  @{
     */
        #define B_back_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define B_back_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define B_back_DM_RES_UP          PIN_DM_RES_UP
        #define B_back_DM_RES_DWN         PIN_DM_RES_DWN
        #define B_back_DM_OD_LO           PIN_DM_OD_LO
        #define B_back_DM_OD_HI           PIN_DM_OD_HI
        #define B_back_DM_STRONG          PIN_DM_STRONG
        #define B_back_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define B_back_MASK               B_back__MASK
#define B_back_SHIFT              B_back__SHIFT
#define B_back_WIDTH              1u

/* Interrupt constants */
#if defined(B_back__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in B_back_SetInterruptMode() function.
     *  @{
     */
        #define B_back_INTR_NONE      (uint16)(0x0000u)
        #define B_back_INTR_RISING    (uint16)(0x0001u)
        #define B_back_INTR_FALLING   (uint16)(0x0002u)
        #define B_back_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define B_back_INTR_MASK      (0x01u) 
#endif /* (B_back__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define B_back_PS                     (* (reg8 *) B_back__PS)
/* Data Register */
#define B_back_DR                     (* (reg8 *) B_back__DR)
/* Port Number */
#define B_back_PRT_NUM                (* (reg8 *) B_back__PRT) 
/* Connect to Analog Globals */                                                  
#define B_back_AG                     (* (reg8 *) B_back__AG)                       
/* Analog MUX bux enable */
#define B_back_AMUX                   (* (reg8 *) B_back__AMUX) 
/* Bidirectional Enable */                                                        
#define B_back_BIE                    (* (reg8 *) B_back__BIE)
/* Bit-mask for Aliased Register Access */
#define B_back_BIT_MASK               (* (reg8 *) B_back__BIT_MASK)
/* Bypass Enable */
#define B_back_BYP                    (* (reg8 *) B_back__BYP)
/* Port wide control signals */                                                   
#define B_back_CTL                    (* (reg8 *) B_back__CTL)
/* Drive Modes */
#define B_back_DM0                    (* (reg8 *) B_back__DM0) 
#define B_back_DM1                    (* (reg8 *) B_back__DM1)
#define B_back_DM2                    (* (reg8 *) B_back__DM2) 
/* Input Buffer Disable Override */
#define B_back_INP_DIS                (* (reg8 *) B_back__INP_DIS)
/* LCD Common or Segment Drive */
#define B_back_LCD_COM_SEG            (* (reg8 *) B_back__LCD_COM_SEG)
/* Enable Segment LCD */
#define B_back_LCD_EN                 (* (reg8 *) B_back__LCD_EN)
/* Slew Rate Control */
#define B_back_SLW                    (* (reg8 *) B_back__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define B_back_PRTDSI__CAPS_SEL       (* (reg8 *) B_back__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define B_back_PRTDSI__DBL_SYNC_IN    (* (reg8 *) B_back__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define B_back_PRTDSI__OE_SEL0        (* (reg8 *) B_back__PRTDSI__OE_SEL0) 
#define B_back_PRTDSI__OE_SEL1        (* (reg8 *) B_back__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define B_back_PRTDSI__OUT_SEL0       (* (reg8 *) B_back__PRTDSI__OUT_SEL0) 
#define B_back_PRTDSI__OUT_SEL1       (* (reg8 *) B_back__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define B_back_PRTDSI__SYNC_OUT       (* (reg8 *) B_back__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(B_back__SIO_CFG)
    #define B_back_SIO_HYST_EN        (* (reg8 *) B_back__SIO_HYST_EN)
    #define B_back_SIO_REG_HIFREQ     (* (reg8 *) B_back__SIO_REG_HIFREQ)
    #define B_back_SIO_CFG            (* (reg8 *) B_back__SIO_CFG)
    #define B_back_SIO_DIFF           (* (reg8 *) B_back__SIO_DIFF)
#endif /* (B_back__SIO_CFG) */

/* Interrupt Registers */
#if defined(B_back__INTSTAT)
    #define B_back_INTSTAT            (* (reg8 *) B_back__INTSTAT)
    #define B_back_SNAP               (* (reg8 *) B_back__SNAP)
    
	#define B_back_0_INTTYPE_REG 		(* (reg8 *) B_back__0__INTTYPE)
#endif /* (B_back__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_B_back_H */


/* [] END OF FILE */
