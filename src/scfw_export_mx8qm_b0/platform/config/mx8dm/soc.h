/*
** ###################################################################
**
**     Copyright 2018-2019 NXP
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
 * Header file used to configure SoC specific features of the SCFW.
 * Includes info on memory map, DSC mapping, subsystem mapping, etc.
 *
 */
/*==========================================================================*/

#ifndef SC_SOC_H
#define SC_SOC_H

/* Includes */

#include "main/types.h"
#include "has_ss.h"
#include "fsl_device_registers.h"
#include "ss/drc/v1/dsc.h"

/* Configure DSCs */

/*! Macro to calculate DSC index */
#define DSC_IDX(X) ((sc_dsc_t) ((((uint32_t) (X)) - ((uint32_t) MSI0_BASE)) / 131072U))

/*! Macro to define AI_READ/WRITE */
#define ANA_READ(BASE_IDX, TOG, ADDRESS, RDATA) DSC_AIRegisterRead(BASE_IDX, TOG, ADDRESS, RDATA)
#define ANA_WRITE(BASE_IDX, TOG, ADDRESS, DATAWORD) DSC_AIRegisterWrite(BASE_IDX, TOG, ADDRESS, DATAWORD)
#define ANA_ENABLE_ANAMIX_AI(BASE_IDX) DSC_EnableAnamixAI(BASE_IDX)
#define ANA_ENABLE_PHYMIX_AI(BASE_IDX) DSC_EnablePhymixAI(BASE_IDX)

/*! Define for Refgen default trim in case of unfused part */
#define REFGEN_DEFAULT_TRIM     0x2BU

/*!
 * @name Defines for sc_dsc_t
 */
/*@{*/
#define SC_DSC_SC        	DSC_IDX(DSC_SC)         /* 0x01 */
#define	SC_DSC_GPU_0	 	DSC_IDX(DSC_GPU_0)      /* 0x16 */
#define	SC_DSC_DRC_0	 	DSC_IDX(DSC_DRC_0)      /* 0x12 */
#define	SC_DSC_HSLSIO		DSC_IDX(DSC_HSLSIO)     /* 0x13 */
#define	SC_DSC_CONN		 	DSC_IDX(DSC_CONN)       /* 0x16 */
#define	SC_DSC_VPU		 	DSC_IDX(DSC_VPU)        /* 0x14 */
#define	SC_DSC_CA72         DSC_IDX(DSC_A72)        /* 0x21 */
#define	SC_DSC_DB           DSC_IDX(DSC_DB)         /* 0x22 */
#define	SC_DSC_CM4_1        DSC_IDX(DSC_M4_1)       /* 0x23 */
#define	SC_DSC_IMG		 	DSC_IDX(DSC_IMG)        /* 0x24 */
#define	SC_DSC_DC_0         DSC_IDX(DSC_DC_0)       /* 0x27 */
#define	SC_DSC_DRC_1        DSC_IDX(DSC_DRC_1)      /* 0x2A */
#define	SC_DSC_ADMA         DSC_IDX(DSC_ADMA)       /* 0x29 */
#define SC_DSC_CM4_0     	DSC_IDX(DSC_M4_0)       /* 0x32 */
#define	SC_DSC_DI_HDMI	 	DSC_IDX(DSC_HDMI)       /* 0x34 */
#define	SC_DSC_CSI_1 		DSC_IDX(DSC_CSI_1)      /* 0x36 */
#define	SC_DSC_CSI_0		DSC_IDX(DSC_CSI_0)      /* 0x38 */
#define	SC_DSC_DI_MIPI_0	DSC_IDX(DSC_MIPI_0)     /* 0x3A */
#define	SC_DSC_DI_LVDS_0	DSC_IDX(DSC_LVDS_0)     /* 0x3B */
#define SC_DSC_LAST      	0x3FU
#define SC_DSC_NA           SC_DSC_LAST
#define SC_DSC_W            6U
/*@}*/

/*!
 * DSC Type. This type is a used to indicate a Distributed Slave
 * Controller (DSC).
 */
typedef uint8_t sc_dsc_t;

/*!
 * @name Defines for sc_ai_t
 */
