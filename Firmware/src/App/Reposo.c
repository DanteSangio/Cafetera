/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/

#include "Reposo.h"

extern SemaphoreHandle_t Semaphore_Reposo;

int BOMBA = OFF;
int MSJ = NULL;
int Solventes;
int NivelAgua = NivelMax;
int Control;

//#include "funciones.h"

void vTaskMaquinaReposo(void *pvParameters)
{
	static int estado = CONTROL;

	xSemaphoreTake(Semaphore_Reposo, 0);

	while (1)
	{
		xSemaphoreTake(Semaphore_Reposo, portMAX_DELAY);

		switch(estado)
		{
			case BAJO_CONSUMO:


				break;

			case C_AGUA:

				if(NivelAgua!=NivelMax)
				{
					CargarAgua();
					estado = C_AGUA;

				}
				if(NivelAgua==NivelMax)
				{
					BOMBA = OFF;
					estado = CONTROL;

				}

				break;

			case GPRS:

				if(MSJ)
				{
					EnviarMsj();
					estado = GPRS;

				}
				if(!MSJ)
				{

					estado = CONTROL;

				}

				break;

			case CONTROL:

				if(NivelAgua <= NivelMinimo)
				{
					BOMBA = ON;
					estado = C_AGUA;

				}
				if(Solventes == Faltante)
				{

					estado = GPRS;

				}
				if(Control == FIN)
				{
					BajoConsumo();
					estado = BAJO_CONSUMO;

				}

				break;

			default: estado = CONTROL;
		}
	}
}

//Funciones asociadas a los eventos
void CargarAgua(void)
{
	

	//Codigo propio de la funcion



	

}

void EnviarMsj(void)
{
	

	//Codigo propio de la funcion



	

}

void BajoConsumo(void)
{
	

	//Codigo propio de la funcion



	

}

