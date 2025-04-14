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

tData crearNodoSet();
tData cargaConjunto();
void mostrarConjunto(tData);

tData unionSet(tData, tData);
void liberarArbol(tData);


/* 
1- Inicializar una lista
2- Cargar una lista (todas)
3- Mostrar una lista
4- crear un conjunto vacio
5- cargar un conjunto (considerar cargar por consola y ((todas))
14- carga por cadena hardcodeada, considerar el
conjunto vacio) (todas)6- mostrar un conjunto
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
