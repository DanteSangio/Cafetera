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

/****************************************DEFINICIONES PARA GPIO************************************************/

#define PORT(x) 	((uint8_t) x)
#define PIN(x)		((uint8_t) x)

#define OUTPUT		((uint8_t) 1)
#define INPUT		((uint8_t) 0)

#define ON			((uint8_t) 1)
#define OFF			((uint8_t) 0)

#define PRESSED		((uint8_t) 0)
#define NOT_PRESSED	((uint8_t) 1)

#define DESACTIVADO				0
#define ACTIVADO				1
#define NO_PULSADO				0
#define PULSADO					1
#define CERRADA					0
#define ABIERTA					1

/*	Definiciones modulo RFID	*/
#define RFID_MOSI_PORT	((uint8_t) 0)
#define RFID_MISO_PORT	((uint8_t) 0)
#define RFID_SCK_PORT	((uint8_t) 0)
#define RFID_SDA_PORT	((uint8_t) 0)
#define RFID_RS_PORT	((uint8_t) 0)
#define RFID_IRQ_PORT	((uint8_t) 2)

#define RFID_MOSI_PIN	((uint8_t) 9)
#define RFID_MISO_PIN	((uint8_t) 8)
#define RFID_SCK_PIN	((uint8_t) 7)
#define RFID_SDA_PIN	((uint8_t) 6)
#define RFID_RS_PIN		((uint8_t) 0)
#define RFID_IRQ_PIN	((uint8_t) 13)
/*	Fin Definiciones modulo RFID	*/

/*	Definiciones pines sensor temperatura	*/
#define TEMP_TX_PORT	((uint8_t) 0)
#define TEMP_RX_PORT	((uint8_t) 0)

#define TEMP_TX_PIN		((uint8_t) 15)
#define TEMP_RX_PIN		((uint8_t) 16)
/*	Fin Definiciones pines sensor temperatura	*/

/*	Definiciones pines caudalimetro	*/
#define CAUDA_IN_PORT	((uint8_t) 0)
#define CAUDA_OUT_PORT	((uint8_t) 0)

#define CAUDA_IN_PIN	((uint8_t) 23)
#define CAUDA_OUT_PIN	((uint8_t) 24)
/*	Fin Definiciones pines caudalimetro	*/

/*	Definiciones modulo LCD	*/
#define LCD_CS_PORT		((uint8_t) 0)
#define LCD_RS_PORT		((uint8_t) 0)
#define LCD_RST_PORT	((uint8_t) 1)
#define LCD_WR_PORT		((uint8_t) 1)
#define LCD_RD_PORT		((uint8_t) 1)

#define LCD_D0_PORT		((uint8_t) 1)
#define LCD_D1_PORT		((uint8_t) 1)
#define LCD_D2_PORT		((uint8_t) 1)
#define LCD_D3_PORT		((uint8_t) 1)
#define LCD_D4_PORT		((uint8_t) 1)
#define LCD_D5_PORT		((uint8_t) 1)
#define LCD_D6_PORT		((uint8_t) 1)
#define LCD_D7_PORT		((uint8_t) 1)

#define LCD_CS_PIN		((uint8_t) 25)
#define LCD_RS_PIN		((uint8_t) 26)
#define LCD_RST_PIN		((uint8_t) 18)
#define LCD_WR_PIN		((uint8_t) 19)
#define LCD_RD_PIN		((uint8_t) 20)

#define LCD_D0_PIN		((uint8_t) 21)
#define LCD_D1_PIN		((uint8_t) 22)
#define LCD_D2_PIN		((uint8_t) 23)
#define LCD_D3_PIN		((uint8_t) 24)
#define LCD_D4_PIN		((uint8_t) 25)
#define LCD_D5_PIN		((uint8_t) 26)
#define LCD_D6_PIN		((uint8_t) 27)
#define LCD_D7_PIN		((uint8_t) 28)
/*	Fin Definiciones modulo LCD	*/

/*	Definiciones pines tarjeta SD	*/
#define SD_SS_PORT		((uint8_t) 1)
#define SD_SCK_PORT		((uint8_t) 3)

#define SD_D0_PORT		((uint8_t) 3)
#define SD_D1_PORT		((uint8_t) 2)

#define SD_SS_PIN		((uint8_t) 29)
#define SD_SCK_PIN		((uint8_t) 26)

#define SD_D0_PIN		((uint8_t) 25)
#define SD_D1_PIN		((uint8_t) 9)
/*	Fin Definiciones pines tarjeta SD	*/

/*	Definiciones pines bomba de agua	*/
#define BOMBA_IN_PORT	((uint8_t) 0)
#define BOMBA_OUT_PORT	((uint8_t) 0)

#define BOMBA_IN_PIN	((uint8_t) 4)
#define BOMBA_OUT_PIN	((uint8_t) 5)
/*	Fin Definiciones pines bomba de agua	*/

/*	Definiciones pines GSM	*/
#define GSM_TX_PORT		((uint8_t) 0)
#define GSM_RX_PORT		((uint8_t) 0)

#define GSM_TX_PIN		((uint8_t) 10)
#define GSM_RX_PIN		((uint8_t) 11)
/*	Fin Definiciones pines GSM	*/

/*	Definiciones pines servo motores	*/
#define SERVO_1_PORT	((uint8_t) 2)
#define SERVO_2_PORT	((uint8_t) 2)
#define SERVO_3_PORT	((uint8_t) 2)
#define SERVO_4_PORT	((uint8_t) 2)
#define SERVO_5_PORT	((uint8_t) 2)

#define SERVO_1_PIN		((uint8_t) 1)
#define SERVO_2_PIN		((uint8_t) 2)
#define SERVO_3_PIN		((uint8_t) 3)
#define SERVO_4_PIN		((uint8_t) 4)
#define SERVO_5_PIN		((uint8_t) 5)
/*	Fin Definiciones pines servo motores	*/

/*	Definiciones pines sensores infrarojos	*/
#define IR_1_PORT		((uint8_t) 2)
#define IR_2_PORT		((uint8_t) 2)
#define IR_3_PORT		((uint8_t) 2)
#define IR_4_PORT		((uint8_t) 2)
#define IR_5_PORT		((uint8_t) 2)
#define IR_6_PORT		((uint8_t) 2)

#define IR_1_PIN		((uint8_t) 6)
#define IR_2_PIN		((uint8_t) 7)
#define IR_3_PIN		((uint8_t) 8)
#define IR_4_PIN		((uint8_t) 10)
#define IR_5_PIN		((uint8_t) 11)
#define IR_6_PIN		((uint8_t) 12)
/*	Fin Definiciones pines sensores infrarojos	*/

/*	Definiciones pines led RGB	*/
#define RGB_RED_PORT		((uint8_t) 0)
#define RGB_BLUE_PORT		((uint8_t) 0)
#define RGB_GREEN_PORT		((uint8_t) 0)

#define RGB_RED_PIN			((uint8_t) 21)
#define RGB_BLUE_PIN		((uint8_t) 27)
#define RGB_GREEN_PIN		((uint8_t) 22)
/*	Fin Definiciones pines led RGB	*/

/*	Definiciones pines led indicador	*/
#define LED_PORT		((uint8_t) 0)

#define LED_PIN			((uint8_t) 28)
/*	Fin Definiciones pines led indicador	*/

/*Funciones*/

void InitGPIOs (void);

#endif /* FIRMWARE_INC_DRIVER_DRIVERGPIO_H_ */
