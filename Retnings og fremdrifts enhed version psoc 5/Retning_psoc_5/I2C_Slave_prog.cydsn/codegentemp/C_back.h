/*******************************************************************************
* File Name: C_back.h  
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

#if !defined(CY_PINS_C_back_H) /* Pins C_back_H */
#define CY_PINS_C_back_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "C_back_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 C_back__PORT == 15 && ((C_back__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    C_back_Write(uint8 value);
void    C_back_SetDriveMode(uint8 mode);
uint8   C_back_ReadDataReg(void);
uint8   C_back_Read(void);
void    C_back_SetInterruptMode(uint16 position, uint16 mode);
uint8   C_back_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the C_back_SetDriveMode() function.
     *  @{
     */
        #define C_back_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define C_back_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define C_back_DM_RES_UP          PIN_DM_RES_UP
        #define C_back_DM_RES_DWN         PIN_DM_RES_DWN
        #define C_back_DM_OD_LO           PIN_DM_OD_LO
        #define C_back_DM_OD_HI           PIN_DM_OD_HI
        #define C_back_DM_STRONG          PIN_DM_STRONG
        #define C_back_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define C_back_MASK               C_back__MASK
#define C_back_SHIFT              C_back__SHIFT
#define C_back_WIDTH              1u

/* Interrupt constants */
#if defined(C_back__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in C_back_SetInterruptMode() function.
     *  @{
     */
        #define C_back_INTR_NONE      (uint16)(0x0000u)
        #define C_back_INTR_RISING    (uint16)(0x0001u)
        #define C_back_INTR_FALLING   (uint16)(0x0002u)
        #define C_back_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define C_back_INTR_MASK      (0x01u) 
#endif /* (C_back__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define C_back_PS                     (* (reg8 *) C_back__PS)
/* Data Register */
#define C_back_DR                     (* (reg8 *) C_back__DR)
/* Port Number */
#define C_back_PRT_NUM                (* (reg8 *) C_back__PRT) 
/* Connect to Analog Globals */                                                  
#define C_back_AG                     (* (reg8 *) C_back__AG)                       
/* Analog MUX bux enable */
#define C_back_AMUX                   (* (reg8 *) C_back__AMUX) 
/* Bidirectional Enable */                                                        
#define C_back_BIE                    (* (reg8 *) C_back__BIE)
/* Bit-mask for Aliased Register Access */
#define C_back_BIT_MASK               (* (reg8 *) C_back__BIT_MASK)
/* Bypass Enable */
#define C_back_BYP                    (* (reg8 *) C_back__BYP)
/* Port wide control signals */                                                   
#define C_back_CTL                    (* (reg8 *) C_back__CTL)
/* Drive Modes */
#define C_back_DM0                    (* (reg8 *) C_back__DM0) 
#define C_back_DM1                    (* (reg8 *) C_back__DM1)
#define C_back_DM2                    (* (reg8 *) C_back__DM2) 
/* Input Buffer Disable Override */
#define C_back_INP_DIS                (* (reg8 *) C_back__INP_DIS)
/* LCD Common or Segment Drive */
#define C_back_LCD_COM_SEG            (* (reg8 *) C_back__LCD_COM_SEG)
/* Enable Segment LCD */
#define C_back_LCD_EN                 (* (reg8 *) C_back__LCD_EN)
/* Slew Rate Control */
#define C_back_SLW                    (* (reg8 *) C_back__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define C_back_PRTDSI__CAPS_SEL       (* (reg8 *) C_back__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define C_back_PRTDSI__DBL_SYNC_IN    (* (reg8 *) C_back__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define C_back_PRTDSI__OE_SEL0        (* (reg8 *) C_back__PRTDSI__OE_SEL0) 
#define C_back_PRTDSI__OE_SEL1        (* (reg8 *) C_back__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define C_back_PRTDSI__OUT_SEL0       (* (reg8 *) C_back__PRTDSI__OUT_SEL0) 
#define C_back_PRTDSI__OUT_SEL1       (* (reg8 *) C_back__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define C_back_PRTDSI__SYNC_OUT       (* (reg8 *) C_back__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(C_back__SIO_CFG)
    #define C_back_SIO_HYST_EN        (* (reg8 *) C_back__SIO_HYST_EN)
    #define C_back_SIO_REG_HIFREQ     (* (reg8 *) C_back__SIO_REG_HIFREQ)
    #define C_back_SIO_CFG            (* (reg8 *) C_back__SIO_CFG)
    #define C_back_SIO_DIFF           (* (reg8 *) C_back__SIO_DIFF)
#endif /* (C_back__SIO_CFG) */

/* Interrupt Registers */
#if defined(C_back__INTSTAT)
    #define C_back_INTSTAT            (* (reg8 *) C_back__INTSTAT)
    #define C_back_SNAP               (* (reg8 *) C_back__SNAP)
    
	#define C_back_0_INTTYPE_REG 		(* (reg8 *) C_back__0__INTTYPE)
#endif /* (C_back__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_C_back_H */


/* [] END OF FILE */
