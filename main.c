#include "setlist.h"
#include "TAD_AF.h"
#include <stdio.h>

int main(){
	str ingreso=load2("{q0,q1},{0,1},{[q0,0,q0],[q0,1,q1],[q1,0,q0],[q1,1,q1]},q0,{q1}");
	
	printf("\t Bienvenido. \nSe ingreso una cadena para que se procese como un automata: ");
	print(ingreso);
	printf("\n CARGA DEL AUTOMATA:\n\n");
	tData automata=crear_AF(ingreso);
	
	printf("\n\n\nSeleccione el elemento a consultar: ");
	printf("\n1)Q: Conjunto de estados \n2)Alfabeto \n3)Funcion de transicion \n4)Estado inicial \n5)Estados de Aceptacion:  ");
	scanf("%d",&opcion);
	consultar_elemento(opcion,automata);
	//mostrar_AF(automata);
}
