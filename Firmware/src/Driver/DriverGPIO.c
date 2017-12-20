/*
 * DriverGPIO.c
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#include "DriverGPIO.h"

/*Tarea de inicializacion*/
void InitGPIOs (void)
{
	/*Inicializo el modulo de GPIO*/
	Chip_GPIO_Init (LPC_GPIO);

	/*Configuro las funciones de cada pin*/

		/*Configuracion de los pines de RFID*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(RFID_MOSI_PORT) , PIN(RFID_MOSI_PIN), IOCON_MODE_INACT , IOCON_FUNC2);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(RFID_MISO_PORT) , PIN(RFID_MISO_PIN), IOCON_MODE_INACT , IOCON_FUNC2);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(RFID_SCK_PORT) , PIN(RFID_SCK_PIN), IOCON_MODE_INACT , IOCON_FUNC2);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(RFID_SDA_PORT) , PIN(RFID_SDA_PIN), IOCON_MODE_INACT , IOCON_FUNC2);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(RFID_RS_PORT) , PIN(RFID_RS_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(RFID_IRQ_PORT) , PIN(RFID_IRQ_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		/*Fin de Configuracion de los pines de RFID*/

		/*Configuracion de los pines de sensor temperatura*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(TEMP_TX_PORT) , PIN(TEMP_TX_PIN), IOCON_MODE_INACT , IOCON_FUNC1);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(TEMP_RX_PORT) , PIN(TEMP_RX_PIN), IOCON_MODE_INACT , IOCON_FUNC1);
		/*Fin de Configuracion de los pines de sensor temperatura*/

		/*Configuracion de los pines de caudalimetro*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(CAUDA_IN_PORT) , PIN(CAUDA_IN_PIN), IOCON_MODE_INACT , IOCON_FUNC3);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(CAUDA_OUT_PORT) , PIN(CAUDA_OUT_PIN), IOCON_MODE_INACT , IOCON_FUNC3);
		/*Fin de Configuracion de los pines de caudalimetro*/

		/*Configuracion de los pines de modulo LCD*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_CS_PORT) , PIN(LCD_CS_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_RS_PORT) , PIN(LCD_RS_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_RST_PORT) , PIN(LCD_RST_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_WR_PORT) , PIN(LCD_WR_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_RD_PORT) , PIN(LCD_RD_PIN), IOCON_MODE_INACT , IOCON_FUNC0);

		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_D0_PORT) , PIN(LCD_D0_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_D1_PORT) , PIN(LCD_D1_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_D2_PORT) , PIN(LCD_D2_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_D3_PORT) , PIN(LCD_D3_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_D4_PORT) , PIN(LCD_D4_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_D5_PORT) , PIN(LCD_D5_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_D6_PORT) , PIN(LCD_D6_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LCD_D7_PORT) , PIN(LCD_D7_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		/*Fin de Configuracion de los pines de modulo LCD*/

		/*Configuracion de los pines de tarjeta SD*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(SD_SS_PORT) , PIN(SD_SS_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(SD_SCK_PORT) , PIN(SD_SCK_PIN), IOCON_MODE_INACT , IOCON_FUNC0);

		Chip_IOCON_PinMux (LPC_IOCON , PORT(SD_D0_PORT) , PIN(SD_D0_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(SD_D1_PORT) , PIN(SD_D1_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		/*Fin de Configuracion de los pines de tarjeta SD*/

		/*Configuracion de los pines de bomba de agua*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(BOMBA_IN_PORT) , PIN(BOMBA_IN_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(BOMBA_OUT_PORT) , PIN(BOMBA_OUT_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		/*Fin de Configuracion de los pines de bomba de agua*/

		/*Configuracion de los pines de GSM*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(GSM_TX_PORT) , PIN(GSM_TX_PIN), IOCON_MODE_INACT , IOCON_FUNC1);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(GSM_RX_PORT) , PIN(GSM_RX_PIN), IOCON_MODE_INACT , IOCON_FUNC1);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(GSM_PW_PORT) , PIN(GSM_PW_PIN), IOCON_MODE_INACT , IOCON_FUNC0);

		/*Fin de Configuracion de los pines de GSM*/

		/*Configuracion de los pines de servo motores*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(SERVO_1_PORT) , PIN(SERVO_1_PIN), IOCON_MODE_INACT , IOCON_FUNC1);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(SERVO_2_PORT) , PIN(SERVO_2_PIN), IOCON_MODE_INACT , IOCON_FUNC1);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(SERVO_3_PORT) , PIN(SERVO_3_PIN), IOCON_MODE_INACT , IOCON_FUNC1);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(SERVO_4_PORT) , PIN(SERVO_4_PIN), IOCON_MODE_INACT , IOCON_FUNC1);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(SERVO_5_PORT) , PIN(SERVO_5_PIN), IOCON_MODE_INACT , IOCON_FUNC1);
		/*Fin de Configuracion de los pines de servo motores*/

		/*Configuracion de los pines de sensores infrarojos*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(IR_1_PORT) , PIN(IR_1_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(IR_2_PORT) , PIN(IR_2_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(IR_3_PORT) , PIN(IR_3_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(IR_4_PORT) , PIN(IR_4_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(IR_5_PORT) , PIN(IR_5_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(IR_6_PORT) , PIN(IR_6_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		/*Fin de Configuracion de los pines de sensores infrarojos*/

		/*Configuracion de los pines de led RGB*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(RGB_RED_PORT) , PIN(RGB_RED_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(RGB_BLUE_PORT) , PIN(RGB_BLUE_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		Chip_IOCON_PinMux (LPC_IOCON , PORT(RGB_GREEN_PORT) , PIN(RGB_GREEN_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		/*Fin de Configuracion de los pines de led RGB*/

		/*Configuracion de los pines de led indicador*/
		Chip_IOCON_PinMux (LPC_IOCON , PORT(LED_PORT) , PIN(LED_PIN), IOCON_MODE_INACT , IOCON_FUNC0);
		/*Fin de Configuracion de los pines de led indicador*/

	/*Fin de Configuro las funciones de cada pin*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*Configuro la direccion de cada pin*/

		//		REVISAR SI LOS PINES CON CONFIGURACION DISTINTA A GPIO TAMBIEN SE TIENE QUE CONFIGURAR ! ! !

		/*Configuracion de los pines de modulo RFID*/
		/*
		Chip_GPIO_SetDir (LPC_GPIO , PORT(RFID_MOSI_PORT) , PIN(RFID_MOSI_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(RFID_MISO_PORT) , PIN(RFID_MISO_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(RFID_SCK_PORT) , PIN(RFID_SCK_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(RFID_SDA_PORT) , PIN(RFID_SDA_PIN) , OUTPUT);
		*/
		Chip_GPIO_SetDir (LPC_GPIO , PORT(RFID_RS_PORT) , PIN(RFID_RS_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(RFID_IRQ_PORT) , PIN(RFID_IRQ_PIN) , INPUT);
		/*Fin de Configuracion de los pines de modulo RFID*/

		/*Configuracion de los pines de sensor temperatura*/
		/*
		Chip_GPIO_SetDir (LPC_GPIO , PORT(TEMP_TX_PORT) , PIN(TEMP_TX_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(TEMP_RX_PORT) , PIN(TEMP_RX_PIN) , OUTPUT);
		*/
		/*Fin de Configuracion de los pines de sensor temperatura*/

		/*Configuracion de los pines de caudalimetro*/
		/*
		Chip_GPIO_SetDir (LPC_GPIO , PORT(CAUDA_IN_PORT) , PIN(CAUDA_IN_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(CAUDA_OUT_PORT) , PIN(CAUDA_OUT_PIN) , OUTPUT);
		*/
		/*Fin de Configuracion de los pines de caudalimetro*/

		/*Configuracion de los pines de modulo LCD*/
		/*
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_CS_PORT) , PIN(LCD_CS_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_RS_PORT) , PIN(LCD_RS_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_RST_PORT) , PIN(LCD_RST_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_WR_PORT) , PIN(LCD_WR_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_RD_PORT) , PIN(LCD_RD_PIN) , OUTPUT);

		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_D0_PORT) , PIN(LCD_D0_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_D1_PORT) , PIN(LCD_D1_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_D2_PORT) , PIN(LCD_D2_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_D3_PORT) , PIN(LCD_D3_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_D4_PORT) , PIN(LCD_D4_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_D5_PORT) , PIN(LCD_D5_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_D6_PORT) , PIN(LCD_D6_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LCD_D7_PORT) , PIN(LCD_D7_PIN) , OUTPUT);
		*/
		/*Fin de Configuracion de los pines de modulo LCD*/

		/*Configuracion de los pines de tarjeta SD*/
		/*
		Chip_GPIO_SetDir (LPC_GPIO , PORT(SD_SS_PORT) , PIN(SD_SS_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(SD_SCK_PORT) , PIN(SD_SCK_PIN) , OUTPUT);

		Chip_GPIO_SetDir (LPC_GPIO , PORT(SD_D0_PORT) , PIN(SD_D0_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(SD_D1_PORT) , PIN(SD_D1_PIN) , OUTPUT);
		*/
		/*Fin de Configuracion de los pines de tarjeta SD*/

		/*Configuracion de los pines de bomba de agua*/
		Chip_GPIO_SetDir (LPC_GPIO , PORT(BOMBA_IN_PORT) , PIN(BOMBA_IN_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(BOMBA_OUT_PORT) , PIN(BOMBA_OUT_PIN) , OUTPUT);
		/*Fin de Configuracion de los pines de bomba de agua*/

		/*Configuracion de los pines de GSM*/
		/*
		Chip_GPIO_SetDir (LPC_GPIO , PORT(GSM_TX_PORT) , PIN(GSM_TX_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(GSM_RX_PORT) , PIN(GSM_RX_PIN) , OUTPUT);
		*/
		Chip_GPIO_SetDir (LPC_GPIO , PORT(GSM_PW_PORT) , PIN(GSM_PW_PIN) , OUTPUT);
		/*Fin de Configuracion de los pines de GSM*/

		/*Configuracion de los pines de servo motores*/
		/*
		Chip_GPIO_SetDir (LPC_GPIO , PORT(SERVO_1_PORT) , PIN(SERVO_1_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(SERVO_2_PORT) , PIN(SERVO_2_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(SERVO_3_PORT) , PIN(SERVO_3_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(SERVO_4_PORT) , PIN(SERVO_4_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(SERVO_5_PORT) , PIN(SERVO_5_PIN) , OUTPUT);
		*/
		/*Fin de Configuracion de los pines de servo motores*/

		/*Configuracion de los pines de sensores infrarojos*/
		Chip_GPIO_SetDir (LPC_GPIO , PORT(IR_1_PORT) , PIN(IR_1_PIN) , INPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(IR_2_PORT) , PIN(IR_2_PIN) , INPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(IR_3_PORT) , PIN(IR_3_PIN) , INPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(IR_4_PORT) , PIN(IR_4_PIN) , INPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(IR_5_PORT) , PIN(IR_5_PIN) , INPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(IR_6_PORT) , PIN(IR_6_PIN) , INPUT);
		/*Fin de Configuracion de los pines de sensores infrarojos*/

		/*Configuracion de los pines de led RGB*/
		Chip_GPIO_SetDir (LPC_GPIO , PORT(RGB_RED_PORT) , PIN(RGB_RED_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(RGB_BLUE_PORT) , PIN(RGB_BLUE_PIN) , OUTPUT);
		Chip_GPIO_SetDir (LPC_GPIO , PORT(RGB_GREEN_PORT) , PIN(RGB_GREEN_PIN) , OUTPUT);
		/*Fin de Configuracion de los pines de led RGB*/

		/*Configuracion de los pines de led indicador*/
		Chip_GPIO_SetDir (LPC_GPIO , PORT(LED_PORT) , PIN(LED_PIN) , OUTPUT);
		/*Fin de Configuracion de los pines de led indicador*/

	/*Fin de Configuro la direccion de cada pin*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*Pongo el nivel inicial de cada pin*/

		/*Configuracion de los pines de bomba de agua*/
		Chip_GPIO_SetPinState (LPC_GPIO, BOMBA_IN_PORT, BOMBA_IN_PIN, OFF);
		Chip_GPIO_SetPinState (LPC_GPIO, BOMBA_OUT_PORT, BOMBA_OUT_PIN, OFF);
		/*Fin de Configuracion de los pines de bomba de agua*/

		/*Configuracion de los pines de led RGB*/
		Chip_GPIO_SetPinState (LPC_GPIO, RGB_RED_PORT, RGB_RED_PIN, OFF);
		Chip_GPIO_SetPinState (LPC_GPIO, RGB_BLUE_PORT, RGB_BLUE_PIN, OFF);
		Chip_GPIO_SetPinState (LPC_GPIO, RGB_GREEN_PORT, RGB_GREEN_PIN, OFF);
		/*Fin de Configuracion de los pines de led RGB*/

		/*Configuracion de los pines de led indicador*/
		Chip_GPIO_SetPinState (LPC_GPIO, LED_PORT, LED_PIN, OFF);
		/*Fin de Configuracion de los pines de led indicador*/

		/*Configuracion de los pines del modulo GMS*/
		Chip_GPIO_SetPinState (LPC_GPIO, GSM_PW_PORT, GSM_PW_PIN, OFF);
		/*Fin de Configuracion de los pines del modulo GMS*/

	/*Fin de Pongo el nivel inicial de cada pin*/
}
