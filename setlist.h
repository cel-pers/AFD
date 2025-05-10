#ifndef SETLIST_H
#define SETLIST_H

#include "TAD_str.h"
#define STR 1
#define SET 2
#define LIST 3


typedef struct dataType{
	int nodeType; //STR, SET, LIST
	union{
		str Str;
		struct {
			struct dataType* data;
			struct dataType* next;
		};
	};
	
}TArbol;
typedef TArbol* tData;



tData crearNodoStr(str);
tData crearNodoSet(tData);
tData crearNodoLista(tData);
tData creaSetVacio();
tData creaListVacio();



//	conjunto
void appendSet (tData*, tData);
tData cargaConjunto();
tData unionSet(tData, tData);
tData interseccion (tData, tData);
tData diferencia (tData, tData); 
int cardinalidad (tData);
int inclusion (tData, tData);
void eliminaConjunto(tData*);
void liberarArbol(tData);
tData cargaConjuntoHardcodeado();
void mostrarConjunto(tData);
int inSet(tData,str);



// lista
tData appendList (tData*, tData);
void printList(tData);
tData cargaListaHardcodeada(str cad);



#endif
