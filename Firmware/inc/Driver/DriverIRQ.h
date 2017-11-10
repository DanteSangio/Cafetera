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

#include "DriverADC.h"
#include "DriverDMA.h"
#include "DriverGPIO.h"
#include "DriverIR.h"
#include "DriverIRQ.h"
#include "DriverRTC.h"
#include "DriverSerie.h"
#include "DriverTFT.h"
#include "DriverTimer.h"
#include "DriverUSB.h"

void TIMER0_IRQHandler (void);
void ADC_IRQHandler (void);
void DMA_IRQHandler (void);
void USB_IRQHandler (void);

void App_Interrupt_Test (void);

#endif /* FIRMWARE_INC_DRIVER_DRIVERIRQ_H_ */
