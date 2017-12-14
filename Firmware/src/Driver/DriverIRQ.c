/*
 * DriverIRQ.c
 *
 *  Created on: 9 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#include "DriverIRQ.h"

void TIMER0_IRQHandler(void)
{
	BaseType_t FuerzaCC = pdFALSE;

	if (Chip_TIMER_MatchPending(LPC_TIMER0, MATCH0))
	{
		Chip_TIMER_ClearMatch(LPC_TIMER0, MATCH0);

		//xSemaphoreGiveFromISR( Semaphore_MUESTRA, &FuerzaCC);

		portYIELD_FROM_ISR( FuerzaCC );
	}
}

void ADC_IRQHandler(void) // 	USAR TODO FROM_ISR
{
	BaseType_t FuerzaCC = pdFALSE;

	NVIC_DisableIRQ(ADC_IRQn);

	//xSemaphoreGiveFromISR( Semaphore_ADC, &FuerzaCC ); 	// ANALIZA SI HAY UNA TAREA DE MAYOR PRIORIDAD A LA QUE SE ESTABA EJECUTANDO
														// BLOQUEADA POR ÉSTE SEMAFORO Y EN EL CASO DE QUE SI, FUERZA EL CAMBIO
														// DE CONTEXTO

	portYIELD_FROM_ISR( FuerzaCC );
}

void ADC_IRQHandlerrrr(void) //static
{
	uint16_t dataADC;
	/* Interrupt mode: Call the stream interrupt handler */
	NVIC_DisableIRQ(_LPC_ADC_IRQ);
	Chip_ADC_Int_SetChannelCmd(_LPC_ADC_ID, _ADC_CHANNLE, DISABLE);
	Chip_ADC_ReadValue(_LPC_ADC_ID, _ADC_CHANNLE, &dataADC);
	ADC_Interrupt_Done_Flag = 1;
	App_print_ADC_value(dataADC);
	/*
	if (DEBUGIN() != 'x') {
		NVIC_EnableIRQ(_LPC_ADC_IRQ);
		Chip_ADC_Int_SetChannelCmd(_LPC_ADC_ID, _ADC_CHANNLE, ENABLE);
	}
	else {Interrupt_Continue_Flag = 0; }
	*/
}

/* Interrupt routine for ADC example */
void App_Interrupt_Test(void) //static
{
	/* Enable ADC Interrupt */
	NVIC_EnableIRQ(_LPC_ADC_IRQ);
	Chip_ADC_Int_SetChannelCmd(_LPC_ADC_ID, _ADC_CHANNLE, ENABLE);
	/* Enable burst mode if any, the AD converter does repeated conversions
	   at the rate selected by the CLKS field in burst mode automatically */
	if (Burst_Mode_Flag) {
		Chip_ADC_SetBurstCmd(_LPC_ADC_ID, ENABLE);
	}
	Interrupt_Continue_Flag = 1;
	ADC_Interrupt_Done_Flag = 1;
	while (Interrupt_Continue_Flag) {
		if (!Burst_Mode_Flag && ADC_Interrupt_Done_Flag) {
			ADC_Interrupt_Done_Flag = 0;
			Chip_ADC_SetStartMode(_LPC_ADC_ID, ADC_START_NOW, ADC_TRIGGERMODE_RISING);
		}
	}
	/* Disable burst mode if any */
	if (Burst_Mode_Flag) {
		Chip_ADC_SetBurstCmd(_LPC_ADC_ID, DISABLE);
	}
	/* Disable ADC interrupt */
	NVIC_DisableIRQ(_LPC_ADC_IRQ);
}

void DMA_IRQHandler(void)
{
	if (Chip_GPDMA_Interrupt(LPC_GPDMA, dmaChannelNum) == SUCCESS) {
		channelTC++;
	}
	else {
		/* Process error here */
	}
}

void USB_IRQHandler(void)
{
	USBD_API->hw->ISR(g_hUsb);
}

