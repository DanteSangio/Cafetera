/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/

#ifndef FIRMWARE_INC_APP_PANTALLA_H_
#define FIRMWARE_INC_APP_PANTALLA_H_

//Declaracion de constantes
#define OFF			0
#define ON			1
#define Cancelar	2
#define Aceptar		3


//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define 	APAGADO	0
#define 	MENSAJE	1
#define 	TECLADO_1	2
#define 	TECLADO_2	3

//Prototipos de los eventos

//Prototipos de las acciones
void MsjPantalla(void);
void Selec_Producto(void);
void Detalle_Producto(void);


#endif /*FIRMWARE_INC_APP_PANTALLA_H_*/
