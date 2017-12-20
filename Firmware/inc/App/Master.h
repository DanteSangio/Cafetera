/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/

#ifndef FIRMWARE_INC_APP_MASTER_H_
#define FIRMWARE_INC_APP_MASTER_H_

#include "Aplicacion.h"

//Declaracion de constantes
#define Rx 		0
#define Tx		1
#define Null	2
//#define OK		3
//declaracion de la maquina
void maquinaMaestro(void);


//Declaracion de estados
#define 	CONECTADO	0
#define 	RECIBIENDO	1
#define 	ENVIANDO	2

//Prototipos de los eventos

//Prototipos de las acciones
void MsjPantalla(void);
void PrenderPantalla(void);

#endif /*FIRMWARE_INC_APP_MASTER_H_*/
