/*
 * DriverTimer.c
 *
 *  Created on: 9 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#include "DriverTimer.h"

/*Tarea de inicializacion*/
void InitTimer0 (void)
{

}

/*Tarea de configuracion*/
void Configuracion_Timer ( void )
{
	uint32_t timerFreq;

	Chip_TIMER_Init(LPC_TIMER0);

	/* Timer rate is system clock rate */
	timerFreq = Chip_Clock_GetSystemClockRate();

	/* Timer setup for match and interrupt at TICKRATE_HZ */
	Chip_TIMER_Reset(LPC_TIMER0);
	Chip_TIMER_MatchEnableInt(LPC_TIMER0, MATCH0);
	Chip_TIMER_SetMatch(LPC_TIMER0, MATCH0, ( timerFreq / 4 )); //  // antes : cada 5 min (timerFreq * 300)
	Chip_TIMER_ResetOnMatchEnable(LPC_TIMER0, MATCH0);
	Chip_TIMER_Enable(LPC_TIMER0);

	/* Enable timer interrupt */
	NVIC_ClearPendingIRQ(TIMER0_IRQn);
	NVIC_EnableIRQ(TIMER0_IRQn);
}