/*@{*/
#define SC_AI_HP_PLL            0U
#define SC_AI_DIG_PLL           1U
#define SC_AI_AV_PLL            2U
#define SC_AI_MLB_PLL           3U
#define SC_AI_BANDGAP_REF       4U
#define SC_AI_VA_REFGEN         5U
#define SC_AI_NEG_CHARGE_PUMP   6U
#define SC_AI_WELL_LEVEL_SOURCE 7U
#define SC_AI_DIFFCLK_ROOT      8U
#define SC_AI_DIFFCLK_RPTR      9U
#define SC_AI_DIFFCLK_TERM      10U
#define SC_AI_PHY_LDO           11U
#define SC_AI_OSC24M            12U
#define SC_AI_RC200OSC          13U
#define SC_AI_TEMP_SENSE        14U
#define SC_AI_VDROP_PROCMON     15U
#define SC_AI_LVDS_TRANS        16U
#define SC_AI_LAST              17U
/*@}*/

/*!
 * Analog Interface Modules Types.
 */
typedef uint8_t sc_ai_t;

/* Configure Subsystems */

typedef uint8_t sc_ss_inst_t;

#define SC_SS_INST_W        1U

/*!
 * Subsystem Type. This type is used to indicate a subsystem.
 */
/*@{*/
#define SC_SUBSYS_SC        0U
#define SC_SUBSYS_M4_0      1U
#define SC_SUBSYS_M4_1      2U
#define SC_SUBSYS_A72       3U
#define SC_SUBSYS_GPU_0     4U
#define SC_SUBSYS_VPU       5U
#define SC_SUBSYS_DC_0      6U
#define SC_SUBSYS_IMG       7U
#define SC_SUBSYS_ADMA      8U
#define SC_SUBSYS_CONN      9U
#define SC_SUBSYS_DB        10U
#define SC_SUBSYS_DRC_0     11U
#define SC_SUBSYS_DRC_1     12U
#define SC_SUBSYS_HSLSIO    13U
#define SC_SUBSYS_LVDS_0    14U
#define SC_SUBSYS_CSI_0     15U
#define SC_SUBSYS_CSI_1     16U
#define SC_SUBSYS_HDMI      17U
#define SC_SUBSYS_MIPI_0    18U
#define SC_SUBSYS_LAST      SC_SUBSYS_MIPI_0
#define SC_SUBSYS_W         5U
#define SC_SUBSYS_NA        31U
/*@}*/

/*!
 * Subsystem Type. This type is used to indicate a subsystem.
 */
typedef uint8_t sc_sub_t;

#define SC_PGP_00           0U
#define SC_PGP_01           1U
#define SC_PGP_02           2U
#define SC_PGP_03           3U
#define SC_PGP_10           4U
#define SC_PGP_11           5U
#define SC_PGP_12           6U
#define SC_PGP_13           7U
#define SC_PGP_20           8U
#define SC_PGP_21           9U
#define SC_PGP_22           10U
#define SC_PGP_23           11U
#define SC_PGP_30           12U
#define SC_PGP_31           13U
#define SC_PGP_32           14U
#define SC_PGP_33           15U

#define SC_PGP_W            5U
#define SC_PGP_NA           16U

#define  MTR_PWR_PLAN_SEL_SCU               0U
#define  MTR_PWR_PLAN_SEL_CM4_0             1U
#define  MTR_PWR_PLAN_SEL_CM4_1             2U
#define  MTR_PWR_PLAN_SEL_GPU3D_1           3U
#define  MTR_PWR_PLAN_SEL_LSIO              4U
#define  MTR_PWR_PLAN_SEL_GPU3D_0           5U
#define  MTR_PWR_PLAN_SEL_CA53              6U
#define  MTR_PWR_PLAN_SEL_DBLOG             7U
#define  MTR_PWR_PLAN_SEL_CA72              8U
#define  MTR_PWR_PLAN_SEL_HSIO              9U
#define  MTR_PWR_PLAN_SEL_DRC_0             10U
#define  MTR_PWR_PLAN_SEL_DB                11U
#define  MTR_PWR_PLAN_SEL_DC_1              12U
#define  MTR_PWR_PLAN_SEL_VPU_A53           13U
#define  MTR_PWR_PLAN_SEL_CONNECTIVITY      14U
#define  MTR_PWR_PLAN_SEL_DMA               15U
#define  MTR_PWR_PLAN_SEL_VPU               16U
#define  MTR_PWR_PLAN_SEL_MIPI_CSI_0        17U
#define  MTR_PWR_PLAN_SEL_MIPI_CSI_1        18U
#define  MTR_PWR_PLAN_SEL_DRC_1             19U
#define  MTR_PWR_PLAN_SEL_DC_0              20U
#define  MTR_PWR_PLAN_SEL_RX_HDMI           21U
#define  MTR_PWR_PLAN_SEL_IMAGING           22U
#define  MTR_PWR_PLAN_SEL_AUDIO             23U
#define  MTR_PWR_PLAN_SEL_DI_HDMI           24U
#define  MTR_PWR_PLAN_SEL_DI_MIPI_0         25U
#define  MTR_PWR_PLAN_SEL_DI_MIPI_1         26U

