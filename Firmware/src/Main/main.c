/*
===============================================================================
 Name        : main.c
 Author      : Dante Sangiovanni
 Version     : 1.00
 Copyright   : UTN TD2
 Description : Definicion del archivo principal
===============================================================================
*/

#include "Aplicacion.h"

/*Manejadores de Semaforos, tareas y colas*/	///// LOS MANEJADORES LOS QUIERO COLOCAR EN EL ARCHIVO APLICACION.H
												///// PERO NO ME DEJA, VER PORQUÉ...
SemaphoreHandle_t 	Semaforo_1;
SemaphoreHandle_t 	Semaforo_2;

TaskHandle_t		Handle_Tarea_Lectura;
TaskHandle_t		Handle_Tarea_Escritura;
TaskHandle_t 		Handle_Tarea_MaquinaGeneral;
TaskHandle_t 		Handle_Tarea_MaquinaMaestro;
TaskHandle_t 		Handle_Tarea_MaquinaPantalla;
TaskHandle_t 		Handle_Tarea_MaquinaReposo;
TaskHandle_t 		Handle_Tarea_RFID;

QueueHandle_t 		Cola_1;
QueueHandle_t 		Cola_2;

SemaphoreHandle_t Semaphore_GSM;
SemaphoreHandle_t Semaphore_General;
SemaphoreHandle_t Semaphore_Maestro;
SemaphoreHandle_t Semaphore_Pantalla;
SemaphoreHandle_t Semaphore_Reposo;

QueueHandle_t		Cola_Rx_GSM;
QueueHandle_t		Cola_Nro_GSM;
QueueHandle_t		Cola_InfoRx_GSM;
QueueHandle_t		Cola_Aux_GSM;
QueueHandle_t		Cola_Msj_GSM;
QueueHandle_t		Cola_RFID;

/*Estructuras*/
typedef struct
{
	uint8_t 	puerto;
	uint8_t 	pin;
	uint32_t 	tiempo;
}LED_GPIO;

LED_GPIO LED_Struct;

/*Tareas*/								///// LAS TAREAS LAS QUIERO COLOCAR EN EL ARCHIVO APLICACION.C
										///// PERO NO ME DEJA, VER PORQUÉ...

//static void vTaskMaquinaGeneral(void *);

/* LED1 toggle thread */
static void vTask1(void *pvParameters)
{
	while (1)
	{
		xSemaphoreTake(Semaforo_2 , portMAX_DELAY );

		Chip_GPIO_SetPinOutHigh (LPC_GPIO , PORT(0) , PIN(22));

		vTaskDelay( 500 / portTICK_PERIOD_MS );

		xSemaphoreGive(Semaforo_1 );
	}
}

/* LED1 toggle thread */
static void xTask2(void *pvParameters)
{
	while (1)
	{
		xSemaphoreTake(Semaforo_1 , portMAX_DELAY );

		Chip_GPIO_SetPinOutLow (LPC_GPIO , PORT(0) , PIN(22));

		vTaskDelay( 500 / portTICK_PERIOD_MS );

		xSemaphoreGive(Semaforo_2 );
	}
}

/* Inputs read thread */
static void vTaskLectura(void *pvParameters)
{
	LED_GPIO Buffer;

	while (1)
	{
		Buffer.tiempo = 0;

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(IR_1_PORT) , PIN(IR_1_PIN)) == (bool)PRESSED )
		{
			Buffer.puerto = PORT(RGB_RED_PORT);
			Buffer.pin = 	PIN(RGB_RED_PIN);
			Buffer.tiempo = 1000;
		}

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(IR_2_PORT) , PIN(IR_2_PIN)) == (bool)PRESSED )
		{
			Buffer.puerto = PORT(RGB_BLUE_PORT);
			Buffer.pin = 	PIN(RGB_BLUE_PIN);
			Buffer.tiempo = 2000;
		}

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(IR_3_PORT) , PIN(IR_3_PIN)) == (bool)PRESSED )
		{
			Buffer.puerto = PORT(RGB_GREEN_PORT);
			Buffer.pin = 	PIN(RGB_GREEN_PIN);
			Buffer.tiempo = 2000;
		}

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(IR_4_PORT) , PIN(IR_4_PIN)) == (bool)PRESSED )
		{
			Buffer.puerto = PORT(RGB_RED_PORT);
			Buffer.pin = 	PIN(RGB_RED_PIN);
			Buffer.tiempo = ALL_LEDs;
		}

		if( Buffer.tiempo != 0 )
		{
			xQueueSendToBack( Cola_1 , &Buffer , portMAX_DELAY );
		}

	}
}

/* Inputs read thread */
static void vTaskRFID(void *pvParameters)
{
	uint32_t var = 0;

	while (1)
	{
		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(IR_1_PORT) , PIN(IR_1_PIN)) == (bool)PRESSED )
		{
			var = 1;
		}

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(IR_2_PORT) , PIN(IR_2_PIN)) == (bool)PRESSED )
		{
			var = 2;
		}

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(IR_3_PORT) , PIN(IR_3_PIN)) == (bool)PRESSED )
		{
			var = 3;
		}

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(IR_4_PORT) , PIN(IR_4_PIN)) == (bool)PRESSED )
		{
			var = 4;
		}

		if( var != 0 )
		{
			xQueueSendToBack( Cola_RFID , &var , portMAX_DELAY );

			xSemaphoreGive(Semaphore_General);

			var = 0;

			vTaskDelay( pdMS_TO_TICKS(200) );
		}

		vTaskDelay( pdMS_TO_TICKS(50) );
	}
}

