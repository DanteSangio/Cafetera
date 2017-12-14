/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 16:19:50
*/

//Declaracion de constantes
#define TRUE  1
#define FALSE  0

//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define 	APAGADO	0
#define 	MENSAJE	1
#define 	TECLADO_1	2
#define 	TECLADO_2	3

//Prototipos de los eventos
int PANTALLA == OFF(void);
int PANTALLA == ON(void);
int EN_Touch == ON(void);
int Accion == Aceptar(void);
int Accion == Cancelar(void);

//Prototipos de las acciones
void PANTALLA = OFF(void);
void MsjPantalla(void);
void Selec_Producto(void);
void Detalle_Producto(void);
void PANTALLA = ON(void);
