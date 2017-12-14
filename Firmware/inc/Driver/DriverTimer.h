/*
 * DriverTimer.h
 *
 *  Created on: 9 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#ifndef FIRMWARE_INC_DRIVER_DRIVERTIMER_H_
#define FIRMWARE_INC_DRIVER_DRIVERTIMER_H_

#include "chip.h"
#include "DriverGPIO.h"

/****************************************DEFINICIONES PARA TIMERS************************************************/
#define MATCH0		0
#define MATCH1		1
#define MATCH2		2
#define MATCH3		3

void InitTimer0 ( void );

void Configuracion_Timer ( void );

#endif /* FIRMWARE_INC_DRIVER_DRIVERTIMER_H_ */
