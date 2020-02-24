/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_IGPIO_H_
#define _FSL_IGPIO_H_

#include "fsl_common.h"

/*!
 * @addtogroup igpio_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief IGPIO driver version 2.0.1. */
#define FSL_IGPIO_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*@}*/

/*! @brief IGPIO direction definition. */
typedef enum _igpio_pin_direction
{
    kIGPIO_DigitalInput  = 0U, /*!< Set current pin as digital input.*/
    kIGPIO_DigitalOutput = 1U, /*!< Set current pin as digital output.*/
} igpio_pin_direction_t;

/*! @brief IGPIO interrupt mode definition. */
typedef enum _igpio_interrupt_mode
{
    kIGPIO_NoIntmode              = 0U, /*!< Set current pin general IO functionality.*/
    kIGPIO_IntLowLevel            = 1U, /*!< Set current pin interrupt is low-level sensitive.*/
    kIGPIO_IntHighLevel           = 2U, /*!< Set current pin interrupt is high-level sensitive.*/
    kIGPIO_IntRisingEdge          = 3U, /*!< Set current pin interrupt is rising-edge sensitive.*/
    kIGPIO_IntFallingEdge         = 4U, /*!< Set current pin interrupt is falling-edge sensitive.*/
    kIGPIO_IntRisingOrFallingEdge = 5U, /*!< Enable the edge select bit to override the ICR register's configuration.*/
} igpio_interrupt_mode_t;

