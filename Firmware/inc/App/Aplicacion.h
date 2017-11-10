/*
 * Aplicacion.h
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#ifndef FIRMWARE_INC_APP_APLICACION_H_
#define FIRMWARE_INC_APP_APLICACION_H_

/*Inclucion de las librerias*/
#include "chip.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"

#include <cr_section_macros.h>

#include "Init.h"

#include "PrimitivaTFT.h"
#include "PrimitivaSerie.h"
#include "PrimitivaIR.h"
#include "PrimitivaUSB.h"

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

/*Definiciones de las macros*/

#define SMS				0		//el modulo GSM esta deshabilitado, me manda por la uart0 y uart1 un mensaje igual que el sms que mandaria el GSM, por la uart1 y uart0 puedo escribir para simular la entrada de un sms
#define GSM				1		//el micro me repite por la uart0 y uart1 lo que me devuelve el modulo GSM. se envian y reciven mensajes
#define COMUNICACION	2		//el micro se comunica por las uarts como si estuviera comunicandose con la pc y la puerta
#define DISABLE			3		//para desactivar el modo debug

#define MODO_DEBUG	DISABLE

#define ALL_LEDs	5000

#define NUMERO_TELEFONO	"5491131673996"	//	Dante = 1563560077

/*Estados de la maquina de GSM*/
#define DISPONIBLE 							0
#define ENVIANDO_NUMERO 					1
#define ENVIANDO_MENSAJE 					2
#define RECIBIENDO_MENSAJE 					3
#define ESPERANDO_SALTO 					4
#define RECIBIENDO_HEADER_TRAMA				5
#define ESPERANDO_MAS 						6
#define RECIBIENDO_NUMERO					7

/*Tamaño de los buffers*/
#define MAX_MESSAGE_LENGTH_GSM				50
#define MAX_NUMBER_LENGTH_GSM				20

/*Variables para el GSM*/
extern char bufferMensajeRecibido[];
extern char bufferMensajeAEnviar[];
extern char numeroAEnviar[];

extern uint8_t flagMensajeRecibidoGSM;

/*Funciones*/
void InicializarProyecto(void);
void InicializarGSM(void);
void InicializarVariables(void);

/*Maquinas de estado*/
void maquinaGSM(void);
uint8_t enviarMensajeGSM(char* numero, char* mensaje);
void SMSIncorrecto(void);
uint8_t compararSMS(char* mensaje, char* mensajeAEnviar);

#endif /* FIRMWARE_INC_APP_APLICACION_H_ */
