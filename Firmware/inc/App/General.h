/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/

#ifndef FIRMWARE_INC_APP_GENERAL_H_
#define FIRMWARE_INC_APP_GENERAL_H_

#include "chip.h"

//Declaracion de constantes
#define OFF			0
#define ON			1
//#define NULL		2
#define Conect		3
#define FIN			4
#define Disconect	5
#define Cancelar	6
#define Aceptar		7
#define OK			8
//declaracion de la maquina
void maquinaGeneral(void);

//Declaracion de estados
#define 	REPOSO			0
#define 	MASTER			1
#define 	SELECCION		2
#define 	DOSIFICACION	3

//Prototipos de las funciones
void Control(void);
void Msj_Display(void);
void Com_USB(void);
void Control_Timer(void);
void Teclado_Pantalla(void);

#endif /*FIRMWARE_INC_APP_GENERAL_H_*/
