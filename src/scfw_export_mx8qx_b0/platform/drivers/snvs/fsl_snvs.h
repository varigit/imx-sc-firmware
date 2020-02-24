/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2017-2019 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DRV_SNVS_H
#define DRV_SNVS_H

/*!
 * @addtogroup snvs_driver
 * @{
 */

/*! @file */

/* Includes */

#include "main/types.h"

/* Defines */

/*!
 * @name Defines for snvs_btn_config_t
 */
/*@{*/
#define SNVS_DRV_BTN_CONFIG_ACTIVELOW       0U
#define SNVS_DRV_BTN_CONFIG_ACTIVEHIGH      1U
#define SNVS_DRV_BTN_CONFIG_RISINGEDGE      2U
#define SNVS_DRV_BTN_CONFIG_FALLINGEDGE     3U
#define SNVS_DRV_BTN_CONFIG_ANYEDGE         4U
/*@}*/

/*!
 * @name Defines for snvs_btn_on_time_t
 */
/*@{*/
#define SNVS_DRV_BTN_ON_50MS                0U
#define SNVS_DRV_BTN_ON_100MS               1U
#define SNVS_DRV_BTN_ON_500MS               2U
#define SNVS_DRV_BTN_ON_0MS                 3U
/*@}*/

/*!
 * @name Defines for snvs_btn_debounce_t
 */
/*@{*/
#define SNVS_DRV_BTN_DEBOUNCE_50MS          0U
#define SNVS_DRV_BTN_DEBOUNCE_100MS         1U
#define SNVS_DRV_BTN_DEBOUNCE_500MS         2U
#define SNVS_DRV_BTN_DEBOUNCE_0MS           3U
/*@}*/

/*!
 * @name Defines for snvs_btn_press_time_t
 */
/*@{*/
#define SNVS_DRV_BTN_PRESS_5S               0U
#define SNVS_DRV_BTN_PRESS_10S              1U
#define SNVS_DRV_BTN_PRESS_15S              2U
#define SNVS_DRV_BTN_PRESS_OFF              3U
/*@}*/

/* Types */

/*!
 * This type is used configure the button active state.
 */
typedef uint8_t snvs_btn_config_t;

/*!
 * This type is used configure the button on time.
 */
typedef uint8_t snvs_btn_on_time_t;

/*!
 * This type is used configure the button debounce time.
 */
typedef uint8_t snvs_btn_debounce_t;

/*!
 * This type is used configure the button press time.
 */
typedef uint8_t snvs_btn_press_time_t;

/* SNVS Functions */

/*!
 * @name Initialization Functions
 * @{
 */

void SNVS_Init(boot_phase_t phase);

/* @} */

/*!
 * @name SRTC Functions
 * @{
 */

/*!
 * @brief Power off system.
 *
 * This function asserts the signal to the PMIC to force a power off.
 */
void SNVS_PowerOff(void);

/*!
 * @brief Set the secure RTC.
 *
 * This function sets the secure RTC.
 *
 * @param seconds   time to set.
 */
void SNVS_SetSecureRtc(uint32_t seconds);

/*!
 * @brief Get the secure RTC.
 *
 * This function returns the secure RTC time.
 *
 * @param seconds   pointer to return seconds.
 */
void SNVS_GetSecureRtc(uint32_t *seconds);

/*!
 * @brief Set the secure RTC calibration value.
 *
 * This function sets the secure RTC calibration value.
 * See the SNVS section of the SRM for more info.
 *
 * @param count   counts to add/subtract per 32768 ticks.
 */
void SNVS_SetSecureRtcCalb(int8_t count);

/*!
 * @brief Get the secure RTC calibration value.
 *
 * This function returns the secure RTC calibration value.
 * See the SNVS section of the SRM for more info.
 *
 * @param count   pointer to return count.
 */
void SNVS_GetSecureRtcCalb(int8_t *count);

/*!
 * @brief Set secure RTC alarm.
 *
 * This function sets the secure RTC alarm and enables it.
 *
 * @param seconds   alarm to set.
 *
 * If seconds=UINT32_MAX then disable alarm.
 */
void SNVS_SetSecureRtcAlarm(uint32_t seconds);

