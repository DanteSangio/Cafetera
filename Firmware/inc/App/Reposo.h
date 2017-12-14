/**
*	\file funciones.h
*	\brief Resumen del archivo
*	\details Descripcion detallada del archivo
*	\author JuanManuelGonzalezGonzalez
*	\date 03-11-2017 00:02:05
*/

//Declaracion de constantes
#define TRUE  1
#define FALSE  0

//declaracion de la maquina
void maquina_estado(void);


//Declaracion de estados
#define 	BAJO_CONSUMO	0
#define 	C_AGUA	1
#define 	GPRS	2
#define 	CONTROL	3

//Prototipos de los eventos
int NivelAgua <= NivelMinimo(void);
int NivelAgua!=NivelMax(void);
int NivelAgua==NivelMax(void);
int Solventes == Faltante(void);
int MSJ(void);
int !MSJ(void);
int Control = FIN(void);

//Prototipos de las acciones
void Nivel_Agua(void);
void Nivel_Solventes(void);
void BOMBA = ON(void);
void CargarAgua(void);
void BOMBA = OFF(void);
void EnviarMsj(void);
void BajoConsumo(void);