#define SC_SS_INFO_INIT                                                                             \
    {HAS_SS_SC,      0, SC_PGP_21,   SC_SUBSYS_NA,  0,  0, SC_DSC_SC},          /* SC_SUBSYS_SC */      \
    {HAS_SS_M4_0,    0, SC_PGP_22,   SC_SUBSYS_NA,  0,  0, SC_DSC_CM4_0},       /* SC_SUBSYS_M4_0 */    \
    {HAS_SS_M4_1,    1, SC_PGP_23,   SC_SUBSYS_NA,  0,  0, SC_DSC_CM4_1},       /* SC_SUBSYS_M4_1 */    \
    {HAS_SS_A72,     0, SC_PGP_02,   SC_SUBSYS_NA,  0,  0, SC_DSC_CA72},        /* SC_SUBSYS_A72 */     \
    {HAS_SS_GPU_0,   0, SC_PGP_10,   SC_SUBSYS_NA,  0,  0, SC_DSC_GPU_0},       /* SC_SUBSYS_GPU_0 */   \
    {HAS_SS_VPU,     0, SC_PGP_11,   SC_SUBSYS_NA,  0,  0, SC_DSC_VPU},         /* SC_SUBSYS_VPU */     \
    {HAS_SS_DC_0,    0, SC_PGP_30,  SC_SUBSYS_IMG, 23,  0, SC_DSC_DC_0},        /* SC_SUBSYS_DC_0 */    \
    {HAS_SS_IMG,     0, SC_PGP_20,   SC_SUBSYS_NA,  0,  0, SC_DSC_IMG},         /* SC_SUBSYS_IMG */     \
    {HAS_SS_ADMA,    0, SC_PGP_31,   SC_SUBSYS_NA,  0,  0, SC_DSC_ADMA},        /* SC_SUBSYS_ADMA */    \
    {HAS_SS_CONN,    0, SC_PGP_01,   SC_SUBSYS_NA,  0,  0, SC_DSC_CONN},        /* SC_SUBSYS_CONN */    \
    {HAS_SS_DB,      0, SC_PGP_NA,   SC_SUBSYS_NA,  0,  0, SC_DSC_DB},          /* SC_SUBSYS_DB */      \
    {HAS_SS_DRC_0,   0, SC_PGP_NA,   SC_SUBSYS_NA,  0,  0, SC_DSC_DRC_0},       /* SC_SUBSYS_DRC_0 */   \
    {HAS_SS_DRC_1,   1, SC_PGP_NA,   SC_SUBSYS_NA,  0,  0, SC_DSC_DRC_1},       /* SC_SUBSYS_DRC_1 */   \
    {HAS_SS_HSLSIO,  0, SC_PGP_00,   SC_SUBSYS_NA,  0,  0, SC_DSC_HSLSIO},      /* SC_SUBSYS_HSLSIO */  \
    {HAS_SS_LVDS_1,  1, SC_PGP_NA, SC_SUBSYS_DC_0, 12,  0, SC_DSC_DI_LVDS_0},   /* SC_SUBSYS_LVDS_0 */  \
    {HAS_SS_CSI_0,   0, SC_PGP_NA,  SC_SUBSYS_IMG, 21, 18, SC_DSC_CSI_0},       /* SC_SUBSYS_CSI_0 */   \
    {HAS_SS_CSI_1,   1, SC_PGP_NA,  SC_SUBSYS_IMG, 22, 19, SC_DSC_CSI_1},       /* SC_SUBSYS_CSI_1 */   \
    {HAS_SS_HDMI,    0, SC_PGP_NA, SC_SUBSYS_DC_0, 13,  0, SC_DSC_DI_HDMI},     /* SC_SUBSYS_HDMI */    \
    {HAS_SS_MIPI_0,  0, SC_PGP_NA, SC_SUBSYS_DC_0, 11,  0, SC_DSC_DI_MIPI_0}    /* SC_SUBSYS_MIPI_0 */  \