/*! @brief IGPIO Init structure definition. */
typedef struct _igpio_pin_config
{
    igpio_pin_direction_t direction; /*!< Specifies the pin direction. */
    uint8_t outputLogic;            /*!< Set a default output logic, which has no use in input */
    igpio_interrupt_mode_t
        interruptMode; /*!< Specifies the pin interrupt mode, a value of @ref igpio_interrupt_mode_t. */
} igpio_pin_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name IGPIO Initialization and Configuration functions
 * @{
 */

/*!
 * @brief Initializes the IGPIO peripheral according to the specified
 *        parameters in the initConfig.
 *
 * @param base IGPIO base pointer.
 * @param pin Specifies the pin number
 * @param initConfig pointer to a @ref igpio_pin_config_t structure that
 *        contains the configuration information.
 */
void IGPIO_PinInit(IGPIO_Type *base, uint32_t pin, const igpio_pin_config_t *Config);
/*@}*/

/*!
 * @name IGPIO Reads and Write Functions
 * @{
 */

/*!
 * @brief Sets the output level of the individual IGPIO pin to logic 1 or 0.
 *
 * @param base IGPIO base pointer.
 * @param pin IGPIO port pin number.
 * @param output IGPIOpin output logic level.
 *        - 0: corresponding pin output low-logic level.
 *        - 1: corresponding pin output high-logic level.
 */
void IGPIO_PinWrite(IGPIO_Type *base, uint32_t pin, uint8_t output);

/*!
 * @brief Sets the output level of the individual IGPIO pin to logic 1 or 0.
 * @deprecated Do not use this function.  It has been superceded by @ref IGPIO_PinWrite.
 */
static inline void IGPIO_WritePinOutput(IGPIO_Type *base, uint32_t pin, uint8_t output)
{
    IGPIO_PinWrite(base, pin, output);
}

/*!
 * @brief Sets the output level of the multiple IGPIO pins to the logic 1.
 *
 * @param base IGPIO peripheral base pointer (IGPIO1, IGPIO2, IGPIO3, and so on.)
 * @param mask IGPIO pin number macro
 */
static inline void IGPIO_PortSet(IGPIO_Type *base, uint32_t mask)
{
#if (defined(FSL_FEATURE_IIGPIO_HAS_DR_SET) && (FSL_FEATURE_IIGPIO_HAS_DR_SET == 1))
    base->DR_SET = mask;
#else
    base->DR |= mask;
#endif /* FSL_FEATURE_IIGPIO_HAS_DR_SET */
}

/*!
 * @brief Sets the output level of the multiple IGPIO pins to the logic 1.
 * @deprecated Do not use this function.  It has been superceded by @ref IGPIO_PortSet.
 */
static inline void IGPIO_SetPinsOutput(IGPIO_Type *base, uint32_t mask)
{
    IGPIO_PortSet(base, mask);
}

/*!
 * @brief Sets the output level of the multiple IGPIO pins to the logic 0.
 *
 * @param base IGPIO peripheral base pointer (IGPIO1, IGPIO2, IGPIO3, and so on.)
 * @param mask IGPIO pin number macro
 */
static inline void IGPIO_PortClear(IGPIO_Type *base, uint32_t mask)
{
#if (defined(FSL_FEATURE_IIGPIO_HAS_DR_CLEAR) && (FSL_FEATURE_IIGPIO_HAS_DR_CLEAR == 1))
    base->DR_CLEAR = mask;
#else
    base->DR &= ~mask;
#endif /* FSL_FEATURE_IIGPIO_HAS_DR_CLEAR */
}

/*!
 * @brief Sets the output level of the multiple IGPIO pins to the logic 0.
 * @deprecated Do not use this function.  It has been superceded by @ref IGPIO_PortClear.
 */
static inline void IGPIO_ClearPinsOutput(IGPIO_Type *base, uint32_t mask)
{
    IGPIO_PortClear(base, mask);
}

/*!
 * @brief Reverses the current output logic of the multiple IGPIO pins.
 *
 * @param base IGPIO peripheral base pointer (IGPIO1, IGPIO2, IGPIO3, and so on.)
 * @param mask IGPIO pin number macro
 */
static inline void IGPIO_PortToggle(IGPIO_Type *base, uint32_t mask)
{
#if (defined(FSL_FEATURE_IIGPIO_HAS_DR_TOGGLE) && (FSL_FEATURE_IIGPIO_HAS_DR_TOGGLE == 1))
    base->DR_TOGGLE = mask;
#endif /* FSL_FEATURE_IIGPIO_HAS_DR_TOGGLE */
}

/*!
 * @brief Reads the current input value of the IGPIO port.
 *
 * @param base IGPIO base pointer.
 * @param pin IGPIO port pin number.
 * @retval IGPIO port input value.
 */
static inline uint32_t IGPIO_PinRead(IGPIO_Type *base, uint32_t pin)
{
    assert(pin < 32);

    return (((base->DR) >> pin) & 0x1U);
}

/*!
 * @brief Reads the current input value of the IGPIO port.
 * @deprecated Do not use this function.  It has been superceded by @ref IGPIO_PinRead.
 */
static inline uint32_t IGPIO_ReadPinInput(IGPIO_Type *base, uint32_t pin)
{
    return IGPIO_PinRead(base, pin);
}
/*@}*/

/*!
 * @name IGPIO Reads Pad Status Functions
 * @{
 */

/*!
 * @brief Reads the current IGPIO pin pad status.
 *
 * @param base IGPIO base pointer.
 * @param pin IGPIO port pin number.
 * @retval IGPIO pin pad status value.
 */
static inline uint8_t IGPIO_PinReadPadStatus(IGPIO_Type *base, uint32_t pin)
{
    assert(pin < 32);

    return (uint8_t)(((base->PSR) >> pin) & 0x1U);
}

/*!
 * @brief Reads the current IGPIO pin pad status.
 * @deprecated Do not use this function.  It has been superceded by @ref IGPIO_PinReadPadStatus.
 */
static inline uint8_t IGPIO_ReadPadStatus(IGPIO_Type *base, uint32_t pin)
{
    return IGPIO_PinReadPadStatus(base, pin);
}

/*@}*/

/*!
 * @name Interrupts and flags management functions
 * @{
 */

/*!
 * @brief Sets the current pin interrupt mode.
 *
 * @param base IGPIO base pointer.
 * @param pin IGPIO port pin number.
 * @param pininterruptMode pointer to a @ref igpio_interrupt_mode_t structure
 *        that contains the interrupt mode information.
 */
void IGPIO_PinSetInterruptConfig(IGPIO_Type *base, uint32_t pin, igpio_interrupt_mode_t pinInterruptMode);

/*!
 * @brief Sets the current pin interrupt mode.
 * @deprecated Do not use this function.  It has been superceded by @ref IGPIO_PinSetInterruptConfig.
 */
static inline void IGPIO_SetPinInterruptConfig(IGPIO_Type *base, uint32_t pin, igpio_interrupt_mode_t pinInterruptMode)
{
    IGPIO_PinSetInterruptConfig(base, pin, pinInterruptMode);
}

/*!
 * @brief Enables the specific pin interrupt.
 *
 * @param base IGPIO base pointer.
 * @param mask IGPIO pin number macro.
 */
static inline void IGPIO_PortEnableInterrupts(IGPIO_Type *base, uint32_t mask)
{
    base->IMR |= mask;
}

/*!
 * @brief Enables the specific pin interrupt.
 *
 * @param base IGPIO base pointer.
 * @param mask IGPIO pin number macro.
 */
static inline void IGPIO_EnableInterrupts(IGPIO_Type *base, uint32_t mask)
{
    IGPIO_PortEnableInterrupts(base, mask);
}

/*!
 * @brief Disables the specific pin interrupt.
 *
 * @param base IGPIO base pointer.
 * @param mask IGPIO pin number macro.
 */
static inline void IGPIO_PortDisableInterrupts(IGPIO_Type *base, uint32_t mask)
{
    base->IMR &= ~mask;
}

/*!
 * @brief Disables the specific pin interrupt.
 * @deprecated Do not use this function.  It has been superceded by @ref IGPIO_PortDisableInterrupts.
 */
static inline void IGPIO_DisableInterrupts(IGPIO_Type *base, uint32_t mask)
{
    IGPIO_PortDisableInterrupts(base, mask);
}

/*!
 * @brief Reads individual pin interrupt status.
 *
 * @param base IGPIO base pointer.
 * @retval current pin interrupt status flag.
 */
static inline uint32_t IGPIO_PortGetInterruptFlags(IGPIO_Type *base)
{
    return base->ISR;
}

/*!
 * @brief Reads individual pin interrupt status.
 *
 * @param base IGPIO base pointer.
 * @retval current pin interrupt status flag.
 */
static inline uint32_t IGPIO_GetPinsInterruptFlags(IGPIO_Type *base)
{
    return IGPIO_PortGetInterruptFlags(base);
}

/*!
 * @brief Clears pin interrupt flag. Status flags are cleared by
 *        writing a 1 to the corresponding bit position.
 *
 * @param base IGPIO base pointer.
 * @param mask IGPIO pin number macro.
 */
static inline void IGPIO_PortClearInterruptFlags(IGPIO_Type *base, uint32_t mask)
{
    base->ISR = mask;
}

/*!
 * @brief Clears pin interrupt flag. Status flags are cleared by
 *        writing a 1 to the corresponding bit position.
 *
 * @param base IGPIO base pointer.
 * @param mask IGPIO pin number macro.
 */
static inline void IGPIO_ClearPinsInterruptFlags(IGPIO_Type *base, uint32_t mask)
{
    IGPIO_PortClearInterruptFlags(base, mask);
}
/*@}*/

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* _FSL_IGPIO_H_*/
