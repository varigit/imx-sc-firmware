/*
** ###################################################################
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
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
 * @addtogroup DB_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_DB_DSC_H
#define SC_SS_DB_DSC_H

/* Includes */

#include "ss/base/dsc.h"

/*!
 * @name GPR Control 0 Bit Definitions
 */
/*@{*/
#define GPR_SSI2_PM                 REGBIT(0, 8)
#define GPR_SSI2_BHM                REGBIT(0, 9)
#define GPR_SSI3_PM                 REGBIT(0, 10)
#define GPR_SSI3_BHM                REGBIT(0, 11)
#define GPR_SSI4_PM                 REGBIT(0, 12)
#define GPR_SSI4_BHM                REGBIT(0, 13)
#define GPR_SSI5_PM                 REGBIT(0, 14)
#define GPR_SSI5_BHM                REGBIT(0, 15)
#define GPR_SSI6_PM                 REGBIT(0, 16)
#define GPR_SSI6_BHM                REGBIT(0, 17)
#define GPR_SSI7_PM                 REGBIT(0, 18)
#define GPR_SSI7_BHM                REGBIT(0, 19)
#define GPR_SSI8_PM                 REGBIT(0, 20)
#define GPR_SSI8_BHM                REGBIT(0, 21)
#define GPR_SSI9_PM                 REGBIT(0, 22)
#define GPR_SSI9_BHM                REGBIT(0, 23)
#define GPR_SSI10_PM                REGBIT(0, 24)
#define GPR_SSI10_BHM               REGBIT(0, 25)
#define GPR_SSI11_PM                REGBIT(0, 26)
#define GPR_SSI11_BHM               REGBIT(0, 27)
#define GPR_SSI12_PM                REGBIT(0, 28)
#define GPR_SSI12_BHM               REGBIT(0, 29)
#define GPR_SSI13_PM                REGBIT(0, 30)
#define GPR_SSI13_BHM               REGBIT(0, 31)
/*@}*/

/*!
 * @name GPR Control 1 Bit Definitions
 */
/*@{*/
#define GPR_SSI14_PM                REGBIT(1, 32)
#define GPR_SSI14_BHM               REGBIT(1, 33)
#define GPR_SSI15_PM                REGBIT(1, 34)
#define GPR_SSI15_BHM               REGBIT(1, 35)
#define GPR_SSI_DRC0_PM0            REGBIT(1, 36)
#define GPR_SSI_DRC0_PM1            REGBIT(1, 37)
#define GPR_SSI_DRC0_BHM0           REGBIT(1, 38)
#define GPR_SSI_DRC0_BHM1           REGBIT(1, 39)
#define GPR_SSI_DRC1_PM0            REGBIT(1, 40)
#define GPR_SSI_DRC1_PM1            REGBIT(1, 41)
#define GPR_SSI_DRC1_BHM0           REGBIT(1, 42)
#define GPR_SSI_DRC1_BHM1           REGBIT(1, 43)
#define GPR_TCU_SPF_BYPASS          REGBIT(1, 59)
#define GPR_ADB_PWRDNREQN           REGBIT(1, 60)
#define GPR_TBU_PD_QREQN            REGBIT(1, 61)
#define GPR_QEN                     REGBIT(1, 62)
#define GPR_SSI_IDLE_STRAP          REGBIT(1, 63)
/*@}*/

/*!
 * @name GPR Status 0 Bit Definitions
 */