#define SC_SS_EP_INIT                             \
    SS_EP_INIT_SC,        /* SC_SUBSYS_SC */      \
    SS_EP_INIT_M4,        /* SC_SUBSYS_M4_0 */    \
    SS_EP_INIT_M4,        /* SC_SUBSYS_M4_1 */    \
    SS_EP_INIT_A72,       /* SC_SUBSYS_A72 */     \
    SS_EP_INIT_GPU,       /* SC_SUBSYS_GPU_0 */   \
    SS_EP_INIT_VPU,       /* SC_SUBSYS_VPU */     \
    SS_EP_INIT_DC,        /* SC_SUBSYS_DC_0 */    \
    SS_EP_INIT_IMG,       /* SC_SUBSYS_IMG */     \
    SS_EP_INIT_ADMA,      /* SC_SUBSYS_ADMA */    \
    SS_EP_INIT_CONN,      /* SC_SUBSYS_CONN */    \
    SS_EP_INIT_DB,        /* SC_SUBSYS_DB */      \
    SS_EP_INIT_DRC,       /* SC_SUBSYS_DRC_0 */   \
    SS_EP_INIT_DRC,       /* SC_SUBSYS_DRC_1 */   \
    SS_EP_INIT_HSLSIO,    /* SC_SUBSYS_HSLSIO */  \
    SS_EP_INIT_LVDS,      /* SC_SUBSYS_LVDS_0 */  \
    SS_EP_INIT_CSI,       /* SC_SUBSYS_CSI_0 */   \
    SS_EP_INIT_CSI,       /* SC_SUBSYS_CSI_1 */   \
    SS_EP_INIT_HDMI,      /* SC_SUBSYS_HDMI */    \
    SS_EP_INIT_MIPI       /* SC_SUBSYS_MIPI_0 */  \

#define SC_SS_BASE_INFO_INIT                        \
    &ss_base_info_sc,       /* SC_SUBSYS_SC */      \
    &ss_base_info_m4,       /* SC_SUBSYS_M4_0 */    \
    &ss_base_info_m4,       /* SC_SUBSYS_M4_1 */    \
    &ss_base_info_a72,      /* SC_SUBSYS_A72 */     \
    &ss_base_info_gpu,      /* SC_SUBSYS_GPU_0 */   \
    &ss_base_info_vpu,      /* SC_SUBSYS_VPU */     \
    &ss_base_info_dc,       /* SC_SUBSYS_DC_0 */    \
    &ss_base_info_img,      /* SC_SUBSYS_IMG */     \
    &ss_base_info_adma,     /* SC_SUBSYS_ADMA */    \
    &ss_base_info_conn,     /* SC_SUBSYS_CONN */    \
    &ss_base_info_db,       /* SC_SUBSYS_DB */      \
    &ss_base_info_drc,      /* SC_SUBSYS_DRC_0 */   \
    &ss_base_info_drc,      /* SC_SUBSYS_DRC_1 */   \
    &ss_base_info_hslsio,   /* SC_SUBSYS_HSLSIO */  \
    &ss_base_info_lvds,     /* SC_SUBSYS_LVDS_0 */  \
    &ss_base_info_csi,      /* SC_SUBSYS_CSI_0 */   \
    &ss_base_info_csi,      /* SC_SUBSYS_CSI_1 */   \
    &ss_base_info_hdmi,     /* SC_SUBSYS_HDMI */    \
    &ss_base_info_mipi      /* SC_SUBSYS_MIPI_0 */  \

