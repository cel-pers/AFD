#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/*  lista [a,b,c,f] importa el orden
	conjunto {a,b,c,d} no importa el orden
*/



tData crearNodoStr(str elem){
	tData nuevo;
	nuevo=(tData)malloc(sizeof(TArbol));
	nuevo->nodeType= STR;//1- str
	nuevo->Str=elem; /
	return nuevo;
}

tData crearNodoLista(tData contenido){ 
	
	tData nuevo=(tData)malloc(sizeof(TArbol));
	nuevo->nodeType = LIST;
	nuevo->data=contenido; 
	nuevo->next=NULL; 
	return nuevo;
}	
	
tData crearNodoSet(tData data)
{
	tData nuevo=(tData)malloc(sizeof(TArbol));
	nuevo->nodeType = SET;
	nuevo->data=data; //o asigno =dato
	nuevo->next=NULL; // = sig;
	return nuevo;
}

//FUNCIONES DE CONJUNTOS
	
tData cargaConjunto(){
	
	int op;
	printf ("\n 1.Ingresar | 2.Finalizar  ");
	scanf("%d", &op);
	fflush(stdin); // borra el buffer
	
	if(op == 1){
		printf("\nIngrese el elemento del conjunto: ");
		str cad=load();
		
		/*if(pertenece(cad,cad)==0){//si no pertenece al conjunto
			cab->data= crearNodoStr(load());
		}*/
		tData nuevoStr=crearNodoStr(cad); //primer elemento 
		tData aux=cargaConjunto();	
		
		return crearNodoSet(nuevoStr,aux);
	}else	
		return NULL;	
}


void mostrarConjunto(tData conj){ //RECURSIVO
	if(conj!=NULL){
		
		if( conj->data != NULL){
			
			if(conj->data->nodeType == STR){
				print(conj->data->Str); //muestro cadena
			}else{
				printf("\nError");
			}
		}
		if(conj->next != NULL){
			printf(", ");
		}else{
			printf("}");
		}
		mostrarConjunto(conj->next);
	}
}

int cardinalidad (tData arb){//supongo que tiene sentido para conjuntos
	int c=0; //para el contador
	tData aux=NULL;
	if(arb != NULL && arb->nodetype==2){//si el padre existe, entonces hay algo para contar //no usamos indiferencia porque solo tenemos punteros a la estructura tArbol
		aux=arb;
		while (aux != NULL ){
			c++;
			aux=aux->next;
		}
	}else{
		printf("El conjunto no tiene ningun elemento o no se ha mandado a analizar un conjunto.");
		c=-1;
	}
	return c;
}

	
	
int inclusion (tData A, tData B){//Para la inclusion vamos a usar la cardinalidad
	
	// verificamos si A y B son conjuntos válidos
	if (A == NULL || A->nodetype != 2 || B == NULL || B->nodetype != 2) {
		printf("No se pudo realizar la operación, uno o ambos nodos no son conjuntos válidos.\n");
		return 0; // No se puede determinar inclusión
	}
	
	
	
	//en el caso en el que A sea un conj vacío 
	if(A->dato.data==NULL && A->next == NULL)
		return 1;
	
	
	//CASO CARDINALES
	int cardA = cardinalidad(A);
	int cardB = cardinalidad(B);
	if(cardA>cardB){
		return 0;//si la cardinalidad del primer conjunto es mas grande que la cardinalidad del conjunto B, entonces significa que no puede estar incluido en el conjunto B
	}
	//entonces vamos por el camino de analizar cada elemento
	
	tData aux=A;
	while (aux != NULL && inArbol(B,retornaDato(aux))==1){// mientras no lleguemos al elem final de A y todos los elementos vayan perteneciendo al conjunto B
		aux=aux->next;
	}
	//preguntamos por cual condición del ciclo salimos
	if (aux == NULL) //salimos porque se termino de analizar todo el conjunto y todos los elementos estan incluidos, sino se hubiera cortado antes porque pertenece == 0
		return 1;
	else 
		return 0;
	
}
void eliminaConjunto(tData*lista){
	tData aux,tempo; aux=NULL; tempo=NULL;
	aux=*lista;
	while(aux!=NULL){
		tempo=aux;
		aux=aux->next;
		free(tempo);
	}
	*lista=NULL;
}

