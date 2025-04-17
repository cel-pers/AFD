#include "TAD_arbol.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	str ptr;
	int p;
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
	//mostrarConjunto(unionSet(A,B));
	printf("\nIngrese elemento a buscar: ");
	ptr=load();
	p=inArbol(A,ptr);
	if(p==0)printf("\nEl elemento pertenece al conjunto");
	else printf("\nEl elemento no pertenece al conjunto");
	
	eliminaConjunto(&A);
	
}
