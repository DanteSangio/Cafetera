/*
 * DriverDMA.h
 *
 *  Created on: 9 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#ifndef FIRMWARE_INC_DRIVER_DRIVERDMA_H_
#define FIRMWARE_INC_DRIVER_DRIVERDMA_H_

#include "chip.h"
#include "DriverADC.h"

static volatile uint8_t dmaChannelNum;
extern uint32_t DMAbuffer;

void App_DMA_Test (void);

#endif /* FIRMWARE_INC_DRIVER_DRIVERDMA_H_ */
