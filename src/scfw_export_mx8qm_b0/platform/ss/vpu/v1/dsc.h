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
 * @addtogroup VPU_SS
 * @{
 */
/*==========================================================================*/

#ifndef SC_SS_VPU_DSC_H
#define SC_SS_VPU_DSC_H

/* Includes */

#include "ss/base/dsc.h"

/*!
 * @name Reset Bit Definitions
 */
/*@{*/
#define RST_MED_CORE_DEC        REGBIT(0, 2)
#define RST_MED_CORE_ENC        REGBIT(0, 3)
#define RST_MED_CORE_BISR       REGBIT(0, 7)
/*@}*/

/*!
 * @name GPR Control 0 Bit Definitions
 */
/*@{*/
#define GPR_CLK_GATE_EN         REGBIT(0, 8)
#define GPR_XUVI_MODE           REGBIT(0, 16)
/*@}*/

/*!
 * @name SS IRQ Mask Definitions
 */
/*@{*/
#define IRQ_ECC                 REGBIT64(1, 0)
#define IRQ_WAKE0               REGBIT64(1, 1)
#define IRQ_WAKE1               REGBIT64(1, 2)
#define IRQ_WAKE2               REGBIT64(1, 3)
#define IRQ_WAKE3               REGBIT64(1, 4)
/*@}*/

#endif /* SC_SS_VPU_DSC_H */

/**@}*/