/*@{*/
#define GPS_SSI2_SI                 REGBIT(0, 4)
#define GPS_SSI2_RI                 REGBIT(0, 5)
#define GPS_SSI3_SI                 REGBIT(0, 6)
#define GPS_SSI3_RI                 REGBIT(0, 7)
#define GPS_SSI4_SI                 REGBIT(0, 8)
#define GPS_SSI4_RI                 REGBIT(0, 9)
#define GPS_SSI5_SI                 REGBIT(0, 10)
#define GPS_SSI5_RI                 REGBIT(0, 11)
#define GPS_SSI6_SI                 REGBIT(0, 12)
#define GPS_SSI6_RI                 REGBIT(0, 13)
#define GPS_SSI7_SI                 REGBIT(0, 14)
#define GPS_SSI7_RI                 REGBIT(0, 15)
#define GPS_SSI8_SI                 REGBIT(0, 16)
#define GPS_SSI8_RI                 REGBIT(0, 17)
#define GPS_SSI9_SI                 REGBIT(0, 18)
#define GPS_SSI9_RI                 REGBIT(0, 19)
#define GPS_SSI10_SI                REGBIT(0, 20)
#define GPS_SSI10_RI                REGBIT(0, 21)
#define GPS_SSI11_SI                REGBIT(0, 22)
#define GPS_SSI11_RI                REGBIT(0, 23)
#define GPS_SSI12_SI                REGBIT(0, 24)
#define GPS_SSI12_RI                REGBIT(0, 25)
#define GPS_SSI13_SI                REGBIT(0, 26)
#define GPS_SSI13_RI                REGBIT(0, 27)
#define GPS_SSI14_SI                REGBIT(0, 28)
#define GPS_SSI14_RI                REGBIT(0, 29)
#define GPS_SSI15_SI                REGBIT(0, 30)
#define GPS_SSI15_RI                REGBIT(0, 31)
/*@}*/

/*!
 * @name GPR Status 1 Bit Definitions
 */
/*@{*/
#define GPS_SSI_DRC0_SI             REGBIT(1, 32)
#define GPS_SSI_DRC0_RI             REGBIT(1, 33)
#define GPS_SSI_DRC1_SI             REGBIT(1, 34)
#define GPS_SSI_DRC1_RI             REGBIT(1, 35)
#define GPS_ADB_PWRDNACKN           REGBIT(1, 36)
#define GPS_TBU_PD_QACCEPTN         REGBIT(1, 37)
#define GPS_CACTIVE_PG0             REGBIT(1, 38)
#define GPS_CACTIVE_PG1             REGBIT(1, 39)
#define GPS_CACTIVE_PG2             REGBIT(1, 40)
#define GPS_CACTIVE_PG3             REGBIT(1, 41)
#define GPS_CACTIVE_BN              REGBIT(1, 42)
#undef  GPS_SSI0_PM_DATA_PEND
#define GPS_SSI0_PM_DATA_PEND       REGBIT(1, 43)
#undef  GPS_SSI1_PM_DATA_PEND
#define GPS_SSI1_PM_DATA_PEND       REGBIT(1, 44)
#define GPS_SSI2_PM_DATA_PEND       REGBIT(1, 45)
#define GPS_SSI3_PM_DATA_PEND       REGBIT(1, 46)
#define GPS_SSI4_PM_DATA_PEND       REGBIT(1, 47)
#define GPS_SSI5_PM_DATA_PEND       REGBIT(1, 48)
#define GPS_SSI6_PM_DATA_PEND       REGBIT(1, 49)
#define GPS_SSI7_PM_DATA_PEND       REGBIT(1, 50)
#define GPS_SSI8_PM_DATA_PEND       REGBIT(1, 51)
#define GPS_SSI9_PM_DATA_PEND       REGBIT(1, 52)
#define GPS_SSI10_PM_DATA_PEND      REGBIT(1, 53)
#define GPS_SSI11_PM_DATA_PEND      REGBIT(1, 54)
#define GPS_SSI12_PM_DATA_PEND      REGBIT(1, 55)
#define GPS_SSI13_PM_DATA_PEND      REGBIT(1, 56)
#define GPS_SSI14_PM_DATA_PEND      REGBIT(1, 57)
#define GPS_SSI15_PM_DATA_PEND      REGBIT(1, 58)
#define GPS_SSI_DRC0_PM_DATA_PEND   REGBIT(1, 59)
#define GPS_SSI_DRC1_PM_DATA_PEND   REGBIT(1, 60)
/*@}*/

#endif /* SC_SS_DB_DSC_H */

/**@}*/

