/**
*	\file funciones.c
*	\brief 
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/












int EN_RFID = 0 ;int EN_Touch = 0 ;int EN_USB = 0 ;int ID_RFID = 0 ;int USB_state = 0 ;int Accion = 0 ;int RFID = 0 ;int Tiempo = 0 ;int VASO = 0 ;int PANTALLA = 0 ;
#include "funciones.h" 

//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details 
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/
void maquina_estado()
{
		static int estado = REPOSO;

		switch(estado)
		{
			case REPOSO:
			
				if((RFID==NULL))
				{
					
					estado = REPOSO;
		
				}
				if((RFID==Master_ID) && (USB_state==Conect))
				{
					EN_RFID=OFF;
					EN_USB=ON;

					estado = MASTER;
		
				}
				if(RFID())
				{
					EN_RFID=OFF;
					EN_Touch=ON;

					estado = SELECCION;
		
				}

				break;
			
			case MASTER:
			
				if((USB_state==Conect) && (Accion!=FIN))
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
					EN_Touch=OFF();
					estado = DOSIFICACION;
		
				}

				break;
			
			case DOSIFICACION:
			
				if((Tiempo==TimeOut))
				{
					EN_RFID=ON();
					estado = REPOSO;
		
				}

				break;
			
			default: estado = REPOSO;
		}


}

//Funciones asociadas a los eventos

/**
*	\fn int RFID(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/
int RFID(void)
{
	int res = 0 ;

	//Codigo propio de la funcion



	return res;

}

//Funciones asociadas a las acciones

/**
*	\fn void Control(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/
void Control(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void Msj_Display(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/
void Msj_Display(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void Com_USB(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/
void Com_USB(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void Control_Timer(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/
void Control_Timer(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void Teclado_Pantalla(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/
void Teclado_Pantalla(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void EN_Touch=OFF(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/
void EN_Touch=OFF(void)
{
	

	//Codigo propio de la funcion



	

}

/**
*	\fn void EN_RFID=ON(void)
*	\brief Resumen
*	\details Detalles
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/
void EN_RFID=ON(void)
{
	

	//Codigo propio de la funcion



	

}

