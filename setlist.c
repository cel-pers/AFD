




#include "setlist.h"

//CREA NODOS

tData crearNodoStr(str elem){
	tData nuevo;
	nuevo=(tData)malloc(sizeof(TArbol));
	nuevo->nodeType= STR;//1- str
	nuevo->Str=elem; 
		return nuevo;
}
	
tData crearNodoLista(tData contenido){ 
	
	tData nuevo=(tData)malloc(sizeof(TArbol));
	nuevo->nodeType = LIST;
	nuevo->data=contenido; 
	nuevo->next=NULL; 
	return nuevo;
}	
		
tData crearNodoSet(tData data){
	tData nuevo=(tData)malloc(sizeof(TArbol));
	nuevo->nodeType = SET;
	nuevo->data=data; //o asigno =dato
	nuevo->next=NULL; // = sig;
	return nuevo;
}
		
		
tData creaSetVacio(){
	return NULL;
}
	
tData creaListVacio(){
	return NULL;
}
	
	
	
	
	
	
/*FUNCIONES DEL CONJUNTO*/	

void mostrarConjunto(tData conj){
	printf("{");
	while (conj!=NULL){
		if(conj->nodeType == SET && conj->data !=NULL){
			if(conj->data->nodeType == STR){
				print(conj->data->Str);
				if(conj->next!=NULL)
				printf(" ");
			}else if(conj->data->nodeType == LIST){
				printList(conj->data);
			}
		}
		conj=conj->next;
	}
	printf("}");
}
	/*
void mostrarConjunto(tData conj){ //RECURSIVO no va a funcionar con delta
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
			return; 
		}
		mostrarConjunto(conj->next);
	}else{
		printf("}");
	}
}
	*/	
		
void appendSet (tData *ini,tData elem ){
	/*VARIABLES*/
	tData aux= NULL;
	
	//if ((*ini)->nodeType == SET && elem->nodeType == STR){  //Verificamos que los argumentos pasados sean correctos
		
		if (*ini != NULL){//Ya tenemos elementos y hay que enganchar al final
			if (inSet(*ini, elem->Str) != 0 ){ 
				// no pertenece segun la funcion de la sofi 
				aux = *ini;
				
				while (aux->next != NULL){//recorrer el conjunto
					aux = aux->next;
				}
				aux->next= crearNodoSet(elem); //enganchamos el elemento al final
			}else {
				printf("\n ERROR. el elemento ya esta en el conjunto");
			}
			
		}else{
			*ini=crearNodoSet(elem);
		}
	//}
	
}

