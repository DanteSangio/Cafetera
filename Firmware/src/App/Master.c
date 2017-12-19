/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
#include "Master.h"

uint32_t Accion;
uint32_t Recepcion;
uint32_t Transmision;

//int MsjPantalla;

void maquinaMaestro(void)
{
		static int estado = CONECTADO;

		switch(estado)
		{
			case CONECTADO:
			
				if(Accion == Rx)
				{
					
					estado = RECIBIENDO;
		
				}
				if(Accion == Tx)
				{
					
					estado = ENVIANDO;
		
				}
				if(Accion == 0) // NULL
				{
					//MsjPantalla = "Bienvenido";
					estado = CONECTADO;
		
				}

				break;
			
			case RECIBIENDO:
			
				if(Recepcion != OK)
				{
					//Rx_USB();
					estado = RECIBIENDO;
		
				}
				if(Recepcion == OK)
				{
					
					estado = CONECTADO;
		
				}

				break;
			
			case ENVIANDO:
			
				if( Transmision != OK)
				{
					//Tx_USB();
					estado = ENVIANDO;
		
				}
				if(Transmision == OK)
				{
					
					estado = CONECTADO;
		
				}

				break;
			
			default: estado = CONECTADO;
		}


}

void Rx_USB(void)
{
	

	//Codigo propio de la funcion



	

}
void Tx_USB(void)
{
	

	//Codigo propio de la funcion



	

}
/*
void MsjPantalla(void)
{
	

	//Codigo propio de la funcion



	

}
*/
void PrenderPantalla(void)
{
	

	//Codigo propio de la funcion



	

}