#ifdef DEBUG
    #define SNAME_INIT  \
        "SC",           \
        "M4_0",         \
        "M4_1",         \
        "A72",          \
        "GPU_0",        \
        "VPU",          \
        "DC_0",         \
        "IMG",          \
        "ADMA",         \
        "CONN",         \
        "DB",           \
        "DRC_0",        \
        "DRC_1",        \
        "HSLSIO",       \
        "LVDS_0",       \
        "CSI_0",        \
        "CSI_1",        \
        "HDMI",         \
        "MIPI_0"

    #define RNAME_INIT          \
        RNAME_INIT_SC_0         \
        RNAME_INIT_M4_0         \
        RNAME_INIT_M4_1         \
        RNAME_INIT_A72_0        \
        RNAME_INIT_GPU_0        \
        RNAME_INIT_VPU_0        \
        RNAME_INIT_DC_0         \
        RNAME_INIT_IMG_0        \
        RNAME_INIT_ADMA_0       \
        RNAME_INIT_CONN_0       \
        RNAME_INIT_DB_0         \
        RNAME_INIT_DRC_0        \
        RNAME_INIT_DRC_1        \
        RNAME_INIT_HSLSIO_0     \
        RNAME_INIT_LVDS_0       \
        RNAME_INIT_CSI_0        \
        RNAME_INIT_CSI_1        \
        RNAME_INIT_HDMI_0       \
        RNAME_INIT_MIPI_0       \
        RNAME_INIT_BRD

#endif

#define SC_R_DDR        SC_R_DRC_0
#define SC_R_DDR_PLL    SC_R_DRC_0_PLL

/* Configure Top Level Memory Map */

#define SC_MEMMAP_INIT                                                         \
    { LSIO_SS_BASE1,    0x1C000000U, 1, 1, 30, 1, 0x00, SC_SUBSYS_HSLSIO},     \
    {  VPU_SS_BASE1,     0x4000000U, 0, 1, 26, 1, 0x00, SC_SUBSYS_VPU},        \
    {  SCU_SS_BASE0,     0x4000000U, 0, 1, 26, 0, 0x00, SC_SUBSYS_SC},         \
    { M4_0_SS_BASE0,     0x4000000U, 1, 1, 26, 0, 0x00, SC_SUBSYS_M4_0},       \
    { M4_1_SS_BASE0,     0x4000000U, 1, 1, 26, 0, 0x00, SC_SUBSYS_M4_1},       \
    {DBLOG_SS_BASE0,     0x1000000U, 0, 1, 24, 2, 0x00, SC_SUBSYS_ADMA},       \
    {   AP_SS_BASE0,     0x1000000U, 0, 1, 24, 0, 0x00, SC_SUBSYS_A72},        \
    {GPU_0_SS_BASE0,     0x1000000U, 0, 1, 24, 0, 0x00, SC_SUBSYS_GPU_0},      \
    {  VPU_SS_BASE0,     0x1000000U, 0, 1, 24, 1, 0x00, SC_SUBSYS_VPU},        \
    { DC_0_SS_BASE0,     0x1000000U, 0, 1, 24, 0, 0x00, SC_SUBSYS_DC_0},       \
    {  IMG_SS_BASE0,     0x1000000U, 0, 1, 24, 0, 0x00, SC_SUBSYS_IMG},        \
    {AUDIO_SS_BASE0,     0x1000000U, 0, 1, 24, 0, 0x00, SC_SUBSYS_ADMA},       \
    {  DMA_SS_BASE0,     0x1000000U, 0, 1, 24, 1, 0x00, SC_SUBSYS_ADMA},       \
    { CONN_SS_BASE0,     0x1000000U, 0, 1, 24, 0, 0x00, SC_SUBSYS_CONN},       \
    {   DB_SS_BASE0,     0x1000000U, 0, 1, 24, 0, 0x00, SC_SUBSYS_DB},         \
    { LSIO_SS_BASE0,     0x1000000U, 0, 1, 24, 0, 0x1D, SC_SUBSYS_HSLSIO},     \
    { HSIO_SS_BASE0,     0x1000000U, 0, 1, 24, 0, 0x1F, SC_SUBSYS_HSLSIO},     \
    { HSIO_SS_BASE1,    0x10000000U, 1, 1, 28, 0, 0x20, SC_SUBSYS_HSLSIO},     \
    { HSIO_SS_BASE2,    0x10000000U, 1, 1, 28, 0, 0x30, SC_SUBSYS_HSLSIO},     \
    {     DDR_BASE0,    0x80000000U, 1, 0,  0, 0, 0x00, SC_SUBSYS_DB},         \
    { LSIO_SS_BASE2,    0x40000000U, 1, 1, 30, 2, 0x00, SC_SUBSYS_HSLSIO},     \
    {     DDR_BASE1, 0x780000000ULL, 1, 0,  0, 0, 0x00, SC_SUBSYS_DB},         \
    {         SC_NA,          SC_NA, 0, 0,  0, 0, 0, 0}

