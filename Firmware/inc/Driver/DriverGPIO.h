/*
 * DriverGPIO.h
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#ifndef FIRMWARE_INC_DRIVER_DRIVERGPIO_H_
#define FIRMWARE_INC_DRIVER_DRIVERGPIO_H_

#include "chip.h"

/*Definiciones de las macros*/
#define OUTPUT		((uint8_t) 1)
#define INPUT		((uint8_t) 0)

#define PORT(x) 	((uint8_t) x)
#define PIN(x)		((uint8_t) x)

/*	Definiciones pines led RGB	*/
#define RED_PORT	((uint8_t) 2)
#define BLUE_PORT	((uint8_t) 0)
#define GREEN_PORT	((uint8_t) 2)

#define RED_PIN		((uint8_t) 0)
#define BLUE_PIN	((uint8_t) 26)
#define GREEN_PIN	((uint8_t) 1)
/*	Fin Definiciones pines led RGB	*/

/*	Definiciones pines joystick	*/
#define UP_KEY_PORT		((uint8_t) 2)
#define DOWN_KEY_PORT	((uint8_t) 2)
#define LEFT_KEY_PORT	((uint8_t) 0)
#define RIGHT_KEY_PORT	((uint8_t) 0)

#define UP_KEY_PIN		((uint8_t) 4)
#define DOWN_KEY_PIN	((uint8_t) 3)
#define LEFT_KEY_PIN	((uint8_t) 16)
#define RIGHT_KEY_PIN	((uint8_t) 15)
/*	Fin Definiciones pines joystick	*/

#define OUTPUT		((uint8_t) 1)
#define INPUT		((uint8_t) 0)

#define ON			((uint8_t) 1)
#define OFF			((uint8_t) 0)


#define PRESSED		((uint8_t) 0)
#define NOT_PRESSED	((uint8_t) 1)

#define ALL_LEDs	((uint32_t) 5000)

/*Funciones*/

void InitGPIOs (void);

#endif /* FIRMWARE_INC_DRIVER_DRIVERGPIO_H_ */
