/*
 * DriverIRQ.h
 *
 *  Created on: 9 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#ifndef FIRMWARE_INC_DRIVER_DRIVERIRQ_H_
#define FIRMWARE_INC_DRIVER_DRIVERIRQ_H_

#include "chip.h"
#include "FreeRTOS.h"
#include "semphr.h"

void TIMER0_IRQHandler ( void );

#endif /* FIRMWARE_INC_DRIVER_DRIVERIRQ_H_ */
