/*
** ###################################################################
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
**     Copyright 2017 NXP
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of the copyright holder nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** ###################################################################
*/

/*==========================================================================*/
/*!
 * @file
 *
 * File containing the subsystem specific DSC header info.
 *
 * @addtogroup SC_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_SC_DSC_H
#define SC_SS_SC_DSC_H

/* Includes */

#include "ss/base/dsc.h"

/*!
 * @name SS GPR Control 0 Bit Definitions
 */
/*@{*/
#define GPR_CM4_HCLK_MUX_SEL        REGBIT(0, 8)
#define GPR_CM4_PANIC_MODE_SEL      REGBIT(0, 9)
#define GPR_CM4_AXBS_STALL_REQUEST  REGBIT(0, 10)
#define GPR_ROSC_STOP_EN_AON        REGBIT(0, 11)
#define GPR_CM4_DBG_REQ             REGBIT(0, 12)
#define GPR_CM4_TX_EVENT_ENB        REGBIT(0, 13)
#define GPR_CM4_HCLK_ENB            REGBIT(0, 14)
#define GPR_CXCTI0                  REGBIT(0, 15)
#define GPR_CSYSREQ_DBLOG           REGBIT(0, 16)
#define GPR_CSYSREQ_SCU             REGBIT(0, 17)
#define GPR_CSYSREQ_CM4_0           REGBIT(0, 18)
#define GPR_CSYSREQ_CM4_1           REGBIT(0, 19)
#define GPR_CSYSREQ_A53             REGBIT(0, 20)
#define GPR_CSYSREQ_A72             REGBIT(0, 21)
#define GPR_CSYSREQ_VPU             REGBIT(0, 22)
#define GPR_SIM_BBS_LP_RUN_ACK_3V   REGBIT(0, 24)
#define GPR_SIM_BBS_HS_RUN_ACK_3V   REGBIT(0, 25)
#define GPR_SIM_SYS_RST_SRSL_WDOG   REGBIT(0, 26)
#define GPR_SIM_SYS_RST_SRSH_LOCKUP REGBIT(0, 27)
#define GPR_SIM_SYS_RST_SRSH_SW     REGBIT(0, 28)
#define GPR_SIM_SYS_RST_SRSH_UECC   REGBIT(0, 29)
#define GPR_SIM_RCM_VLLS_DETECT     REGBIT(0, 30)
#define GPR_SLEEP_HOLD_REQ          REGBIT(0, 31)
/*@}*/

/*!
 * @name SS GPR Control 1 Bit Definitions
 */
/*@{*/
#define GPR_CPWRUPACK1              REGBIT(1, 1)
#define GPR_CPWRUPACK2              REGBIT(1, 2)
#define GPR_CPWRUPACK3              REGBIT(1, 3)
#define GPR_CPWRUPACK4              REGBIT(1, 4)
#define GPR_CPWRUPACK5              REGBIT(1, 5)
#define GPR_CPWRUPACK6              REGBIT(1, 6)
#define GPR_CPWRUPACK7              REGBIT(1, 7)
#define GPR_CPWRUPACK8              REGBIT(1, 8)
#define GPR_CPWRUPACK9              REGBIT(1, 9)
#define GPR_CPWRUPACK10             REGBIT(1, 10)
#define GPR_CPWRUPACK11             REGBIT(1, 11)
#define GPR_CPWRUPACK12             REGBIT(1, 12)
#define GPR_CDBGPWRUPACK            REGBIT(1, 13)
#define GPR_CSYSPWRUPACK            REGBIT(1, 14)
#define GPR_CDBGRSTACK              REGBIT(1, 15)
#define GPR_LPI2C1_IPG_STOP         REGBIT(1, 18)
#define GPR_LPI2C1_IPG_STOP_MODE    REGBIT(1, 19)
#define GPR_WDOG1_IPG_STOP          REGBIT(1, 21)
#define GPR_CAAM_CLK_EN             REGBIT(1, 22)
#define GPR_CAAM_IPG_STOP           REGBIT(1, 23)
#define GPR_TPM1_IPG_STOP           REGBIT(1, 25)
#define GPR_LPUART1_IPG_STOP        REGBIT(1, 27)
#define GPR_LPUART1_IPG_STOP_MODE   REGBIT(1, 28)
#define GPR_IOMUX_ISO_EN0           REGBIT(1, 30)
#define GPR_IOMUX_ISO_EN1           REGBIT(1, 31)
/*@}*/

/*!
 * @name SS GPR Control 2 Bit Definitions
 */
