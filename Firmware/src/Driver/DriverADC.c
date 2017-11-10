/*
 * DriverADC.c
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#include "DriverADC.h"

uint16_t ADC_ValorMedido;

/*Tarea de inicializacion*/
void InitADC (void)
{
	Chip_ADC_Init(_LPC_ADC_ID, &ADCSetup);
	Chip_ADC_EnableChannel(_LPC_ADC_ID, _ADC_CHANNLE, ENABLE);
}

/*Imprimir valor del ADC*/
void App_print_ADC_value(uint16_t data)
{
	volatile uint32_t j;
	j = 5000000;
	/*
	DEBUGOUT("ADC value is : 0x%04x\r\n", data);
	*/
	/* Delay */
	while (j--) {}
}

/* Polling routine for ADC example */
void App_Polling_Test(void) //static
{
	uint16_t dataADC;

	/* Select using burst mode or not */
	if (Burst_Mode_Flag) {
		Chip_ADC_SetBurstCmd(_LPC_ADC_ID, ENABLE);
	}
	else {
		Chip_ADC_SetBurstCmd(_LPC_ADC_ID, DISABLE);
	}

	/*
	// Get  adc value until get 'x' character
	while (DEBUGIN() != 'x') {
		// Start A/D conversion if not using burst mode
		if (!Burst_Mode_Flag) {
			Chip_ADC_SetStartMode(_LPC_ADC_ID, ADC_START_NOW, ADC_TRIGGERMODE_RISING);
		}
		// Waiting for A/D conversion complete
		while (Chip_ADC_ReadStatus(_LPC_ADC_ID, _ADC_CHANNLE, ADC_DR_DONE_STAT) != SET) {}
		// Read ADC value
		Chip_ADC_ReadValue(_LPC_ADC_ID, _ADC_CHANNLE, &dataADC);
		// Print ADC value
		App_print_ADC_value(dataADC);
	}
	*/

	/* Disable burst mode, if any */
	if (Burst_Mode_Flag) {
		Chip_ADC_SetBurstCmd(_LPC_ADC_ID, DISABLE);
	}
}
