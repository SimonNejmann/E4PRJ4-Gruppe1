#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* scl */
#define scl__0__INTTYPE CYREG_PICU12_INTTYPE4
#define scl__0__MASK 0x10u
#define scl__0__PC CYREG_PRT12_PC4
#define scl__0__PORT 12u
#define scl__0__SHIFT 4u
#define scl__AG CYREG_PRT12_AG
#define scl__BIE CYREG_PRT12_BIE
#define scl__BIT_MASK CYREG_PRT12_BIT_MASK
#define scl__BYP CYREG_PRT12_BYP
#define scl__DM0 CYREG_PRT12_DM0
#define scl__DM1 CYREG_PRT12_DM1
#define scl__DM2 CYREG_PRT12_DM2
#define scl__DR CYREG_PRT12_DR
#define scl__INP_DIS CYREG_PRT12_INP_DIS
#define scl__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define scl__MASK 0x10u
#define scl__PORT 12u
#define scl__PRT CYREG_PRT12_PRT
#define scl__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define scl__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define scl__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define scl__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define scl__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define scl__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define scl__PS CYREG_PRT12_PS
#define scl__SHIFT 4u
#define scl__SIO_CFG CYREG_PRT12_SIO_CFG
#define scl__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define scl__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define scl__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define scl__SLW CYREG_PRT12_SLW

/* sda */
#define sda__0__INTTYPE CYREG_PICU12_INTTYPE5
#define sda__0__MASK 0x20u
#define sda__0__PC CYREG_PRT12_PC5
#define sda__0__PORT 12u
#define sda__0__SHIFT 5u
#define sda__AG CYREG_PRT12_AG
#define sda__BIE CYREG_PRT12_BIE
#define sda__BIT_MASK CYREG_PRT12_BIT_MASK
#define sda__BYP CYREG_PRT12_BYP
#define sda__DM0 CYREG_PRT12_DM0
#define sda__DM1 CYREG_PRT12_DM1
#define sda__DM2 CYREG_PRT12_DM2
#define sda__DR CYREG_PRT12_DR
#define sda__INP_DIS CYREG_PRT12_INP_DIS
#define sda__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define sda__MASK 0x20u
#define sda__PORT 12u
#define sda__PRT CYREG_PRT12_PRT
#define sda__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define sda__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define sda__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define sda__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define sda__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define sda__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define sda__PS CYREG_PRT12_PS
#define sda__SHIFT 5u
#define sda__SIO_CFG CYREG_PRT12_SIO_CFG
#define sda__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define sda__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define sda__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define sda__SLW CYREG_PRT12_SLW

/* I2CS_I2C_FF */
#define I2CS_I2C_FF__ADR CYREG_I2C_ADR
#define I2CS_I2C_FF__CFG CYREG_I2C_CFG
#define I2CS_I2C_FF__CLK_DIV1 CYREG_I2C_CLK_DIV1
#define I2CS_I2C_FF__CLK_DIV2 CYREG_I2C_CLK_DIV2
#define I2CS_I2C_FF__CSR CYREG_I2C_CSR
#define I2CS_I2C_FF__D CYREG_I2C_D
#define I2CS_I2C_FF__MCSR CYREG_I2C_MCSR
#define I2CS_I2C_FF__PM_ACT_CFG CYREG_PM_ACT_CFG5
#define I2CS_I2C_FF__PM_ACT_MSK 0x04u
#define I2CS_I2C_FF__PM_STBY_CFG CYREG_PM_STBY_CFG5
#define I2CS_I2C_FF__PM_STBY_MSK 0x04u
#define I2CS_I2C_FF__TMOUT_CFG0 CYREG_I2C_TMOUT_CFG0
#define I2CS_I2C_FF__TMOUT_CFG1 CYREG_I2C_TMOUT_CFG1
#define I2CS_I2C_FF__TMOUT_CSR CYREG_I2C_TMOUT_CSR
#define I2CS_I2C_FF__TMOUT_SR CYREG_I2C_TMOUT_SR
#define I2CS_I2C_FF__XCFG CYREG_I2C_XCFG

