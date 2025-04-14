#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	tData A=NULL;
	tData B=NULL;
	printf("\nA continuacion, se creará un conjunto A: ");
	
	A=cargaConjunto();
	
	printf("\nConjunto ingresado: \n{");
	mostrarConjunto(A);
	
	printf("\nA continuacion, se creará un conjunto B: ");

	B=cargaConjunto();
	
	printf("\nConjunto ingresado: \n{");
	mostrarConjunto(B);
	
	printf("\nUnion de conjuntos: ");
	mostrarConjunto(unionSet(A,B));
	
	
	
	
	liberarArbol(A);
	
}
