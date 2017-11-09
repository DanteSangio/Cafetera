/*
 * Init.c
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#include "Init.h"

void Inicializar (void)
{
	InitGPIOs();
	InitUART0();
	InitTFT();
	InitRTC();
	InitADC();

	SystemCoreClockUpdate();
}