#define SC_R_ROM    SC_R_OCRAM

#define SC_BOOT_ADDR_INIT                                                     \
    {OCRAM_ALIAS_BASE,       0x17FFFU, SC_R_OCRAM,     SC_SUBSYS_HSLSIO},     \
    {      OCRAM_BASE,       0x3FFFFU, SC_R_OCRAM,     SC_SUBSYS_HSLSIO},     \
    {  FSPI0_MEM_BASE,    0x10000000U, SC_R_FSPI_0,    SC_SUBSYS_HSLSIO},     \
    {      TCML1_BASE,     0x4000000U, SC_R_M4_0_PID0, SC_SUBSYS_M4_0},       \
    {      TCML2_BASE,     0x4000000U, SC_R_M4_1_PID0, SC_SUBSYS_M4_1},       \
    {       DDR_BASE0,    0x80000000U, SC_R_DRC_0,     SC_SUBSYS_DRC_0},      \
    {  FSPI1_MEM_BASE,    0x40000000U, SC_R_FSPI_1,    SC_SUBSYS_HSLSIO},     \
    {   HSIO_SS_BASE0,     0x1000000U, SC_R_SATA_0,    SC_SUBSYS_HSLSIO},     \
    {       DDR_BASE1, 0x780000000ULL, SC_R_DRC_0,     SC_SUBSYS_DRC_0},      \
    {           SC_NA,          SC_NA, 0U,             0U}

/* Configure Features */

/*! Standard DSCMIX clock rate */
#define SC_DSCMIX               SC_400MHZ

/*! MAX HP PLL frequency */
#define DIV_FACTOR_NUM          2
#define DIV_FACTOR_DEN          3

/*! Define to indicate SoC DSC has AI */
#ifndef NO_DEVICE_ACCESS
    #define SC_DSC_AI
#endif

/*! Define to use SECO FW */
#define HAS_SECO_FW
#define SECO_FW_VERSION ((2UL << 16) | (3UL << 4) | 1UL)
#define SECO_FW_NDELAY  ((0UL << 16) | (3UL << 4) | 0UL)

/*! Define to use MIPI DSI/CSI trim */
#define HAS_DSI_VOH_TRIM

/*! Define to decide when to relock PLLs enabled by ROM. */
#define FSL_FEATURE_RELOCK_ROM_LOCKED_PLL   (0U)

/*! Define DDR DATX8 Lanes */
#define DWC_NO_OF_BYTES	4

/*! Define to support ROM function calls */
#define SC_ROM_FUNC_ADDR    0x00000580U
#define SC_ROM_FUNC_TAG     0xEA90U
#define SC_ROM_FUNC_VER     0x0001U

/*! Defines for AI temp sensor */
#define AI_TEMP_RATE            1000U
#define AI_TEMP_NP              1915
#define AI_TEMP_NT              25
#define AI_TEMP_PANIC           127

/*!
 * Define operating points for A72 and GPU.
 */
#define NUM_GPU_OPP         3
#define NUM_A72_OPP         4

/*! Define to indicate timer services required */
#define HAS_TIMER_SERVICES

/* Define boot cpu and address based on whether or
   not we're running the DDR stress test */
#ifdef M4_BOOT
    #define BOOT_CPU            SC_R_M4_0_PID0
    #define BOOT_ADDR           0x000000000ULL
    #define BOOT_MU             SC_R_M4_0_MU_1A
    #define BOOT_CPU_STARTS     1U
    #define BOOT_SRC            0x00040000U
    #define BOOT_DST            0x34FE0000U
    #define BOOT_SIZE           0x20000U
    #define BOOT_FLAGS          0x00000000U
