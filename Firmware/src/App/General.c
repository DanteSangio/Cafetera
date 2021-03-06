/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/

#include "General.h"

extern SemaphoreHandle_t Semaphore_General;
extern QueueHandle_t     Cola_RFID;

uint32_t EN_RFID 	= 	0 ;
uint32_t EN_Touch 	= 	0 ;
uint32_t EN_USB 	= 	0 ;
uint32_t ID_RFID 	=	0 ;
uint32_t USB_state 	= 	0 ;

uint32_t Tiempo 	= 	0 ;
uint32_t VASO 		= 	0 ;

uint32_t PANTALLA;

uint32_t TimeOut; //extern
uint32_t Master_ID; //extern

extern uint32_t Accion;

void vTaskMaquinaGeneral(void *pvParameters)
{
	static int estado = REPOSO;

	uint32_t RFID = 0;

	xSemaphoreTake(Semaphore_General, 0);

	while (1)
	{
		xSemaphoreTake(Semaphore_General, portMAX_DELAY);

		xQueueReceive(Cola_RFID, &RFID, 0);

		switch(estado)
		{
			case REPOSO:

				if(RFID==0) // NULL
				{
					estado = REPOSO;

				}
				if((RFID==Master_ID) && (USB_state==Conect))
				{
					EN_RFID = OFF;
					EN_USB = ON;

					estado = MASTER;

				}
				if(RFID)
				{
					EN_RFID = OFF;
					EN_Touch = ON;

					estado = SELECCION;

				}

				break;

			case MASTER:

				if((USB_state == Conect) && (Accion != FIN))
				{

					estado = MASTER;

				}
				if((USB_state==Disconect) || (Accion==FIN))
				{
					EN_RFID=ON;
					EN_USB=OFF;
					PANTALLA=OFF;

					estado = REPOSO;

				}

				break;

			case SELECCION:

				if((Accion!=Cancelar) && (Accion!=Aceptar)&& (Tiempo!=TimeOut))
				{

					estado = SELECCION;

				}
				if((Tiempo==TimeOut) || (Accion==Cancelar))
				{
					EN_RFID=ON;
					EN_Touch=OFF;

					estado = REPOSO;

				}
				if((Accion==Aceptar) && (VASO==OK))
				{
					EN_Touch=OFF;
					estado = DOSIFICACION;

				}

				break;

			case DOSIFICACION:

				if(Tiempo==TimeOut)
				{
					EN_RFID=ON;
					estado = REPOSO;

				}

				break;

			default: estado = REPOSO;
		}
	}
}

void Msj_Display(void)
{
	

	//Codigo propio de la funcion



	

}

void Control_Timer(void)
{
	

	//Codigo propio de la funcion



	

}

void Teclado_Pantalla(void)
{
	

	//Codigo propio de la funcion



	

}

