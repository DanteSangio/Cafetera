/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 15:07:58
*/

//Declaracion de constantes
#define TRUE  1
#define FALSE  0

//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define 	REPOSO	0
#define 	MASTER	1
#define 	SELECCION	2
#define 	DOSIFICACION	3

//Prototipos de los eventos
int RFID(void);

//Prototipos de las acciones
void Control(void);
void Msj_Display(void);
void Com_USB(void);
void Control_Timer(void);
void Teclado_Pantalla(void);
void EN_Touch=OFF(void);
void EN_RFID=ON(void);
