/*
** ###################################################################
**
**     Copyright (c) 2016 Freescale Semiconductor, Inc.
**     Copyright 2017-2019 NXP
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
 * Header file containing the SoC API.
 *
 */
/*==========================================================================*/

#ifndef SC_SOC_API_H
#define SC_SOC_API_H

#define STC_RCAT_SETCAT(SS, CAT, CATMASK, CMP)              \
    STC_RCAT_SetCategorization(base_ptrs[                   \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi],                     \
    CAT, CATMASK, CMP)

#define STC_RCAT_SETSTARTSTOPTDM(SS, CAT, TDM, START, STOP)	\
    STC_RCAT_SetStartStopTDM(base_ptrs[		                \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi],	                    \
    CAT, TDM, START, STOP)

#define STC_RCAT_GETHPR(SS, CAT)                            \
    STC_RCAT_GetHPR(base_ptrs[                              \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi], CAT)

#define STC_RCAT_SETHPR(SS, CAT, HPR)                       \
	STC_RCAT_SetHPR(base_ptrs[sc_ss_info[                   \
	SC_SUBSYS_##SS].db_ssi], CAT, HPR)

#define STC_QOS_PANIC(SS, CAT, QOS)                         \
    STC_QOS_Panic(base_ptrs[                                \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi],                     \
    CAT, QOS)

#define STC_UD_THRESHOLD1(SS, CAT, TH)                      \
    STC_UD_EnableThreshold1(base_ptrs[                      \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi],                     \
    CAT, TH)

#define STC_UD_THRESHOLD2(SS, CAT, TH)                      \
    STC_UD_EnableThreshold2(base_ptrs[                      \
    sc_ss_info[SC_SUBSYS_##SS].db_ssi],                     \
    CAT, TH)

/* Indicator for system interface resources to manage power
 * mode directly (i.e. no save/restore).
 */
#define SOC_SYS_IF_NO_SAVE      (SC_PM_PW_MODE_ON + 1U)

#define SOC_RR                  1U
#define SOC_RR_CHECK(X)         ((((X) >> 24U) & 0xFFUL) == 0xCCUL)
#define SOC_RR_INFO(R, P)       ((0xCCUL << 24U) | (U32(R) << 8U) | U32(P))
#define SOC_RR_REASON(X)        (((X) >> 8U) & 0xFFUL)
#define SOC_RR_PT(X)            (((X) >> 0U) & 0xFFUL)

typedef struct
{
    uint32_t freq;
    uint32_t volt;
    uint8_t fbb;
} freq_volt_tbl_t;

typedef struct
{
    uint32_t shader_clk;
    uint32_t core_clk;
    uint32_t ahb_clk;
    uint32_t axi_ssi_clk;
} gpu_clks_opp_t;

/*
 * Stores CPU power state info 
 */
typedef struct
{
    sc_rm_idx_t rm_idx;
    sc_pm_power_mode_t req_mode;
    sc_bool_t lpm_active;
    sc_bool_t rst_req;
    uint8_t wake_idx;
    sc_pm_wake_src_t wake_src;
    sc_faddr_t resume_addr;
} soc_cpu_state_t;

/*
 * Stores cluster power state info 
 */
typedef struct
{
    sc_rm_idx_t rm_idx;
    uint8_t num_cpu;
    soc_cpu_state_t *cpu_state;
    sc_pm_power_mode_t req_mode;
} soc_cluster_state_t;

/*
 * Stores multi-cluster power state info 
 */
typedef struct
{
    sc_rm_idx_t rm_idx;
    soc_cluster_state_t *cluster_state;
    sc_pm_power_mode_t req_mode;
} soc_multicluster_state_t;

/*
 * Stores M4 sleep state info 
 */
typedef struct
{
    sc_rm_idx_t wic_rm_idx;
    sc_rm_idx_t sc_mu_rm_idx;
    sc_bool_t    dsm_req;
    sc_bool_t    dsm_active;
    sc_bool_t    rst_req;
    uint8_t stopm;
    uint8_t pstopo;    
    sc_faddr_t resume_addr;
} soc_m4_state_t;

/*
 * Stores system interface node resource info
 */
typedef struct
{
    sc_rm_idx_t num_rm_idx;             /* Number of resources in the node */
    const sc_rsrc_t *rsrc;              /* Resource array for node */
    sc_rm_idx_t *rm_idx;                /* Resource index array for node */
    sc_pm_power_mode_t *saved_pm;       /* Saved power mode array for node */
} soc_sys_if_node_t;

/*
 * Stores system interface power mode reqest info 
 */
typedef struct
{
    sc_pm_power_mode_t hpm;     /* High-power mode for system interface */
    sc_pm_power_mode_t lpm;     /* Low-power mode for system interface */
} soc_sys_if_req_t;

/*
 * Stores HMP node power mode info   
 */
typedef struct
{
    sc_rm_idx_t rm_idx;
    soc_sys_if_req_t *sys_if_req;       /* System interface mode request array */    
} soc_hmp_node_t;

/*
 * Stores HMP system power mode info
 */
typedef struct
{
    uint8_t num_hmp;                    /* Number of HMP nodes */
    soc_hmp_node_t *hmp_node;           /* HMP node array */
    uint8_t num_sys_if;                 /* Number of system interace nodes */
    soc_sys_if_node_t *sys_if_node;     /* System interface node array */
    sc_rm_idx_t ap_gic_rm_idx;          /* AP GIC resource index */
    sc_rm_idx_t ap_irqstr_rm_idx;       /* AP IRQSTR resource index */
    uint8_t ap_resume_cluster_idx;   /* AP resume cluster index */
    uint8_t ap_resume_cpu_idx;       /* AP resume cpu index */
    sc_pm_power_mode_t ddr_mode;        /* DDR mode for SoC */
    sc_bool_t lpm_active;               /* LPM active boolean */
} soc_hmp_t;

/*
 * Stores DDR retention region info
 */
typedef struct
{
    const uint32_t addr;
    const uint32_t size;
    uint32_t * const buf;
} soc_ddr_ret_region_t;

/*
 * Stores DDR retention info
 */
typedef struct
{
    const uint32_t num_drc;                     /* Number of DRCs to retain */
    ddrc * const drc_inst;                      /* Buffer for DRC register retention */
    ddr_phy * const drc_phy_inst;               /* Buffer for DRC PHY register retention */
    const uint32_t num_region;                  /* Number of DDR retention regions */
    const soc_ddr_ret_region_t * const region;  /* Retention region array */
    uint32_t ddr_clk_rate;                      /* Clock rate to restore after retention */
} soc_ddr_ret_info_t;

/*
 * Stores MSI ring usecount
 */
typedef struct
{
    const sc_rsrc_t rsrc;
    uint16_t count;
    uint16_t ss_count;
} soc_msi_ring_usecount_t;

/* External variables */

#if (HAS_SS_GPU_0 || HAS_SS_GPU_1) && !defined(NO_GPU_CLKS)
    extern gpu_clks_opp_t gpu_clks[NUM_GPU_OPP];
#endif

#if (SOC_NUM_CLUSTER > 1U)
    extern soc_multicluster_state_t soc_multicluster_state;
#endif

extern soc_hmp_t soc_hmp;
extern soc_sys_if_req_t soc_sys_if_req[SOC_NUM_HMP_NODES][SOC_NUM_SYS_IF];
extern soc_m4_state_t soc_m4_state[SOC_NUM_M4];
extern soc_cluster_state_t soc_cluster_state[SOC_NUM_CLUSTER];

extern uint32_t soc_dpll_tbl_0[];
extern uint32_t soc_dpll_tbl_1[];

extern sc_rm_pt_t soc_reset_pt;
extern sc_pm_reset_reason_t soc_reset_rsn;

/* Functions */

/*!
 * This function initalizes the parts of the SoC.
 *
 * @param[in]     api_phase   flag indicating phase
 *
 */
void soc_init(boot_phase_t phase);

/*!
 * This function configures SCU resources.
 *
 * @param[in]     pt_sc       SCU partition
 * @param[in]     pt_boot     boot partition
 */
void soc_config_sc(sc_rm_pt_t pt_sc, sc_rm_pt_t pt_boot);

/*!
 * This function configures SECO resources.
 */
void soc_config_seco(void);

/*!
 * This function returns if a resource is available.
 *
 * @param[in]     rsrc        resource to check
 *
 * @return Returns SC_TRUE if the resource is available.
 */
sc_bool_t soc_rsrc_avail(sc_rsrc_t rsrc);

/*!
 * This function initalizes DDR.
 *
 * @param[in]     early       Boolean for early init
 *
 * @return Returns the sc_err_t.
 *
 */
sc_err_t soc_init_ddr(sc_bool_t early);

/*!
 * Enable/Disable anamix in some SS during init and low power mode.
 */
void soc_setup_anamix(sc_bool_t enable);

/*!
 * This function powers up the DSC anamix.
 *
 * @param[in]     dsc         DSC to affect
 */
void soc_dsc_powerup_anamix(sc_dsc_t dsc);

/*!
 * This function powers up the DSC phymix.
 *
 * @param[in]     dsc         DSC to affect
 */
void soc_dsc_powerup_phymix(sc_dsc_t dsc);

/*!
 * This function powers down the DSC anamix.
 *
 * @param[in]     dsc         DSC to affect
 */
void soc_dsc_powerdown_anamix(sc_dsc_t dsc);

/*!
 * This function powers down the DSC phymix.
 *
 * @param[in]     dsc         DSC to affect
 */
void soc_dsc_powerdown_phymix(sc_dsc_t dsc);


/*!
 * Setup HSIO repeaters for internal or external PCIE clock
 *
 * @param[in]     internal_clk         True if using internal clock
 * @param[in]     enable               True if powering up SS
 */
void soc_setup_hsio_repeater(sc_bool_t internal_clk, sc_bool_t enable);

/*!
 * This function returns the trim value for a temp sensor.
 *
 * @param[in]     dsc         DSC to affect
 *
 * @return Returns trim value.
 */
uint32_t soc_get_temp_trim(sc_dsc_t dsc);

/*!
 * This function identifies if the given pd has internal
 * or external switches.
 *
 *@param[in]      dsc            DSC to affect
 *@param[in]      pd             pd to affect
 *
 * @return    Returns SC_TRUE if the pd is internally switched,
 *            SC_FALSE if externally switched.
 */
sc_bool_t soc_pd_switchable(sc_dsc_t dsc, uint32_t pd);

sc_bool_t soc_pd_retention(sc_dsc_t dsc, uint32_t pd);

/*!
 * Return the DSCMIX clock slice index and type.
 * 
 * @param[out]       clk_type          DSC clock slice type
 * @param[out]       idx               DSC clock slice index
 * @param[out]       parent            DSC clock slice parent
 */
void soc_dsc_clock_info(dsc_clk_type_t *clk_type, uint32_t *idx, 
    sc_pm_clk_parent_t *parent);

/*!
 * Configure the STCs in the DB when it is powered up.
 */
void soc_db_stc_config(void);

/*!
 * Dumps registers of single analog module.
 *
 */
void soc_dsc_ai_dumpmodule(sc_dsc_t dsc, uint8_t tog, sc_ai_t ai);

/*!
 * Dumps registers of analog modules in a subsystem.
 */
void soc_dsc_ai_dump(sc_dsc_t dsc);

/*!
 * Allows for muxing out analog clocks and voltage levels.
 */
void soc_anamix_test_out(sc_dsc_t dsc);

/*!
 * Perform DIG PLL trim. 
 */
void soc_perform_dco_trim(sc_dsc_t dsc, uint32_t pll_index);

/*!
 * Return the type of memory used with the SS.   
 */
uint32_t soc_mem_type(sc_dsc_t dsc, uint32_t pd);

/*!
 * Calibrate REFGEN tree.   
 */
#ifdef AUTOCAL
void soc_autocal_refgen_tree(void);
#endif

void soc_self_refresh_power_down_clk_disable_entry(void);
void soc_refresh_power_down_clk_disable_exit(void);

sc_err_t soc_set_freq_voltage(sc_sub_t ss, uint32_t old_freq,
    uint32_t *new_freq, sc_bool_t pmic_change);

uint32_t soc_get_freq(sc_sub_t ss);

void soc_trans_pd(sc_sub_t ss, uint8_t pd,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);

sc_bool_t soc_fbb_enabled(sc_sub_t ss);
sc_bool_t soc_ss_has_fbb(sc_sub_t ss);
void soc_set_fbb(sc_sub_t ss, uint8_t fbb_mask, sc_bool_t enable,
    uint32_t delay);

sc_err_t soc_set_cpu_resume(uint8_t cluster_idx, uint8_t cpu_idx, 
    sc_bool_t isPrimary, sc_faddr_t resume_addr);

sc_err_t soc_set_m4_resume(uint8_t m4_idx,sc_faddr_t resume_addr);

sc_err_t soc_set_multicluster_power_mode(sc_pm_power_mode_t mode);

sc_err_t soc_set_cluster_power_mode(uint8_t cluster_idx,
    sc_pm_power_mode_t mode);

sc_err_t soc_set_cpu_power_mode(uint8_t cluster_idx, uint8_t cpu_idx,
    sc_pm_power_mode_t mode, sc_pm_wake_src_t wake_src);

sc_err_t soc_set_cpu_rst_mode(uint8_t cluster_idx, uint8_t cpu_idx, 
    sc_bool_t rst);
    
sc_err_t soc_set_m4_sleep_mode(uint8_t m4_idx, sc_bool_t dsm,
    uint8_t stopm, uint8_t pstopo);

sc_bool_t soc_get_m4_sleep_mode_active(uint8_t m4_idx);

sc_err_t soc_set_m4_rst_mode(uint8_t m4_idx, sc_bool_t rst);

sc_err_t soc_req_sys_if_power_mode(uint8_t hmp_idx, sc_pm_sys_if_t sys_if, 
    sc_pm_power_mode_t hpm, sc_pm_power_mode_t lpm);

sc_err_t soc_trans_sys_if_hpm(uint8_t hmp_idx);

sc_err_t soc_trans_sys_if_lpm(void);

sc_err_t soc_sync_sys_if_pm(void);

sc_err_t soc_trans_cpu_power_mode(uint8_t cluster_idx, uint8_t cpu_idx);

sc_err_t soc_trans_m4_power_mode(uint8_t m4_idx);

void soc_prewake_cpu(void);

sc_err_t soc_wake_cpu(uint8_t cluster_idx, uint8_t cpu_idx);

sc_err_t soc_wake_m4(uint8_t m4_idx);

sc_err_t soc_wake_lsio_mu(void);

sc_err_t soc_wake_m4_mu(uint8_t m4_idx);

void soc_wake_sys_if_interconnect(void);

sc_pm_power_mode_t soc_get_hmp_sys_power_mode(void);
void soc_ddr_config_retention(soc_ddr_ret_info_t *ddr_ret_info);
void soc_ddr_enter_retention(void);
void soc_ddr_exit_retention(void);
void soc_ddr_dqs2dq_init(void);
void soc_ddr_dqs2dq_periodic(void);
void soc_drc_lpcg_setup(void);
int8_t soc_get_temp_ofs(sc_dsc_t dsc);
uint32_t soc_get_max_freq(sc_dsc_t dsc_id);
void soc_dump_hmp_power_state(void);
sc_bool_t soc_slice_is_dsc(const dsc_clk_info_t *clk_info);
uint8_t soc_mem_pwr_plane(sc_dsc_t dsc_id);
void soc_setup_msi_slave_ring(sc_sub_t cur_ss, sc_sub_t parent,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);
void soc_msi_ring_workaround(sc_pm_power_mode_t from_mode,
    sc_pm_power_mode_t to_mode, soc_msi_ring_usecount_t *msi_slv_ring,
    uint32_t num_msi_slaves, MSI_MSTR_Type *msi_reg, sc_sub_t cur_ss);
sc_bool_t soc_is_audio_pll(sc_dsc_t dsc, uint8_t pll_index);
void soc_trans_bandgap(sc_sub_t ss, sc_rsrc_t rsrc_idx,
    sc_pm_power_mode_t from_mode, sc_pm_power_mode_t to_mode);

#ifdef USE_AVPLL_FOR_DC
sc_dsc_t soc_get_dc_avpll_info(sc_rsrc_t pll_rsrc, uint8_t *ai_toggle, sc_bool_t *ssc_enable);
#endif

sc_bool_t soc_gpu_freq_hw_limited(void);
sc_bool_t soc_enet_get_freq_limit(sc_rsrc_t enet_rsrc);
uint32_t soc_get_clock_div(sc_dsc_t dsc, uint32_t *pll_div);

/*!
 * Save reset info.
 */
void soc_set_reset_info(sc_pm_reset_reason_t reason, sc_rm_pt_t pt);

/*!
 * Return reset reason.
 */
sc_pm_reset_reason_t soc_reset_reason(void);

/*!
 * Return partition causing reset.
 */
sc_rm_pt_t soc_reset_part(void);

void soc_temp_sensor_tick(uint16_t msec);

void soc_rompatch_checksum(uint32_t *checksum, uint16_t len);

uint32_t soc_dpll_dco_pc(sc_dsc_t dsc, uint8_t pll_index, uint32_t rate);

void soc_dpll_populate_tbl(void);

void soc_fabric_force_on(sc_bool_t enb);

void soc_post_ss_reset(sc_dsc_t dsc, DSC_Type *dsc_base);

void soc_gicr_quiesce(uint8_t cluster_idx, uint32_t cpu_idx);

void soc_ssi_pause(sc_bool_t enable);

extern sc_bool_t clk_off_trans;

#endif /* SC_SOC_API_H */

/**@}*/

