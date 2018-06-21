/*
 * system_TM4C.h
 *
 *  Created on: Dec 30, 2017
 *      Author: juan
 */

#ifndef CMSIS_SYSTEM_TM4C_H_
#define CMSIS_SYSTEM_TM4C_H_

/**************************************************************************//**
 * @file     system_TM4C.h
 * @brief    CMSIS Cortex-M4 Device Peripheral Access Layer Header File for
 *           TI Stellaris TM4C Devices
 * @version  V3.00
 * @date     19. December 2011
 * @date     Last modified: 2014-09-04T14:59:17-0400
 *
 * @brief    Changed part name from LM4F to TM4C KJH
 *
 * @note
 * Copyright (C) 2010-2011 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M
 * processor based microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such ARM based processors.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#ifndef SYSTEM_TM4C_H
#define SYSTEM_TM4C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */


/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_TM4C_H */



#endif /* CMSIS_SYSTEM_TM4C_H_ */
