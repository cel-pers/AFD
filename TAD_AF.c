#include "TAD_AF.h"
//creando el automata
tData  tomar_delta(str* cadena){
	//declaraciones e inicializaciones
	//tData conj, trans, aux ;
	
	tData conj = NULL; //conjunto en donde guardo las listas
	tData trans = NULL;
	str dato = NULL;
	tData aux = NULL;
	//AUTOMATa
	//{q0,q1},{0,1},{[q0,0,q0],     [q0,1,q1],[q1,0,q0],[q1,1,q1] }      ,q0,{q1}]
	//ciclo para ir guardando las trans
	
	while(compareStrChar(*cadena,'}')== -1){//mientras no se vaya del conjunto de transiciones
		
		//Cadena es lo que resta, en un comienzo, todas las trans
		*cadena = afterToken(*cadena, '['); //actualiza la cadena para que apunte a lo que le sigue a [
		
		//dato es lo que tomamos de la cadena, la 1ra transición , UNA transicion
		dato = beforeToken(*cadena, ']');
		
		//en dato voy a tener la primer funcion de trasicion, la cargo en una lista
		trans = cargaListaHardcodeada(dato);
		
		if(conj==NULL){ //si el conj, esta vacio		
			conj=crearNodoSet(trans); //creamos el nodo con una trans
			aux=conj; //guardamos el conj en un auxiliar, para no perdeer la cabeza
		}else{ //sino, el conjunto de transiciones ya tiene elementos
			aux->next=crearNodoSet(trans); // como el conj tiene elementos, ponemos el nuevo en el siguiente nodd
			aux=aux->next;//actualizamos next
		}
		
		//actualiza la cadena a lo que esta despues de ] 
		*cadena = afterToken(*cadena, ']');
		
		if(compareStrChar(*cadena,',')==0)
			*cadena = afterToken(*cadena, ',');
		
		
	}
	return conj;
	
}


//creando el automata
//ingreso=	{q0,q1},{0,1},{[q0,0,q0],     [q0,1,q1],[q1,0,q0],[q1,1,q1] }      ,q0,{q1}
tData crear_AF(str ingreso){
	
	tData inicio = NULL;
	tData temp=NULL; //para no perder la cabeza
	tData elemento=NULL;  //pongo el dato en un nodo tData STR
	str dato=NULL;
	
	for(int i=1;i<=5;i++){
		if(i<3 || i==5)//casos set
		{
			dato=tomar_dato(&ingreso);
			elemento=cargaConjuntoHardcodeado(dato);
			
			if(inicio==NULL){
				inicio=crearNodoLista(elemento);
				temp=inicio;
			}else{
				temp->next=crearNodoLista(elemento);
				temp=temp->next;
			}
			
		}else{
			if(i==3){
				ingreso=afterToken(ingreso,'{');
				elemento=tomar_delta(&ingreso);
				temp->next=crearNodoLista(elemento);
				temp=temp->next;
				
			}else{
				
				ingreso=afterToken(ingreso,',');
				print(ingreso);
				dato=beforeToken(ingreso,',');
				printf("\ndato ");
				print(dato);
				ingreso=afterToken(ingreso,',');
				elemento=crearNodoStr(dato);
				temp->next=crearNodoLista(elemento);
				temp=temp->next;
			}
		}
	}

	
	printf("\n\n Automata \n\n");
	printList(inicio);
	
	return inicio;
}


