/*******************************************************************************
* File Name: State_2_defs.h
* 
* PSoC Creator  4.0
*
* Description:
* It contains defines for UDB editor content and should not be modified.
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2016 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_STATE_2_DEFS_H
#define INCLUDED_STATE_2_DEFS_H
#include "cydevice.h"
#include "cydevice_trm.h"
#include "cytypes.h"
#include "cyfitter.h"
#include "State_2_CtrlReg_Run.h"
#include "State_2_CtrlReg_Dir.h"

/* Note: Register pointers (denoted by a _PTR suffix) should be accessed
 * via the CY_GET_REGn and CY_SET_REGn macros (defined in cytypes.h),
 * where n is the width of the datapath with which they are associated.
 */

/******************** Forward (Width: 8) Definitions ********************/

#define State_2_Forward_A0_PTR 	 ((reg8 *) State_2_Forward_u0__A0_REG)
#define State_2_Forward_A0_REG 	 (* State_2_Forward_A0_PTR)
#define State_2_Forward_A1_PTR 	 ((reg8 *) State_2_Forward_u0__A1_REG)
#define State_2_Forward_A1_REG 	 (* State_2_Forward_A1_PTR)
#define State_2_Forward_D0_PTR 	 ((reg8 *) State_2_Forward_u0__D0_REG)
#define State_2_Forward_D0_REG 	 (* State_2_Forward_D0_PTR)
#define State_2_Forward_D1_PTR 	 ((reg8 *) State_2_Forward_u0__D1_REG)
#define State_2_Forward_D1_REG 	 (* State_2_Forward_D1_PTR)
#define State_2_Forward_F0_PTR 	 ((reg8 *) State_2_Forward_u0__F0_REG)
#define State_2_Forward_F0_REG 	 (* State_2_Forward_F0_PTR)
#define State_2_Forward_F1_PTR 	 ((reg8 *) State_2_Forward_u0__F1_REG)
#define State_2_Forward_F1_REG 	 (* State_2_Forward_F1_PTR)

/* Note: To avoid corruption of a shared register, call the following registers from within
 * a critical section (See Component Author Guide for details).
 */

/* Macros to clear DP FIFOs.*/
#define State_2_Forward_F0_CLEAR do { \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0x01u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)));\
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0xfeu & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)));\
    } while(0)
#define State_2_Forward_F1_CLEAR do { \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0x02u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)));\
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0xfdu & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)));\
    } while(0)

/* Macros to set FIFO level mode. See the TRM for details */
#define State_2_Forward_F0_SET_LEVEL_NORMAL \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0xfbu & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)))
#define State_2_Forward_F1_SET_LEVEL_NORMAL \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0xf7u & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)))
#define State_2_Forward_F0_SET_LEVEL_MID \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0x04u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)))
#define State_2_Forward_F1_SET_LEVEL_MID \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0x08u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)))

/* Macros to set FIFO to single-buffer mode. */
#define State_2_Forward_F0_SINGLE_BUFFER_SET \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0x01u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)))
#define State_2_Forward_F1_SINGLE_BUFFER_SET \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0x02u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)))

/* Macros to return the FIFO to normal mode. */
#define State_2_Forward_F0_SINGLE_BUFFER_UNSET \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0xfeu & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)))
#define State_2_Forward_F1_SINGLE_BUFFER_UNSET \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG), 0xfdu & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Forward_u0__DP_AUX_CTL_REG)))

/* End macros which should be called from within a critical section */

/******************** Pos (Width: 8) Definitions ********************/

#define State_2_Pos_A0_PTR 	 ((reg8 *) State_2_Pos_u0__A0_REG)
#define State_2_Pos_A0_REG 	 (* State_2_Pos_A0_PTR)
#define State_2_Pos_A1_PTR 	 ((reg8 *) State_2_Pos_u0__A1_REG)
#define State_2_Pos_A1_REG 	 (* State_2_Pos_A1_PTR)
#define State_2_Pos_D0_PTR 	 ((reg8 *) State_2_Pos_u0__D0_REG)
#define State_2_Pos_D0_REG 	 (* State_2_Pos_D0_PTR)
#define State_2_Pos_D1_PTR 	 ((reg8 *) State_2_Pos_u0__D1_REG)
#define State_2_Pos_D1_REG 	 (* State_2_Pos_D1_PTR)
#define State_2_Pos_F0_PTR 	 ((reg8 *) State_2_Pos_u0__F0_REG)
#define State_2_Pos_F0_REG 	 (* State_2_Pos_F0_PTR)
#define State_2_Pos_F1_PTR 	 ((reg8 *) State_2_Pos_u0__F1_REG)
#define State_2_Pos_F1_REG 	 (* State_2_Pos_F1_PTR)

/* Note: To avoid corruption of a shared register, call the following registers from within
 * a critical section (See Component Author Guide for details).
 */

/* Macros to clear DP FIFOs.*/
#define State_2_Pos_F0_CLEAR do { \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0x01u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)));\
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0xfeu & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)));\
    } while(0)
#define State_2_Pos_F1_CLEAR do { \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0x02u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)));\
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0xfdu & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)));\
    } while(0)

/* Macros to set FIFO level mode. See the TRM for details */
#define State_2_Pos_F0_SET_LEVEL_NORMAL \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0xfbu & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)))
#define State_2_Pos_F1_SET_LEVEL_NORMAL \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0xf7u & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)))
#define State_2_Pos_F0_SET_LEVEL_MID \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0x04u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)))
#define State_2_Pos_F1_SET_LEVEL_MID \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0x08u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)))

/* Macros to set FIFO to single-buffer mode. */
#define State_2_Pos_F0_SINGLE_BUFFER_SET \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0x01u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)))
#define State_2_Pos_F1_SINGLE_BUFFER_SET \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0x02u | \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)))

/* Macros to return the FIFO to normal mode. */
#define State_2_Pos_F0_SINGLE_BUFFER_UNSET \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0xfeu & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)))
#define State_2_Pos_F1_SINGLE_BUFFER_UNSET \
    CY_SET_XTND_REG8(\
        ((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG), 0xfdu & \
        CY_GET_XTND_REG8(((reg8 *) State_2_Pos_u0__DP_AUX_CTL_REG)))

/* End macros which should be called from within a critical section */


#endif /* INCLUDED_STATE_2_DEFS_H */
