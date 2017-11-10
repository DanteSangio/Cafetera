/*
 * DriverADC.h
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#ifndef FIRMWARE_INC_DRIVER_DRIVERADC_H_
#define FIRMWARE_INC_DRIVER_DRIVERADC_H_

#include "chip.h"

#define _ADC_CHANNLE ADC_CH0
#define _LPC_ADC_ID LPC_ADC
#define _LPC_ADC_IRQ ADC_IRQn
#define _GPDMA_CONN_ADC GPDMA_CONN_ADC

static char WelcomeMenu[] = "\r\nHello NXP Semiconductors \r\n"
							"ADC DEMO \r\n"
							"Sample rate : 200kHz \r\n"
							"Press \'c\' to continue or \'x\' to quit\r\n"
							"Press \'o\' or \'p\' to set Sample rate\r\n"
							"Press \'b\' to ENABLE or DISABLE Burst Mode\r\n";

static char SelectMenu[] = "\r\nPress number 1-3 to choose ADC running mode:\r\n"
						   "\t1: Polling Mode \r\n"
						   "\t2: Interrupt Mode \r\n"
						   "\t3: DMA Mode \r\n";

static ADC_CLOCK_SETUP_T ADCSetup;
static volatile uint8_t Burst_Mode_Flag = 0, Interrupt_Continue_Flag;
static volatile uint8_t ADC_Interrupt_Done_Flag, channelTC;

extern uint16_t ADC_ValorMedido;

void InitADC (void);
void App_print_ADC_value (uint16_t);
void App_Polling_Test (void);

#endif /* FIRMWARE_INC_DRIVER_DRIVERADC_H_ */
