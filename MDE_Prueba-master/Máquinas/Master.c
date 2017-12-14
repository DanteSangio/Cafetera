/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/



#include "funciones.h" 

//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details 
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
void maquina_estado()
{
		static int estado = CONECTADO;

		switch(estado)
		{
			case CONECTADO:
			
				if(Accion == Rx())
				{
					
					estado = RECIBIENDO;
		
				}
				if(Accion == Tx())
				{
					
					estado = ENVIANDO;
		
				}
				if(Accion == NULL())
				{
					MsjPantalla = "Bienvenido"();
					estado = CONECTADO;
		
				}

				break;
			
			case RECIBIENDO:
			
				if(Recepcion != OK())
				{
					Rx_USB();
					estado = RECIBIENDO;
		
				}
				if(Recepcion == OK())
				{
					
					estado = CONECTADO;
		
				}

				break;
			
			case ENVIANDO:
			
				if(Transmision!=OK())
				{
					Tx_USB();
					estado = ENVIANDO;
		
				}
				if(Transmision == OK())
				{
					
					estado = CONECTADO;
		
				}

				break;
			
			default: estado = CONECTADO;
		}


}

//Funciones asociadas a los eventos

/**
*	\fn int Accion == Rx(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
int Accion == Rx(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int Accion == Tx(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
int Accion == Tx(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int Recepcion != OK(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
int Recepcion != OK(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int Recepcion == OK(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
int Recepcion == OK(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int Transmision!=OK(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
int Transmision!=OK(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int Transmision == OK(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
int Transmision == OK(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int Accion == NULL(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
int Accion == NULL(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

//Funciones asociadas a las acciones

/**
*	\fn void Rx_USB(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
void Rx_USB(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void Tx_USB(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
void Tx_USB(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void MsjPantalla(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
void MsjPantalla(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void PrenderPantalla(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
void PrenderPantalla(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void PANTALLA = ON(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
void PANTALLA = ON(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void MsjPantalla = "Bienvenido"(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/
void MsjPantalla = "Bienvenido"(void)
{
	

	//Codigo propio de la funcion



	

}

