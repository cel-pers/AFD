#include "TAD_arbol.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int op;
	str cad1=load2("1,2,3,4");
	printf("Bienvenido al programa: Empezaremos con conjuntos");
	printf("\n Conjunto A: ");
	tData A = cargaConjuntoHarcodeado(cad1);
	printf("\nSi desea agregar un conjunto B presione 0, de lo contrario se cargara uno predeterminado");
	scanf("%d",&op);
	if(op==0){
		tData B=cargaConjunto();
	}else{
		str cad2=load2("3,4,5,6");
		printf("\n Conjunto B: ");
		tData B = cargaConjuntoHarcodeado(cad2);
	}	
	printf("\nOperaciones entre conjuntoas");
	printf("\nCardinalidad de A: %d", cardinalidad(A));
	printf("\nCardinalidad de B: %d", cardinalidad(B));

	printf("\nUnion de y B: ");
	tData U=unionSet(A,B);
	mostrarConjunto(U);
	
}