int inSet(tData lista,str cad){
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
	
	
	
	
		
tData cargaConjunto(){
	/*DECLARACION E INICIALIZACION DE VARIABLES*/
	int op;
	
	tData elem,conj;
	elem=NULL; //para el nodo str
	conj=NULL; //para el conjunto
	
	str cad;
	cad=NULL;
	
	/*PRUEBA*/
	printf("\n 1. INGRESAR UN ELEM || 2. CREAR CONJ. VACIO ||3. SALIR");
	printf("\n opcion ingresada: ");
	scanf("%d", &op);
	
	
	if(op==2)
		conj=creaSetVacio();
	
	
	while (op==1){
		fflush(stdin);
		cad=load();
		elem=crearNodoStr(cad);
		appendSet (&conj, elem);
		
		printf("\n 1. INGRESAR OTRO ELEM ||2. SALIR");
		printf("\n opcion ingresada: ");
		scanf("%d", &op);
	}
	printf("\n Conjunto resultante: {");
	
	mostrarConjunto(conj);
	
	return conj ;
}

	
	
tData cargaConjuntoHardcodeado(str cad){ 
	
	tData conj;
	conj=NULL; //para el conjunto
	str ncad=NULL, vcad=NULL, aux=NULL;
	char c=',';
	//debo separar y cargar cada elemento en un nodo STR
	aux=cad;
	
	while(aux!=NULL){
		if(compareStrChar(aux,c)==0||aux->sig==NULL)//son iguales
		{
			//PRIMER ELEMENTO
			if(conj==NULL){
				ncad=beforeToken(cad,c);
				vcad=afterToken(cad,c);
				appendSet(&conj, crearNodoStr(ncad));
			}
			
			else{
				ncad=beforeToken(vcad,c);
				appendSet(&conj, crearNodoStr(ncad));
				vcad=afterToken(vcad,c);
			}
			
		}
		aux = aux->sig;
	}
	printf("\n Conjunto resultante: ");
	mostrarConjunto(conj);
	
	return conj ;
}
	tData cargaListaHardcodeada(str cad){ 
		
		tData lista=NULL;
		
		str ncad=NULL, vcad=NULL, aux=NULL;
		char c=',';
		//debo separar y cargar cada elemento en un nodo STR
		aux=cad;
		
		while(aux!=NULL){
			if(compareStrChar(aux,c)==0||aux->sig==NULL)//son iguales
			{
				//PRIMER ELEMENTO
				if(lista==NULL){
					ncad=beforeToken(cad,c);
					vcad=afterToken(cad,c);
					lista=push(lista, crearNodoStr(ncad));
				}
				
				else{
					ncad=beforeToken(vcad,c);
					lista=push(lista,crearNodoStr(ncad));
					
					vcad=afterToken(vcad,c);
				}
				
			}
			aux = aux->sig;
		}
		printf("\n lista resultante: ");
		printList(lista);
		
		return lista ;
	}

tData copiaNodoStr(tData org){ //devuelve un nodo tData STR
	tData copia = NULL;
	if(org->nodeType == STR){
		copia=crearNodoStr(org->Str);
		return copia;
	}else return NULL;
}
	
	

tData copiaNodoSet(tData org){ //me devuelve un nodo del tipo SET
	tData copia=NULL;
	tData elem=NULL;
	
	if(org->nodeType==SET){ //leo nodos del tipo SET
		elem=copiaNodoStr(org->data); //le paso el nodo dato que deberia ser str(me lo verifica la funcion copiaNodoStr)
		copia=crearNodoSet(elem);
		return copia;
		
	}else return NULL;
}
	
	
tData unionSet(tData A, tData B){
	
	tData U=NULL;
	tData aux=NULL;
	
	//caso ambos conj. vacios
	if(A==NULL && B==NULL) return NULL;
	
	//casos especiales
	if(A==NULL){
		while(B!=NULL){
			
			appendSet(&U,copiaNodoStr(B->data));
			B=B->next;
		}
		return U;
	}
	if(B==NULL){
		while(A!=NULL){
			
			appendSet(&U,copiaNodoStr(A->data));
			A=A->next;
		}
		return U;
	}
	if(A->nodeType == SET && B->nodeType == SET){
		while(A!=NULL){
			if(U==NULL){ //conjunto vacio
				U = copiaNodoSet(A);
				aux=U;
				A=A->next;
			}else{
				aux->next=copiaNodoSet(A);
				aux=aux->next;
				A=A->next;
			}
		}
		
		//aux apunta al ultimo elemento de la union
		
		while(B != NULL){
			if(inSet(U,B->data->Str)== -1)//va a funcionar si el dato del set es str. si no esta en la union entonces lo copio
			{
				aux->next=copiaNodoSet(B);
				aux=aux->next;
			}
			B=B->next;
		}
	}
	return U;
}

int cardinalidad (tData arb){//supongo que tiene sentido para conjuntos
	int c=0; //para el contador
	tData aux=NULL;
	if(arb != NULL && arb->nodeType==2){//si el padre existe, entonces hay algo para contar //no usamos indireccion porque solo tenemos punteros a la estructura tArbol
		aux=arb;
		while (aux != NULL ){
			c++;
			aux=aux->next;
		}
	}else{
		printf("\nEl conjunto es vacio");
		c=0;
	}
	return c;
}
	
	
	
int inclusion (tData A, tData B){//Para la inclusion vamos a usar la cardinalidad
	
	if(A==NULL && B==NULL){
		return 1; //porque el vacio esta incluido en el conjunto vacio
	}
	
	//en el caso en el que A sea un conj vacio 
	if(A==NULL)
	   return 1;
	
	// verificamos si A y B son conjuntos válidos
	if (A->nodeType != 2 || B->nodeType != 2) {
		printf("\nNo se pudo realizar la operación, uno o ambos nodos no son conjuntos validos.\n");
		return 0; // No se puede determinar inclusion
	}
	
	//caso en que ambos conjuntos sean vacio
	
	
	
	//CASO CARDINALES, incluye el caso en el que B es vacio
	int cardA = cardinalidad(A);
	int cardB = cardinalidad(B);
	if(cardA>cardB){
		return 0;//si la cardinalidad del primer conjunto es mas grande que la cardinalidad del conjunto B, entonces significa que no puede estar incluido en el conjunto B
	}
	
	
	//entonces vamos por el camino de analizar cada elemento
	
	tData aux=A;
	while (aux != NULL && inSet(B,aux->data->Str)==0){// mientras no lleguemos al elem final de A y todos los elementos vayan perteneciendo al conjunto B
		aux=aux->next;
	}
	//preguntamos por cual condición del ciclo salimos
	if (aux == NULL) //salimos porque se termino de analizar todo el conjunto y todos los elementos estan incluidos, sino se hubiera cortado antes porque pertenece == 0
		return 1;
	else 
		return 0;
	
}
	
	
tData diferencia(tData A, tData B){
	tData D=NULL;
	tData I=interseccion(A,B);
	//A menos la interseccion de los dos
	while(A!=NULL){
		if(inSet(I,A->data->Str)==-1){ //si el elemento de A no esta en la interseccion entonces lo copio a diferencia
			
			appendSet(&D,copiaNodoStr(A->data)); //copio dato y lo agrego al conjunto
			
		}
		A=A->next;
	}
	return D;
}
	
void agrega(tData*cab,tData cad){

	int p,b=0;
	tData aux = NULL; 
	tData copia = crearNodoSet(crearNodoStr(cad->data->Str));
	if(*cab==NULL){
		*cab=copia;
	}else {
		aux=*cab;
		while(aux->next!=NULL && b==0){
			/*while(aux->sig!=NULL && b==0){*/
			p=inSet(aux,cad->data->Str);
			if(p==-1){
				b=1;
				aux=aux->next;
			}
			if(b==0)  aux->next=copia;
		}
	}
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
				b=1;
			}
			aux=aux->next;
		}
		A=A->next;
	}
	return C;
}

	
	
	
	
	//FUNCIONES DE LISTA 	
	
//AGREGA UN NODO AL FINAL DE LA LISTA
tData push (tData lista, tData nuevoNodo){
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
/*void printList(tData lista){
	printf("[");
	while(lista!=NULL){
		if(lista->nodeType == LIST && lista->data !=NULL && lista->data->nodeType == STR){
			print(lista->data->Str);
			printf(" ");
		}
		lista=lista->next;
	}
	printf(" ]");
}*/

	void printList(tData lista){
		printf("[");
		while(lista!=NULL){
			if(lista->nodeType == LIST && lista->data !=NULL){
				if(lista->data->nodeType == STR){
					print(lista->data->Str);
					printf(" ");
				}else if(lista->data->nodeType == SET){
					mostrarConjunto(lista->data);
				}
				
			}
			lista=lista->next;
		}
		printf("]");
	}
	
