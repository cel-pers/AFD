#ifndef ARBOL_H
#define ARBOL_H

#define STR 1
#define SET 2
#define LIST 3

#include "string.h"
typedef struct dataType{
	int nodeType; //STR, SET, LIST
	union {
		str Str;
		struct ptr{
			struct dataType* data;
			struct dataType* next;
		};
	};
	
}TArbol;
typedef TArbol* tData;


typedef TArbol* tData;
tData crearNodoStr(str);
tData crearNodoSet(tData);
tData crearNodoLista(tData);
tData cargaConjunto();

/*faltaba agregar*/
tData cargaConjuntoHardcodeado (const char*);

void mostrarConjunto(tData);
void printList(tData);
int inArbol(tData,str);
tData unionSet(tData, tData);

tData unionSet (tData A, tData B);
tData interseccion (tData A, tData B);
tData diferencia (tData A, tData B); 
int cardinalidad (tData);
int inclusion (tData A, tData B);
void eliminaConjunto(tData*);
void liberarArbol(tData);
void agrega(tData*,tData);
tData push (tData lista, tData nuevoNodo);

/* 
1- Inicializar una lista
2- Cargar una lista (todas)
3- Mostrar una lista
4- crear un conjunto vacio
5- cargar un conjunto (considerar cargar por consola y ((todas))
14- carga por cadena hardcodeada, considerar el
conjunto vacio) (todas)
6- mostrar un conjunto
Implementar las operaciones de
7- union 
8- interseccion 
9- diferencia 
10- cardinalidad, 
11- pertenece
12- inclusion 
13- eliminar conjunto.

*/
#endif