#else
    #define BOOT_CPU            SC_R_A72_0
    #define BOOT_ADDR           0x080000000UL
    #define BOOT_MU             SC_R_MU_0A
    #define BOOT_CPU_STARTS     1U
    #define BOOT_FLAGS          0x00000000U
#endif

/* Boot data address */
#define SC_BOOT_DATA_ADDR_PTR   0x000005F0U
#define SC_BOOT_DATA_ADDR       0x2001FC00U
#define SC_BOOT_DATA2_ADDR      0x2001FD00U
#define SC_BOOT_PASSOVER_ADDR   0x0010FD00U
#define SC_BOOT_DATA_USB_ADDR   0x80000000U

/* Config IROB */
#define SC_IROB_CONFIG          SC_IROB_4K

/* Configure Tests */
#define SC_R_PCIE               SC_R_PCIE_A
#define SC_R_SERDES             SC_R_SERDES_0

/*! Define to indicate number of CAAM job rings */
#define SC_CAAM_JR              4U

/*! Define to indicate number of MU */
#define SC_SECO_MU              4U

/* Configure IVT */
#define SC_IVT_MAX_NUM_IMGS            4U
#define SC_IVT_MAX_HW_CFG_SIZE_V2      359U
#define SC_IVT_MAX_NUM_OF_CONTAINER    2U
#define SC_IVT_HEADER_TAG			   0xD1U
#define SC_IVT_HAS_SCD_PTR

/* Define CPU topology */
#define SOC_NUM_CLUSTER         1U
#define SOC_IDX_A72             0U
#define SOC_NUM_A72             2U

/* Define M4 topology */
#define SOC_NUM_M4              2U
#define SOC_IDX_M4_0            0U
#define SOC_IDX_M4_1            1U

/* Define HMP topology */
#define SOC_NUM_HMP_NODES       4U
#define SOC_HMP_IDX_SCU         0U                  /* SCU must be index 0 */
#define SOC_HMP_IDX_M4_0        1U                  /* M4 order must follow topology above */
#define SOC_HMP_IDX_M4_1        2U
#define SOC_HMP_IDX_A72         3U
#define SOC_HMP_IDX_M4          SOC_HMP_IDX_M4_0
#define SOC_HMP_IDX_AP          SOC_HMP_IDX_A72

/* Define system-level interface topology */
#define SOC_NUM_SYS_IF          4U                  /* Number of system-level interfaces */
#define SOC_SYS_IF_MU_RSRC      5U                  /* Number of AP -> SCU message unit resources */
#define SOC_SYS_IF_ICN_RSRC     3U                  /* Number of interconnect resources */
#define SOC_SYS_IF_OCMEM_RSRC   3U                  /* Number of on-chip memory resources */
#define SOC_SYS_IF_DDR_RSRC     2U                  /* Number of DDR resources */
#define SOC_SYS_IF_CPU_HPM      SC_PM_PW_MODE_LP    /* CPU power mode threshold for HPM */

/* Define wakeup bindings */
#define SOC_GIC_DSC             SC_DSC_ADMA         /* DSC for GIC wakeups */
#define SOC_IRQSTEER_DSC        SC_DSC_ADMA         /* DSC for IRQSTEER wakeup */
#define SOC_GIC_WAKEUP00        REGBIT64(1, 0)      /* DSC IRQ for GIC wakeups */
#define SOC_IRQSTEER_AP_WAKEUP  REGBIT64(1, 11)     /* DSC IRQ for AP IRQSTEER wakeup */
#define SOC_IRQSTEER_M4_WAKEUP  REGBIT64(1, 9)      /* DSC IRQ for M4 IRQSTEER wakeup */
#define SOC_WAKEUP_PW_MODE      SC_PM_PW_MODE_STBY  /* CPU power mode limit for GIC wakeup */
#define SOC_RESUME_PW_MODE      SC_PM_PW_MODE_ON    /* CPU power mode for resume */
#define SOC_M4_STOPM_PDN        3U                  /* STOPM >= 3 will power down M4 core */
#define SOC_M4_STOPM_MEMSR      3U                  /* STOPM == 3 will retain memories */

