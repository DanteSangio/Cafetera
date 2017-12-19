/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/

#ifndef FIRMWARE_INC_APP_REPOSO_H_
#define FIRMWARE_INC_APP_REPOSO_H_

//Declaracion de constantes
#define NivelMax 99
#define NivelMinimo 10
#define Faltante 2
#define FIN 3
#define NULL 4
#define OFF 0
#define ON 1

//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define 	BAJO_CONSUMO	0
#define 	C_AGUA	1
#define 	GPRS	2
#define 	CONTROL	3

//Prototipos de los eventos

//Prototipos de las acciones
void CargarAgua(void);
void EnviarMsj(void);
void BajoConsumo(void);

#endif /*FIRMWARE_INC_APP_REPOSO_H_*/