/* I2CS_I2C_IRQ */
#define I2CS_I2C_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define I2CS_I2C_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define I2CS_I2C_IRQ__INTC_MASK 0x8000u
#define I2CS_I2C_IRQ__INTC_NUMBER 15u
#define I2CS_I2C_IRQ__INTC_PRIOR_NUM 7u
#define I2CS_I2C_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_15
#define I2CS_I2C_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define I2CS_I2C_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* PWM2_PWMUDB */
#define PWM2_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB00_01_ACTL
#define PWM2_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB00_01_CTL
#define PWM2_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB00_01_CTL
#define PWM2_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB00_01_CTL
#define PWM2_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB00_01_CTL
#define PWM2_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB00_01_MSK
#define PWM2_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB00_01_MSK
#define PWM2_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB00_01_MSK
#define PWM2_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB00_01_MSK
#define PWM2_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define PWM2_PWMUDB_genblk1_ctrlreg__7__POS 7
#define PWM2_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB00_ACTL
#define PWM2_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_B0_UDB00_CTL
#define PWM2_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB00_ST_CTL
#define PWM2_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_B0_UDB00_CTL
#define PWM2_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_B0_UDB00_ST_CTL
#define PWM2_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define PWM2_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB00_MSK_ACTL
#define PWM2_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB00_MSK_ACTL
#define PWM2_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_B0_UDB00_MSK
#define PWM2_PWMUDB_genblk8_stsreg__0__MASK 0x01u
#define PWM2_PWMUDB_genblk8_stsreg__0__POS 0
#define PWM2_PWMUDB_genblk8_stsreg__1__MASK 0x02u
#define PWM2_PWMUDB_genblk8_stsreg__1__POS 1
#define PWM2_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB01_02_ACTL
#define PWM2_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG CYREG_B0_UDB01_02_ST
#define PWM2_PWMUDB_genblk8_stsreg__2__MASK 0x04u
#define PWM2_PWMUDB_genblk8_stsreg__2__POS 2
#define PWM2_PWMUDB_genblk8_stsreg__3__MASK 0x08u
#define PWM2_PWMUDB_genblk8_stsreg__3__POS 3
#define PWM2_PWMUDB_genblk8_stsreg__MASK 0x0Fu
#define PWM2_PWMUDB_genblk8_stsreg__MASK_REG CYREG_B0_UDB01_MSK
#define PWM2_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB01_ACTL
#define PWM2_PWMUDB_genblk8_stsreg__STATUS_REG CYREG_B0_UDB01_ST
#define PWM2_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG CYREG_B0_UDB02_03_A0
#define PWM2_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG CYREG_B0_UDB02_03_A1
#define PWM2_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG CYREG_B0_UDB02_03_D0
#define PWM2_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG CYREG_B0_UDB02_03_D1
#define PWM2_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB02_03_ACTL
#define PWM2_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG CYREG_B0_UDB02_03_F0
#define PWM2_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG CYREG_B0_UDB02_03_F1
#define PWM2_PWMUDB_sP8_pwmdp_u0__A0_A1_REG CYREG_B0_UDB02_A0_A1
#define PWM2_PWMUDB_sP8_pwmdp_u0__A0_REG CYREG_B0_UDB02_A0
#define PWM2_PWMUDB_sP8_pwmdp_u0__A1_REG CYREG_B0_UDB02_A1
#define PWM2_PWMUDB_sP8_pwmdp_u0__D0_D1_REG CYREG_B0_UDB02_D0_D1
#define PWM2_PWMUDB_sP8_pwmdp_u0__D0_REG CYREG_B0_UDB02_D0
#define PWM2_PWMUDB_sP8_pwmdp_u0__D1_REG CYREG_B0_UDB02_D1
#define PWM2_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB02_ACTL
#define PWM2_PWMUDB_sP8_pwmdp_u0__F0_F1_REG CYREG_B0_UDB02_F0_F1
#define PWM2_PWMUDB_sP8_pwmdp_u0__F0_REG CYREG_B0_UDB02_F0
#define PWM2_PWMUDB_sP8_pwmdp_u0__F1_REG CYREG_B0_UDB02_F1

/* step */
#define step__0__INTTYPE CYREG_PICU2_INTTYPE3
#define step__0__MASK 0x08u
#define step__0__PC CYREG_PRT2_PC3
#define step__0__PORT 2u
#define step__0__SHIFT 3u
#define step__AG CYREG_PRT2_AG
#define step__AMUX CYREG_PRT2_AMUX
#define step__BIE CYREG_PRT2_BIE
#define step__BIT_MASK CYREG_PRT2_BIT_MASK
#define step__BYP CYREG_PRT2_BYP
#define step__CTL CYREG_PRT2_CTL
#define step__DM0 CYREG_PRT2_DM0
#define step__DM1 CYREG_PRT2_DM1
#define step__DM2 CYREG_PRT2_DM2
#define step__DR CYREG_PRT2_DR
#define step__INP_DIS CYREG_PRT2_INP_DIS
#define step__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define step__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define step__LCD_EN CYREG_PRT2_LCD_EN
#define step__MASK 0x08u
#define step__PORT 2u
#define step__PRT CYREG_PRT2_PRT
#define step__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define step__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define step__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define step__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define step__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define step__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define step__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define step__PS CYREG_PRT2_PS
#define step__SHIFT 3u
#define step__SLW CYREG_PRT2_SLW

