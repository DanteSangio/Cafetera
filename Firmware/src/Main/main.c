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

QueueHandle_t 		Cola_1;
QueueHandle_t 		Cola_2;

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

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(UP_KEY_PORT) , PIN(UP_KEY_PIN)) == (bool)PRESSED )
		{
			Buffer.puerto = PORT(RED_PORT);
			Buffer.pin = 	PIN(RED_PIN);
			Buffer.tiempo = 1000;
		}

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(DOWN_KEY_PORT) , PIN(DOWN_KEY_PIN)) == (bool)PRESSED )
		{
			Buffer.puerto = PORT(BLUE_PORT);
			Buffer.pin = 	PIN(BLUE_PIN);
			Buffer.tiempo = 2000;
		}

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(LEFT_KEY_PORT) , PIN(LEFT_KEY_PIN)) == (bool)PRESSED )
		{
			Buffer.puerto = PORT(GREEN_PORT);
			Buffer.pin = 	PIN(GREEN_PIN);
			Buffer.tiempo = 2000;
		}

		if( Chip_GPIO_GetPinState( LPC_GPIO , PORT(RIGHT_KEY_PORT) , PIN(RIGHT_KEY_PIN)) == (bool)PRESSED )
		{
			Buffer.puerto = PORT(RED_PORT);
			Buffer.pin = 	PIN(RED_PIN);
			Buffer.tiempo = ALL_LEDs;
		}

		if( Buffer.tiempo != 0 )
		{
			xQueueSendToBack( Cola_1 , &Buffer , portMAX_DELAY );
		}

		/*
		xSemaphoreTake(Semaforo_2 , portMAX_DELAY );

		Chip_GPIO_SetPinOutHigh (LPC_GPIO , PORT(0) , PIN(22));

		vTaskDelay( 500 / portTICK_PERIOD_MS );

		xSemaphoreGive(Semaforo_1 );
		*/
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
				Chip_GPIO_SetPinToggle( LPC_GPIO , PORT(RED_PORT) ,   PIN(RED_PIN) );
				Chip_GPIO_SetPinToggle( LPC_GPIO , PORT(BLUE_PORT) ,  PIN(BLUE_PIN) );
				Chip_GPIO_SetPinToggle( LPC_GPIO , PORT(GREEN_PORT) , PIN(GREEN_PIN) );

				vTaskDelay( 500 / portTICK_PERIOD_MS );
			}
		}

		/*
		xSemaphoreTake(Semaforo_1 , portMAX_DELAY );

		Chip_GPIO_SetPinOutLow (LPC_GPIO , PORT(0) , PIN(22));

		vTaskDelay( 500 / portTICK_PERIOD_MS );

		xSemaphoreGive(Semaforo_2 );
		*/
	}
}

int main(void)
{
	//Éste es el segundo commit para probar !!!

	/*Configuración inicial del microcontrolador*/
	Inicializar ();

	/*Creación de los Semaforos del Sistema Operativo*/
	vSemaphoreCreateBinary(Semaforo_1);
	vSemaphoreCreateBinary(Semaforo_2);

	/*Toma del Semaforo*/
	xSemaphoreTake(Semaforo_1 , portMAX_DELAY );

	/*Creacion de las colas del Sistema Operativo*/
	Cola_1 = xQueueCreate( 5 , sizeof(LED_GPIO) );
	Cola_2 = xQueueCreate( 5 , sizeof(LED_GPIO) );

	xQueueSendToBack( Cola_1 , &LED_Struct , portMAX_DELAY );
	xQueueReceive( Cola_1 , &LED_Struct , portMAX_DELAY );

	/*Creación de las tareas necesarias para el Sistema Operativo*/
	xTaskCreate(	vTask1,
					(char *) "vTask1",
					configMINIMAL_STACK_SIZE,
					NULL, (tskIDLE_PRIORITY + 1UL),
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

	/*Lanzamiento del Manejador del Sistema Operativo*/
	vTaskStartScheduler();

	/*Nunca debería arribar aquí*/
    return 0;
}
