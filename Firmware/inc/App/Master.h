/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 14:55:47
*/

#ifndef FIRMWARE_INC_APP_MASTER_H_
#define FIRMWARE_INC_APP_MASTER_H_

//Declaracion de constantes
#define TRUE  1
#define FALSE  0

//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define 	CONECTADO	0
#define 	RECIBIENDO	1
#define 	ENVIANDO	2

//Prototipos de los eventos
int Accion == Rx(void);
int Accion == Tx(void);
int Recepcion != OK(void);
int Recepcion == OK(void);
int Transmision!=OK(void);
int Transmision == OK(void);
int Accion == NULL(void);

//Prototipos de las acciones
void Rx_USB(void);
void Tx_USB(void);
void MsjPantalla(void);
void PrenderPantalla(void);
void PANTALLA = ON(void);
void MsjPantalla = "Bienvenido"(void);

#endif /*FIRMWARE_INC_APP_MASTER_H_*/