/* UpDown_bQuadDec */
#define UpDown_bQuadDec_Stsreg__0__MASK 0x01u
#define UpDown_bQuadDec_Stsreg__0__POS 0
#define UpDown_bQuadDec_Stsreg__1__MASK 0x02u
#define UpDown_bQuadDec_Stsreg__1__POS 1
#define UpDown_bQuadDec_Stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB03_04_ACTL
#define UpDown_bQuadDec_Stsreg__16BIT_STATUS_REG CYREG_B0_UDB03_04_ST
#define UpDown_bQuadDec_Stsreg__2__MASK 0x04u
#define UpDown_bQuadDec_Stsreg__2__POS 2
#define UpDown_bQuadDec_Stsreg__3__MASK 0x08u
#define UpDown_bQuadDec_Stsreg__3__POS 3
#define UpDown_bQuadDec_Stsreg__MASK 0x0Fu
#define UpDown_bQuadDec_Stsreg__MASK_REG CYREG_B0_UDB03_MSK
#define UpDown_bQuadDec_Stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB03_ACTL
#define UpDown_bQuadDec_Stsreg__STATUS_REG CYREG_B0_UDB03_ST

/* UpDown_Cnt8_CounterUDB */
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__16BIT_A0_REG CYREG_B0_UDB04_05_A0
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__16BIT_A1_REG CYREG_B0_UDB04_05_A1
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__16BIT_D0_REG CYREG_B0_UDB04_05_D0
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__16BIT_D1_REG CYREG_B0_UDB04_05_D1
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__16BIT_F0_REG CYREG_B0_UDB04_05_F0
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__16BIT_F1_REG CYREG_B0_UDB04_05_F1
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__A0_A1_REG CYREG_B0_UDB04_A0_A1
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__A0_REG CYREG_B0_UDB04_A0
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__A1_REG CYREG_B0_UDB04_A1
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__D0_D1_REG CYREG_B0_UDB04_D0_D1
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__D0_REG CYREG_B0_UDB04_D0
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__D1_REG CYREG_B0_UDB04_D1
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__F0_F1_REG CYREG_B0_UDB04_F0_F1
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__F0_REG CYREG_B0_UDB04_F0
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__F1_REG CYREG_B0_UDB04_F1
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define UpDown_Cnt8_CounterUDB_sC8_counterdp_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB04_05_CTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB04_05_CTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB04_05_CTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB04_05_CTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB04_05_MSK
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB04_05_MSK
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB04_05_MSK
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB04_05_MSK
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__7__MASK 0x80u
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__7__POS 7
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG CYREG_B0_UDB04_CTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB04_ST_CTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__COUNT_REG CYREG_B0_UDB04_CTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__COUNT_ST_REG CYREG_B0_UDB04_ST_CTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__MASK 0x80u
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define UpDown_Cnt8_CounterUDB_sCTRLReg_ctrlreg__PERIOD_REG CYREG_B0_UDB04_MSK
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__0__MASK 0x01u
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__0__POS 0
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__1__MASK 0x02u
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__1__POS 1
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__16BIT_STATUS_REG CYREG_B0_UDB04_05_ST
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__2__MASK 0x04u
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__2__POS 2
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__3__MASK 0x08u
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__3__POS 3
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__5__MASK 0x20u
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__5__POS 5
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__6__MASK 0x40u
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__6__POS 6
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__MASK 0x6Fu
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__MASK_REG CYREG_B0_UDB04_MSK
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__MASK_ST_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__PER_ST_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__STATUS_CNT_REG CYREG_B0_UDB04_ST_CTL
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__STATUS_CONTROL_REG CYREG_B0_UDB04_ST_CTL
#define UpDown_Cnt8_CounterUDB_sSTSReg_stsreg__STATUS_REG CYREG_B0_UDB04_ST

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x01u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x02u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x02u

/* Clock_2 */
#define Clock_2__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_2__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_2__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_2__CFG2_SRC_SEL_MASK 0x07u
#define Clock_2__INDEX 0x00u
#define Clock_2__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_2__PM_ACT_MSK 0x01u
#define Clock_2__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_2__PM_STBY_MSK 0x01u