/*@{*/
#define GPR_TL_ISO_EN_B             REGBIT(2, 0)
#define GPR_TL_SW_LF_EN             REGBIT(2, 1)
#define GPR_TL_SW_HF_EN             REGBIT(2, 2)
/*@}*/

/*!
 * @name SS GPR Status 0 Bit Definitions
 */
/*@{*/
#define GPS_BOOT_MODE0              REGBIT(0, 16)
#define GPS_BOOT_MODE1              REGBIT(0, 17)
#define GPS_BOOT_MODE2              REGBIT(0, 18)
#define GPS_BOOT_MODE3              REGBIT(0, 19)
#define GPS_BOOT_MODE4              REGBIT(0, 20)
#define GPS_BOOT_MODE5              REGBIT(0, 21)
#define GPS_BOOT_MODE6              REGBIT(0, 22)
#define GPS_BOOT_MODE7              REGBIT(0, 23)
#define GPS_LP_STOP_MODE_LOWV_BBS0  REGBIT(0, 24)
#define GPS_LP_STOP_MODE_LOWV_BBS1  REGBIT(0, 25)
#define GPS_LP_STOP_MODE_LOWV_BBS2  REGBIT(0, 26)
#define GPS_LP_STOP_OPTION_BBS0     REGBIT(0, 28)
#define GPS_LP_STOP_OPTION_BBS1     REGBIT(0, 29)
/*@}*/

/*!
 * @name SS GPR Status 1 Bit Definitions
 */
/*@{*/
#define GPS_CPWRUPREQ1              REGBIT(1, 1)
#define GPS_CPWRUPREQ2              REGBIT(1, 2)
#define GPS_CPWRUPREQ3              REGBIT(1, 3)
#define GPS_CPWRUPREQ4              REGBIT(1, 4)
#define GPS_CPWRUPREQ5              REGBIT(1, 5)
#define GPS_CPWRUPREQ6              REGBIT(1, 6)
#define GPS_CPWRUPREQ7              REGBIT(1, 7)
#define GPS_CPWRUPREQ8              REGBIT(1, 8)
#define GPS_CPWRUPREQ9              REGBIT(1, 9)
#define GPS_CDBGPWRUPREQ            REGBIT(1, 13)
#define GPS_CSYSPWRUPREQ            REGBIT(1, 14)
#define GPS_CDBGRSTREQ              REGBIT(1, 15)
#define GPS_ADM_LPM_INHIBIT         REGBIT(1, 17)
/*@}*/

/*!
 * @name SS GPR Status 2 Bit Definitions
 */
/*@{*/
#define GPS_JTAG_ID                 REGBIT(2, 0)
/*@}*/

/*!
 * @name SS IRQ Mask Definitions
 */
/*@{*/
#define IRQ_CM4_CPU_SLEEPING        REGBIT64(1, 4)
#define IRQ_CM4_CPU_SLEEP_DEEP      REGBIT64(1, 5)
#define IRQ_CM4_AXBS_STALL_ACK      REGBIT64(1, 6)
#define IRQ_CM4_CPU_SYS_RESET_REQ   REGBIT64(1, 7)
#define IRQ_WDOG1_WDG_RSTO          REGBIT64(1, 8)
#define IRQ_CM4_CPU_LOCKUP          REGBIT64(1, 9)
#define IRQ_AWIC_REQ                REGBIT64(1, 10)
#define IRQ_CM4_UECC_ERR            REGBIT64(1, 11)
#define IRQ_BBS_SIM_BBS_LP_RUN_REQ  REGBIT64(1, 12)
#define IRQ_BBS_SIM_BBS_HS_RUN_REQ  REGBIT64(1, 13)
#define IRQ_CM0_CPU_SLEEP_DEEP      REGBIT64(1, 15)
#define IRQ_CM0_CPU_RESET_REQ       REGBIT64(1, 16)
#define IRQ_CM0_WDOG1_WDG_RSTO      REGBIT64(1, 17)
#define IRQ_CM0_CPU_LOCKUP          REGBIT64(1, 18)
#define IRQ_CM0_UECC_ERR            REGBIT64(1, 19)
#define IRQ_LPI2C1_IPG_STOP_ACK     REGBIT64(1, 20)
#define IRQ_LPUART1_IPG_STOP_ACK    REGBIT64(1, 21)
#define IRQ_CAAM_IPG_STOP_ACK       REGBIT64(1, 22)
#define IRQ_INTMUX_INT_OUT_ASYNC    REGBIT64(1, 24)
#define IRQ_MU_SIDEB                REGBIT64(1, 27)
/*@}*/

#endif /* SC_SS_SC_DSC_H */

/**@}*/