//sofimicol
int inArbol(tData lista,str cad){
	tData aux; aux=NULL;
	int t,b;
	b=-1;
	while(lista!=NULL && b==-1){
		aux=lista->data;
		t= pertenece(aux->Str,cad);
		if(t==0)
			b=0;
		lista=lista->next;
	}
	if(b==0)
	  return 0;
	else 
	return -1;
}

tData interseccion(tData A,tData B){
	tData C=NULL ,aux=NULL;
	int p,b;
	while(A!=NULL){
		aux=B;	
		b=0;
		while (aux!=NULL && b==0){
			p=comparacad(A->data->Str,aux->data->Str);
			if(p==0){
				agrega(&C,aux);
				b=1;}
			aux=aux->next;
		}
		A=A->next;
	}
	return C;
}

	
//FUNCIONES DE LISTA (PROFE )	
	
//AGREGA UN NODO AL FINAL DE LA LISTA
tData push (tdata lista, tData nuevoNodo){
	if(lista!=NULL){
		tData temp= lista;
		while(temp->next){
			temp=temp->next;
		}
		temp->next = nuevoNodo;
		return lista;
	}
	else {
		return nuevoNodo;
	}
}


//MUESTRA LA LISTA
void printList(tData lista){
	printf("[");
	while(lista!=NULL){
		if(lista->nodeType == LIST && lista->data !=NULL && lista->data->nodeType == STR){
			print(lista->data->strData);
			printf(" ");
		}
		lista=lista->next;
	}
	printf(" ]");
}

//funciones comunes
//liberacion de memoria
void liberarArbol(tData arbol){
	switch(arbol->nodeType){
	case STR:
		liberarLista(arbol->Str);
		break;
	case SET:
		liberarArbol(arbol->data);
		liberarArbol(arbol->next);
		break;
	}
}

//sofimicol
void agrega(tData*cab,tData cad){
	int p,b=0;
	tData aux==null; 
	tData copia = crearNodoSet(crearNodoStr(cad->data->Str));
	if(*cab==NULL){
		*cab=copia;
	}else {
		aux=*cab;
		while(aux->next!=NULL && b==0){
		/*while(aux->sig!=NULL && b==0){*/
			p=inArbol(aux,cad->data->Str);
			if(p==-1){
				b=1;
				aux=aux->next;
			}
			if(b==0)  aux->next=copia;
		}
/*
	if(*cab==NULL){
	*cab=creaNodoSet();
	tData aux=*cab;
	cargaConjunto(&aux,cad);
	cargaConjunto(&aux->next,cad);
	}else{
	switch(*cad->dato){
	case ']': *cad=*cad->sig;
	case'}': *cad=*cad->sig;
	case '{':
	
	break;
	case '[': *cad=*cad->sig;
	*cab->dato=crearNodoLista();
	
	break;
	
	
	
	default:
	
	*cab->Dato=crearNodoStr(beforeToken(*cad,','));
	*cad=afterToken(*cad,',');
	
	break;
	}
	
	//Recorrido recursivo
	void recorrerArbol(tData arbol){
	if(arbol==NULL){
	printf("\nArbol vacio");
	}
	else{
	switch(arbol->nodeType){
	
	case STR: 
	//Procesa la cadena
	print(arbol->Str);
	break;
	case SET:
	//Procesa conjunto
	printf("{");
	recorrerArbol(arbol->data);
	printf("}");
	if(arbol->next != NULL){
	printf(", ");
	recorrerArbol(arbol->next);
	}
	break;
	case LIST:
	//procesa lista
	printf("[");
	recorrerArbol(arbol->data);
	printf("]");
	if(arbol->next != NULL){
	printf(",");
	recorrerArbol(arbol->next);
	}
	break;	
	}	
	}
	}	
	
	*/
