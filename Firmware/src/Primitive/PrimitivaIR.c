/*
 * PrimitivaIR.c
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#include "PrimitivaIR.h"

uint32_t estadoIR0(void)
{
	uint32_t estado;
	estado = Chip_GPIO_GetPinState(LPC_GPIO, IR_1_PORT, IR_1_PIN);
	return(estado);
}
uint32_t estadoIR1(void)
{
	uint32_t estado;
	estado = Chip_GPIO_GetPinState(LPC_GPIO, IR_2_PORT, IR_2_PIN);
	return(estado);
}
uint32_t estadoIR2(void)
{
	uint32_t estado;
	estado = Chip_GPIO_GetPinState(LPC_GPIO, IR_2_PORT, IR_2_PIN);
	return(estado);
}
uint32_t estadoIR3(void)
{
	uint32_t estado;
	estado = Chip_GPIO_GetPinState(LPC_GPIO, IR_3_PORT, IR_3_PIN);
	return(estado);
}
uint32_t estadoIR4(void)
{
	uint32_t estado;
	estado = Chip_GPIO_GetPinState(LPC_GPIO, IR_4_PORT, IR_4_PIN);
	return(estado);
}
uint32_t estadoIR5(void)
{
	uint32_t estado;
	estado = Chip_GPIO_GetPinState(LPC_GPIO, IR_5_PORT, IR_5_PIN);
	return(estado);
}