/* Define ADMA mbist */
#define SS_ADMA_BIST1 (((uint32_t)DSC_ADMA) + 0x8020U)
#define SS_ADMA_BIST1_START 230U
#define SS_ADMA_BIST1_END 233U

#define SS_ADMA_BIST3 (((uint32_t)DSC_ADMA) + 0x8040U)
#define SS_ADMA_BIST3_START 234U
#define SS_ADMA_BIST3_END 266U

/* Include SS configs */

#include "all_config.h"
#include "board/config.h"
#include "handlers_MX8DM.h"            /* Device specific handlers */

/* Configure Resources */

#define SC_NUM_RSRC             \
     (SS_NUM_RSRC_SC            \
    + SS_NUM_RSRC_M4            \
    + SS_NUM_RSRC_M4            \
    + SS_NUM_RSRC_A72           \
    + SS_NUM_RSRC_GPU           \
    + SS_NUM_RSRC_VPU           \
    + SS_NUM_RSRC_DC            \
    + SS_NUM_RSRC_IMG           \
    + SS_NUM_RSRC_ADMA          \
    + SS_NUM_RSRC_CONN          \
    + SS_NUM_RSRC_DB            \
    + SS_NUM_RSRC_DRC           \
    + SS_NUM_RSRC_DRC           \
    + SS_NUM_RSRC_HSLSIO        \
    + SS_NUM_RSRC_LVDS          \
    + SS_NUM_RSRC_CSI           \
    + SS_NUM_RSRC_CSI           \
    + SS_NUM_RSRC_HDMI          \
    + SS_NUM_RSRC_MIPI          \
    + BRD_NUM_RSRC_BRD)

#define SC_PAD_INIT_INIT                    \
    {SC_P_UART1_RTS_B,   3, 0},             \
    {SC_P_UART1_CTS_B,   3, 0},             \
    {SC_P_PMIC_I2C_SDA,  3, 0},             \
    {SC_P_PMIC_I2C_SCL,  3, 0},             \
    {SC_P_SAI1_RXC,      3, 0},             \
    {SC_P_SAI1_RXFS,     3, 0},             \
    {SC_P_USB_SS3_TC0,   3, 0},             \
    {SC_P_USB_SS3_TC1,   3, 0},             \
    {SC_P_USB_SS3_TC2,   3, 0},             \
    {SC_P_USB_SS3_TC3,   3, 0},             \
    {0, 0, 0}

#define SC_ROM_SS_INIT              \
    0,      /* SC_SUBSYS_SC */      \
    1,      /* SC_SUBSYS_M4_0 */    \
    2,      /* SC_SUBSYS_M4_1 */    \
    3,      /* SC_SUBSYS_CCI */     \
    4,      /* SC_SUBSYS_A53 */     \
    5,      /* SC_SUBSYS_A72 */     \
    6,      /* SC_SUBSYS_GPU_0 */   \
    7,      /* SC_SUBSYS_GPU_1 */   \
    8,      /* SC_SUBSYS_VPU */     \
    10,     /* SC_SUBSYS_DC_0 */    \
    11,     /* SC_SUBSYS_DC_1 */    \
    12,     /* SC_SUBSYS_IMG */     \
    13,     /* SC_SUBSYS_AUDIO */   \
    14,     /* SC_SUBSYS_DMA */     \
    15,     /* SC_SUBSYS_CONN */    \
    16,     /* SC_SUBSYS_DB */      \
    17,     /* SC_SUBSYS_DBLOGIC */ \
    18,     /* SC_SUBSYS_DRC_0 */   \
    19,     /* SC_SUBSYS_DRC_1 */   \
    20,     /* SC_SUBSYS_LSIO */    \
    21,     /* SC_SUBSYS_HSIO */    \
    22,     /* SC_SUBSYS_LVDS_0 */  \
    23,     /* SC_SUBSYS_LVDS_1 */  \
    24,     /* SC_SUBSYS_CSI_0 */   \
    25,     /* SC_SUBSYS_CSI_1 */   \
    26,     /* SC_SUBSYS_HDMI_RX */ \
    27,     /* SC_SUBSYS_HDMI */    \
    28,     /* SC_SUBSYS_MIPI_0 */  \
    29      /* SC_SUBSYS_MIPI_1 */

#endif /* SC_SOC_H */