/* set_pwm */
#define set_pwm__0__INTTYPE CYREG_PICU0_INTTYPE0
#define set_pwm__0__MASK 0x01u
#define set_pwm__0__PC CYREG_PRT0_PC0
#define set_pwm__0__PORT 0u
#define set_pwm__0__SHIFT 0u
#define set_pwm__AG CYREG_PRT0_AG
#define set_pwm__AMUX CYREG_PRT0_AMUX
#define set_pwm__BIE CYREG_PRT0_BIE
#define set_pwm__BIT_MASK CYREG_PRT0_BIT_MASK
#define set_pwm__BYP CYREG_PRT0_BYP
#define set_pwm__CTL CYREG_PRT0_CTL
#define set_pwm__DM0 CYREG_PRT0_DM0
#define set_pwm__DM1 CYREG_PRT0_DM1
#define set_pwm__DM2 CYREG_PRT0_DM2
#define set_pwm__DR CYREG_PRT0_DR
#define set_pwm__INP_DIS CYREG_PRT0_INP_DIS
#define set_pwm__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define set_pwm__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define set_pwm__LCD_EN CYREG_PRT0_LCD_EN
#define set_pwm__MASK 0x01u
#define set_pwm__PORT 0u
#define set_pwm__PRT CYREG_PRT0_PRT
#define set_pwm__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define set_pwm__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define set_pwm__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define set_pwm__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define set_pwm__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define set_pwm__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define set_pwm__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define set_pwm__PS CYREG_PRT0_PS
#define set_pwm__SHIFT 0u
#define set_pwm__SLW CYREG_PRT0_SLW

/* Dir_step */
#define Dir_step__0__INTTYPE CYREG_PICU2_INTTYPE4
#define Dir_step__0__MASK 0x10u
#define Dir_step__0__PC CYREG_PRT2_PC4
#define Dir_step__0__PORT 2u
#define Dir_step__0__SHIFT 4u
#define Dir_step__AG CYREG_PRT2_AG
#define Dir_step__AMUX CYREG_PRT2_AMUX
#define Dir_step__BIE CYREG_PRT2_BIE
#define Dir_step__BIT_MASK CYREG_PRT2_BIT_MASK
#define Dir_step__BYP CYREG_PRT2_BYP
#define Dir_step__CTL CYREG_PRT2_CTL
#define Dir_step__DM0 CYREG_PRT2_DM0
#define Dir_step__DM1 CYREG_PRT2_DM1
#define Dir_step__DM2 CYREG_PRT2_DM2
#define Dir_step__DR CYREG_PRT2_DR
#define Dir_step__INP_DIS CYREG_PRT2_INP_DIS
#define Dir_step__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Dir_step__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Dir_step__LCD_EN CYREG_PRT2_LCD_EN
#define Dir_step__MASK 0x10u
#define Dir_step__PORT 2u
#define Dir_step__PRT CYREG_PRT2_PRT
#define Dir_step__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Dir_step__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Dir_step__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Dir_step__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Dir_step__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Dir_step__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Dir_step__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Dir_step__PS CYREG_PRT2_PS
#define Dir_step__SHIFT 4u
#define Dir_step__SLW CYREG_PRT2_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "version_01"
#define CY_VERSION "PSoC Creator  4.0"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 12u
#define CYDEV_CHIP_DIE_PSOC5LP 19u
#define CYDEV_CHIP_DIE_PSOC5TM 20u
#define CYDEV_CHIP_DIE_TMA4 2u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 4u
#define CYDEV_CHIP_FAMILY_FM3 5u
#define CYDEV_CHIP_FAMILY_FM4 6u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E127069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 12u
#define CYDEV_CHIP_MEMBER_4C 18u
#define CYDEV_CHIP_MEMBER_4D 8u
#define CYDEV_CHIP_MEMBER_4E 4u
#define CYDEV_CHIP_MEMBER_4F 13u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 11u
#define CYDEV_CHIP_MEMBER_4I 17u
#define CYDEV_CHIP_MEMBER_4J 9u
#define CYDEV_CHIP_MEMBER_4K 10u
#define CYDEV_CHIP_MEMBER_4L 16u
#define CYDEV_CHIP_MEMBER_4M 15u
#define CYDEV_CHIP_MEMBER_4N 6u
#define CYDEV_CHIP_MEMBER_4O 5u
#define CYDEV_CHIP_MEMBER_4P 14u
#define CYDEV_CHIP_MEMBER_4Q 7u
#define CYDEV_CHIP_MEMBER_4U 3u
#define CYDEV_CHIP_MEMBER_5A 20u
#define CYDEV_CHIP_MEMBER_5B 19u
#define CYDEV_CHIP_MEMBER_FM3 24u
#define CYDEV_CHIP_MEMBER_FM4 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00008000u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
