/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/



#include "funciones.h" 

//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details 
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
void maquina_estado()
{
		static int estado = CONTROL;

		switch(estado)
		{
			case BAJO_CONSUMO:
			

				break;
			
			case C_AGUA:
			
				if(NivelAgua!=NivelMax())
				{
					CargarAgua();
					estado = C_AGUA;
		
				}
				if(NivelAgua==NivelMax())
				{
					BOMBA = OFF();
					estado = CONTROL;
		
				}

				break;
			
			case GPRS:
			
				if(MSJ())
				{
					EnviarMsj();
					estado = GPRS;
		
				}
				if(!MSJ())
				{
					
					estado = CONTROL;
		
				}

				break;
			
			case CONTROL:
			
				if(NivelAgua <= NivelMinimo())
				{
					BOMBA = ON();
					estado = C_AGUA;
		
				}
				if(Solventes == Faltante())
				{
					
					estado = GPRS;
		
				}
				if(Control = FIN())
				{
					BajoConsumo();
					estado = BAJO_CONSUMO;
		
				}

				break;
			
			default: estado = CONTROL;
		}


}

//Funciones asociadas a los eventos

/**
*	\fn int NivelAgua <= NivelMinimo(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
int NivelAgua <= NivelMinimo(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int NivelAgua!=NivelMax(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
int NivelAgua!=NivelMax(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int NivelAgua==NivelMax(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
int NivelAgua==NivelMax(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int Solventes == Faltante(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
int Solventes == Faltante(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int MSJ(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
int MSJ(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int !MSJ(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
int !MSJ(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int Control = FIN(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
int Control = FIN(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

//Funciones asociadas a las acciones

/**
*	\fn void Nivel_Agua(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
void Nivel_Agua(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void Nivel_Solventes(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
void Nivel_Solventes(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void BOMBA = ON(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
void BOMBA = ON(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void CargarAgua(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
void CargarAgua(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void BOMBA = OFF(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
void BOMBA = OFF(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void EnviarMsj(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
void EnviarMsj(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void BajoConsumo(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/
void BajoConsumo(void)
{
	

	//Codigo propio de la funcion



	

}

