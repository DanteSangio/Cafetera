/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/

#include "Pantalla.h"

extern SemaphoreHandle_t Semaphore_Pantalla;

#define TimeOut		5

uint32_t T_Teclado_1 = 0 ;
uint32_t T_Teclado_2 = 0 ;

extern uint32_t Accion;
extern uint32_t PANTALLA;

//#include "funciones.h"

void vTaskMaquinaPantalla(void *pvParameters)
{
	static int estado = APAGADO;

	xSemaphoreTake(Semaphore_Pantalla, 0);

	while (1)
	{
		xSemaphoreTake(Semaphore_Pantalla, portMAX_DELAY);

		switch(estado)
		{
			case APAGADO:

				if(PANTALLA == OFF)
				{

					estado = APAGADO;

				}
				if(PANTALLA == ON)
				{

					estado = MENSAJE;

				}
				/*
				if(EN_Touch == ON)
				{

					estado = TECLADO_1;

				}
				*/
				break;

			case MENSAJE:

				if(PANTALLA == ON)
				{
					//MsjPantalla();
					estado = MENSAJE;

				}
				if(PANTALLA == OFF)
				{

					estado = APAGADO;

				}

				break;

			case TECLADO_1:

				if((Accion != Cancelar) && (Accion!=Aceptar)&& (T_Teclado_1 != TimeOut))
				{
					Selec_Producto();
					estado = TECLADO_1;

				}
				if(Accion == Aceptar)
				{

					estado = TECLADO_2;

				}
				if((Accion==Cancelar) || (T_Teclado_1==TimeOut))
				{
					PANTALLA = ON;
					estado = MENSAJE;

				}

				break;

			case TECLADO_2:

				if((Accion!=Cancelar) && (Accion==Aceptar)&& (T_Teclado_2==TimeOut))
				{
					Detalle_Producto();
					estado = TECLADO_2;

				}
				if((Accion==Aceptar) || (T_Teclado_2==TimeOut))
				{
					PANTALLA = ON;
					estado = MENSAJE;

				}
				if(Accion == Cancelar)
				{

					estado = TECLADO_1;

				}

				break;

			default: estado = APAGADO;
		}
	}
}

//Funciones asociadas a los eventos

void MsjPantalla(void)
{
	

	//Codigo propio de la funcion



	

}


void Selec_Producto(void)
{
	

	//Codigo propio de la funcion



	

}

void Detalle_Producto(void)
{
	

	//Codigo propio de la funcion



	

}

