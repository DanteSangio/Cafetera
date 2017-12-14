/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/






int PANTALLA = 0 ;int Accion = 0 ;int T_Teclado_1 = 0 ;int T_Teclado_2 = 0 ;
#include "funciones.h" 

//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details 
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
void maquina_estado()
{
		static int estado = APAGADO;

		switch(estado)
		{
			case APAGADO:
			
				if(PANTALLA == OFF())
				{
					
					estado = APAGADO;
		
				}
				if(PANTALLA == ON())
				{
					
					estado = MENSAJE;
		
				}
				if(EN_Touch == ON())
				{
					
					estado = TECLADO_1;
		
				}

				break;
			
			case MENSAJE:
			
				if(PANTALLA == ON())
				{
					MsjPantalla();
					estado = MENSAJE;
		
				}
				if(PANTALLA == OFF())
				{
					
					estado = APAGADO;
		
				}

				break;
			
			case TECLADO_1:
			
				if((Accion!=Cancelar) && (Accion!=Aceptar)&& (T_Teclado_1!=TimeOut))
				{
					Selec_Producto();
					estado = TECLADO_1;
		
				}
				if(Accion == Aceptar())
				{
					
					estado = TECLADO_2;
		
				}
				if((Accion==Cancelar) || (T_Teclado_1==TimeOut))
				{
					PANTALLA = ON();
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
					PANTALLA = ON();
					estado = MENSAJE;
		
				}
				if(Accion == Cancelar())
				{
					
					estado = TECLADO_1;
		
				}

				break;
			
			default: estado = APAGADO;
		}


}

//Funciones asociadas a los eventos

/**
*	\fn int PANTALLA == OFF(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
int PANTALLA == OFF(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int PANTALLA == ON(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
int PANTALLA == ON(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int EN_Touch == ON(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
int EN_Touch == ON(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int Accion == Aceptar(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
int Accion == Aceptar(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

/**
*	\fn int Accion == Cancelar(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
int Accion == Cancelar(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

//Funciones asociadas a las acciones

/**
*	\fn void PANTALLA = OFF(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
void PANTALLA = OFF(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void MsjPantalla(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
void MsjPantalla(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void Selec_Producto(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
void Selec_Producto(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void Detalle_Producto(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
void Detalle_Producto(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void PANTALLA = ON(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/
void PANTALLA = ON(void)
{
	

	//Codigo propio de la funcion



	

}

