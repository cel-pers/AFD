#include "TAD_AF.h"
//creando el automata
tData crear_AF(str ingreso){
	
	tData inicio = creaListVacio();
	tData temp=NULL;
	tData elemento=NULL;  //pongo el dato en un nodo tData STR
	str dato=NULL;
	
	//tomo los datos de Q {qo,q1},{0,1}
	dato=tomar_dato(&ingreso);
	elemento=cargaConjuntoHardcodeado(dato);
	inicio = crearNodoLista(elemento);
	temp=inicio;
	printf("\n automata: ");
	printList(inicio);

	// tomo los datos del alfabeto
	dato=tomar_dato(&ingreso);
	elemento=cargaConjuntoHardcodeado(dato);
	temp->next=crearNodoLista(elemento);
	temp=temp->next;
	printf("\n automata: ");
	printList(inicio);
	
	//se supone que ahora leemos las funciones de trans
	dato=tomar_dato(&ingreso);/*
	elemento=cargaConjuntoHardcodeado(dato);
	temp->next=crearNodoLista(elemento);
	temp=temp->next;
	printf("\n automata: ");
	printList(inicio);
	*/
	
	// tomo los delta (conjunto de listas)
	
	//tomo el qo (STR)
	
	// tomo los F (conjunto)
	return inicio;
}
	/*
str tomar_delta(str cadena){
	*cadena = afterToken(*cadena, '['); //actualiza la cadena para que apunte a lo que le sigue a [
	str dato = beforeToken(*cadena, ']'); //me devuelve lo que esta antes de ], osea el dato que quiero
	
	//en dato voy a tener la primer funcion de trasicion, la cargo en una lista 
	tData funcion = cargaListaHardcodeada(dato);
	
	
	
	
	
	
	
	*cadena = afterToken(*cadena,'}'); //me devuelve lo que le sigue a la llave que abre
	*cadena = afterToken(*cadena, ','); //actualiza la cadena para que apunte a lo que le sigue a la coma
	//para ver si funciona
	printf("\n Cadena modificada: ");
	print(*cadena);
	printf("\n Datos extraidos: ");
	print(dato); 
	return dato; //devuelvo el dato que le sigue a la llave que abre
}
	
	*/
	
void mostrar_AF(tData AF){
	
	if(AF!=NULL){
		switch(AF->nodeType){
		case 1: //str
			print(AF->Str);
			mostrar_AF(AF->next);
			break;
		case 2: // set
			mostrarConjunto(AF->data);
			mostrar_AF(AF->next);
			break;
		case 3: //list
			printList(AF->data);
			mostrar_AF(AF->next);
			break;
		}
	}
	
}