/*!
 * @brief Get secure RTC alarm.
 *
 * This function returns the secure RTC alarm.
 *
 * @param seconds   pointer to return alarm.
 */
void SNVS_GetSecureRtcAlarm(uint32_t *seconds);

/*!
 * @brief Set the RTC.
 *
 * This function sets the RTC.
 *
 * @param seconds   time to set.
 */
void SNVS_SetRtc(uint32_t seconds);

/*!
 * @brief Get the RTC.
 *
 * This function returns the RTC time.
 *
 * @param seconds   pointer to return seconds.
 */
void SNVS_GetRtc(uint32_t *seconds);

/*!
 * @brief Set the RTC calibration value.
 *
 * This function sets the RTC calibration value.
 * See the SNVS section of the SRM for more info.
 *
 * @param count   counts to add/subtract per 32768 ticks.
 */
void SNVS_SetRtcCalb(int8_t count);

/*!
 * @brief Set RTC alarm.
 *
 * This function sets the RTC alarm and enables it.
 *
 * @param seconds   alarm to set.
 *
 * If seconds=UINT32_MAX then disable alarm.
 */
void SNVS_SetRtcAlarm(uint32_t seconds);

/*!
 * @brief Get RTC alarm.
 *
 * This function returns the RTC alarm.
 *
 * @param seconds   pointer to return alarm.
 */
void SNVS_GetRtcAlarm(uint32_t *seconds);

/*!
 * @brief Configure the ON/OFF button.
 *
 * This function configures the button detection and IRQ.
 * See the SNVS section of the SRM for more info.
 *
 * @param config   button configuration (see BTN_CONFIG in SRM).
 * @param enable   button IRQ enable (see BTN_MASK in SRM).
 */
void SNVS_ConfigButton(snvs_btn_config_t config, sc_bool_t enable);

/*!
 * @brief Configure the ON/OFF button timing parameters.
 *
 * This function configures the button timing parameters.
 * See the SNVS section of the SRM for more info.
 *
 * @param on       button turn on time (see ON_TIME in SRM).
 * @param debounce button debounce time (see DEBOUNCE in SRM).
 * @param press    button turn off time (see BTN_PRESS_TIME in SRM).
 */
void SNVS_ButtonTime(snvs_btn_on_time_t on, snvs_btn_debounce_t debounce,
    snvs_btn_press_time_t press);

/*!
 * @brief Get button status.
 *
 * This function returns the status of the button.
 * See the SNVS section of the SRM for more info. BTN in HPSR.
 */
sc_bool_t SNVS_GetButtonStatus(void);

/*!
 * @brief Clear button IRQ.
 *
 * This function clears a pending button IRQ.
 */
void SNVS_ClearButtonIRQ(void);

/*!
 * @brief Enter low power mode.
 *
 * This function prepares the SNVS for low power mode. It copies various data
 * from the HP section to the LP section.
 */
void SNVS_EnterLPM(void);

/*!
 * @brief Exit low power mode.
 *
 * This function restores SNVS data from the LP section to the HP section.
 */
void SNVS_ExitLPM(void);

/*!
 * @brief Get the SNVS System Security Monitor State (SSM). 
 *
 * This function returns the System Security Monitor State (SSM).
 * See the SNVS section of the SRM for more info. SSM_ST in HPSR.
 */
uint32_t SNVS_GetState(void);

/*!
 * @brief SNVS security violation IRQ handler.
 *
 * This function is called when the security violation IRQ is asserted.
 */
void SNVS_SecurityViolation_IRQHandler(void);

/*!
 * @brief SNVS power off IRQ handler.
 *
 * This function is called when the power off IRQ is asserted.
 */
void SNVS_PowerOff_IRQHandler(void);

/*!
 * @brief Read a GP register.
 *
 * This function is called read from one of the four GP registers.
 */
uint32_t SNVS_ReadGP(uint8_t idx);

/*!
 * @brief Write a GP register.
 *
 * This function is called write to one of the four GP registers.
 */
void SNVS_WriteGP(uint8_t idx, uint32_t val);

/* Externs */

/*! SNVS error return */
extern sc_err_t snvs_err;

/* @} */

#endif /* DRV_SNVS_H */

/**@}*/

