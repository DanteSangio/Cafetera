/*
 * DriverGPIO.c
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#include "DriverGPIO.h"

/*Tarea de inicializacion*/
void InitGPIOs (void)
{
	Chip_GPIO_Init (LPC_GPIO);

	Chip_IOCON_PinMux (LPC_IOCON , PORT(0) , PIN(22), IOCON_MODE_INACT , IOCON_FUNC0);

	Chip_GPIO_SetDir (LPC_GPIO , PORT(0) , PIN(22) , OUTPUT);
}