/* Led RGB thread */
static void xTaskEscritura(void *pvParameters)
{
	LED_GPIO LED_RGB;

	uint8_t 	Puerto;
	uint8_t 	Pin;
	uint32_t 	Tiempo;
	uint32_t 	Veces;

	while (1)
	{
		xQueueReceive( Cola_2 , &LED_RGB , portMAX_DELAY );

		if ( LED_RGB.tiempo != ALL_LEDs )
		{
			Puerto = 	LED_RGB.puerto;
			Pin = 		LED_RGB.pin;
			Tiempo = 	LED_RGB.tiempo;

			Chip_GPIO_SetPinState( LPC_GPIO , Puerto , Pin , ON );

			vTaskDelay( Tiempo / portTICK_PERIOD_MS );

			Chip_GPIO_SetPinState( LPC_GPIO , Puerto , Pin , OFF );
		}
		else
		{
			for( Veces = 6 ; Veces ; Veces-- )
			{
				Chip_GPIO_SetPinToggle( LPC_GPIO , PORT(RGB_RED_PORT) ,   PIN(RGB_RED_PIN) );
				Chip_GPIO_SetPinToggle( LPC_GPIO , PORT(RGB_BLUE_PORT) ,  PIN(RGB_BLUE_PIN) );
				Chip_GPIO_SetPinToggle( LPC_GPIO , PORT(RGB_GREEN_PORT) , PIN(RGB_GREEN_PIN) );

				vTaskDelay( 500 / portTICK_PERIOD_MS );
			}
		}

	}
}

int main(void)
{
	//Ahora es el tercer commit para prueba !

	/*Configuración inicial del microcontrolador*/
	Inicializar ();

	/*Inicializacion de GPIO*/
	LED_Struct.pin = PORT(RGB_RED_PORT);
	LED_Struct.puerto = PIN(RGB_RED_PIN);
	LED_Struct.tiempo = 500;

	/*Creación de los Semaforos del Sistema Operativo*/
	vSemaphoreCreateBinary(Semaforo_1);
	vSemaphoreCreateBinary(Semaforo_2);

	vSemaphoreCreateBinary(Semaphore_GSM);
	vSemaphoreCreateBinary(Semaphore_General);
	vSemaphoreCreateBinary(Semaphore_Maestro);

	/*Toma del Semaforo*/
	xSemaphoreTake(Semaforo_1 , portMAX_DELAY );

	/*Creacion de las colas del Sistema Operativo*/
	Cola_1 = xQueueCreate( 1 , sizeof(LED_GPIO) );
	Cola_2 = xQueueCreate( 5 , sizeof(LED_GPIO) );

	Cola_Rx_GSM 	= xQueueCreate( 1 , sizeof(uint32_t) );
	Cola_Msj_GSM	= xQueueCreate( 1 , sizeof(uint32_t) );
	Cola_Nro_GSM 	= xQueueCreate( 1 , sizeof(uint32_t) );
	Cola_InfoRx_GSM = xQueueCreate( 1 , sizeof(uint32_t) );
	Cola_Aux_GSM 	= xQueueCreate( 1 , sizeof(uint32_t) );

	Cola_RFID		= xQueueCreate( 1 , sizeof(uint32_t) );

	xQueueSendToBack( Cola_1 , &LED_Struct , portMAX_DELAY );
	xQueueReceive( Cola_1 , &LED_Struct , portMAX_DELAY );

	/*Creación de las tareas necesarias para el Sistema Operativo*/

	xTaskCreate(	vTask1,
					(char *) "vTask1",
					configMINIMAL_STACK_SIZE,
					NULL,
					(tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) NULL
	);

	xTaskCreate(	xTask2,
					(char *) "vTask2",
					configMINIMAL_STACK_SIZE,
					NULL,
					(tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) NULL
	);

	xTaskCreate(	vTaskLectura,
					(char *) "vTaskLectura",
					configMINIMAL_STACK_SIZE,
					&LED_Struct,
					(tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) Handle_Tarea_Lectura
	);

	xTaskCreate(	xTaskEscritura,
					(char *) "xTaskEscritura",
					configMINIMAL_STACK_SIZE,
					&LED_Struct,
					(tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) Handle_Tarea_Escritura
	);

	xTaskCreate(	vTaskRFID,
					(char *) "vTaskRFID",
					configMINIMAL_STACK_SIZE,
					NULL,
					(tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) Handle_Tarea_RFID
	);

	xTaskCreate(	vTaskMaquinaGeneral,
					(char *) "vTaskMaquinaGeneral",
					configMINIMAL_STACK_SIZE,
					NULL,
					(tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) Handle_Tarea_MaquinaGeneral
	);

	xTaskCreate(	vTaskMaquinaMaestro,
					(char *) "vTaskMaquinaMaestro",
					configMINIMAL_STACK_SIZE,
					NULL,
					(tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) Handle_Tarea_MaquinaMaestro
	);

	xTaskCreate(	vTaskMaquinaPantalla,
					(char *) "vTaskMaquinaPantalla",
					configMINIMAL_STACK_SIZE,
					NULL,
					(tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) Handle_Tarea_MaquinaPantalla
	);

	xTaskCreate(	vTaskMaquinaReposo,
					(char *) "vTaskMaquinaReposo",
					configMINIMAL_STACK_SIZE,
					NULL,
					(tskIDLE_PRIORITY + 1UL),
					(xTaskHandle *) Handle_Tarea_MaquinaReposo
	);

	/*Lanzamiento del Manejador del Sistema Operativo*/
	vTaskStartScheduler();

	/*Nunca debería arribar aquí*/
    return 0;
}
