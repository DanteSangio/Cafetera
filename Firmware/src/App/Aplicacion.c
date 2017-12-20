/*
 * Aplicacion.c
 *
 *  Created on: 8 de nov. de 2017
 *      Author: Dante Sangiovanni
 */

#include "Aplicacion.h"

extern SemaphoreHandle_t Semaphore_GSM;

extern QueueHandle_t		Cola_Rx_GSM;
extern QueueHandle_t		Cola_Nro_GSM;
extern QueueHandle_t		Cola_InfoRx_GSM;
extern QueueHandle_t		Cola_Aux_GSM;
extern QueueHandle_t		Cola_Msj_GSM;

/*Funciones*/
void InicializarProyecto(void)
{

}

uint32_t recibirDatosGSM(uint32_t* dato)
{
	return 0;
}

void InicializarVariables(void)
{

}

uint8_t enviarMensajeGSM(char* numero, char* mensaje)
{
	return 0;
}

void SMSIncorrecto(void)
{

}

uint8_t compararSMS(char* mensaje, char* mensajeAEnviar)
{
	return 0;
}

void EnviarAlGSM(char* msj)
{

}

void InicializarGSM(void){

	static uint32_t data = 0;

	// Muestro en el display que se esta inicializando el gsm
	//MsjPantalla("INICIALIZANDO");
	//MsjPantalla("MODULO GSM");

	//inicializo en modulo GSM
	Chip_GPIO_SetPinState(LPC_GPIO, GSM_PW_PORT, GSM_PW_PIN, OFF); // SetPIN(PWR,OFF);
	vTaskDelay( pdMS_TO_TICKS(1500) ); //tiempoGSM = 600; // 1,5seg
	Chip_GPIO_SetPinState(LPC_GPIO, GSM_PW_PORT, GSM_PW_PIN, ON); // SetPIN(PWR,ON);
	vTaskDelay( pdMS_TO_TICKS(2500) ); //tiempoGSM = 1000; // 2,5seg

	EnviarAlGSM("AT+CMEE=1\r");
	vTaskDelay( pdMS_TO_TICKS(500) );
	EnviarAlGSM("AT+CMGF=1\r");
	vTaskDelay( pdMS_TO_TICKS(500) );
	EnviarStringUART3("AT+CNMI=2,2\r");
	vTaskDelay( pdMS_TO_TICKS(5000) );
}

/*Maquinas de estado*/

void maquinaGSM(void)		// La trama del sms recibido es: +CMT: "+5491163560077","","14/10/24,13:44:27-12"\rTEXTO_RECIBIDO\r
{
	static uint32_t estado = DISPONIBLE;
	static uint32_t contador = 0;
	static uint32_t barraCero = '\0';
	static char bufferAux[50];

	uint32_t data;

	switch(estado)
	{
		case DISPONIBLE:

			if( xQueueReceive(Cola_Rx_GSM, &data, 0) == pdPASS )
			{
				if(data == '+')
				{
					estado = ESPERANDO_SALTO;
					break;
				}
			}

			if( uxQueueSpacesAvailable( Cola_Msj_GSM ) && uxQueueSpacesAvailable( Cola_Nro_GSM ) )
			{
				EnviarAlGSM("AT+CMGS=\"");

				xQueueReceive(Cola_Nro_GSM, &numeroAEnviar, 0);
				EnviarAlGSM(numeroAEnviar);

				EnviarAlGSM("\"\r");

				xQueueReset(Cola_Nro_GSM);

				estado = ENVIANDO_NUMERO;
			}

			break;

		case ENVIANDO_NUMERO:
			if( xQueueReceive(Cola_Rx_GSM, &data, 0) == pdPASS )
			{
				if(data=='>')
				{
					xQueueReceive(Cola_Msj_GSM, &bufferMensajeAEnviar, 0);
					EnviarAlGSM(bufferMensajeAEnviar);

					xQueueReset(Cola_Msj_GSM);

					EnviarAlGSM(26); // le envio el CTRL+Z

					estado = ENVIANDO_MENSAJE;
				}
			}
			break;

		case ENVIANDO_MENSAJE:

			if( xQueueReceive(Cola_Rx_GSM, &data, 0) == pdPASS )
			{
				if(data == 'K')
				{
					estado = DISPONIBLE;
				}
			}
			break;

		case ESPERANDO_SALTO:

			if( xQueueReceive(Cola_Rx_GSM, &data, 0) == pdPASS )
			{
				if(data == '\n')
				{
					estado = RECIBIENDO_MENSAJE;
				}
			}

			break;

		case RECIBIENDO_MENSAJE:

			if( xQueueReceive(Cola_Rx_GSM, &data, 0) == pdPASS )
			{
				if(data != '\r')
				{
					xQueueSendToBack(Cola_InfoRx_GSM, &data, 0);
				}
				else
				{
					xQueueSendToBack(Cola_InfoRx_GSM, &barraCero, 0);

					xSemaphoreGive( Semaphore_GSM );

					estado = DISPONIBLE;
				}
			}

			break;

		case RECIBIENDO_HEADER_TRAMA:

			if( xQueueReceive(Cola_Rx_GSM, &data, 0) == pdPASS )
			{
				if(data != ':')
				{
					xQueueSendToBack(Cola_Aux_GSM, &data, 0);
				}
				else
				{
					xQueueSendToBack(Cola_Aux_GSM, &barraCero, 0);

					/*
					if(!strcmp(bufferAux,"CMT"))
						estado = ESPERANDO_MAS;
					else
						estado = DISPONIBLE;
					*/
				}
			}

			break;

		case ESPERANDO_MAS:

			if( xQueueReceive(Cola_Rx_GSM, &data, 0) == pdPASS )
			{
				if(data == '+')
				{
					estado = RECIBIENDO_NUMERO;
				}
			}

			break;

		case RECIBIENDO_NUMERO:
			if( xQueueReceive(Cola_Rx_GSM, &data, 0) == pdPASS )
			{
				if(data != '\"')
				{
					xQueueSendToBack(Cola_Aux_GSM, &data, 0);
				}
				else
				{
					xQueueSendToBack(Cola_Aux_GSM, &barraCero, 0);

					/*
					if(!strcmp(bufferAux,numeroDeTelefono))   //si en numero entrante es igual al numero de telefono definido para mandarle sms paso valido el texto recibido
						 estado = ESPERANDO_SALTO;
					else
						estado = DISPONIBLE;
					*/
				}
			}

			break;

	}
}


