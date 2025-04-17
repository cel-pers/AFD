#include "string.h"
#include <stdlib.h>
#include <stdio.h>


str createStr(){ //Crea nodo
	return NULL;
}
str cargaNodo(char c){
	str nuevo;
	nuevo=(str)malloc(sizeof(tNodo));
	nuevo->dato=c;
	nuevo->sig=NULL;
	return nuevo;
}
void iporCola(str* cab, char carac){
	str aux, nuevo;
	aux=*cab;
	nuevo=cargaNodo(carac);
	if(*cab!=NULL){
		while(aux->sig!=NULL)
			aux=aux->sig;
		aux->sig=nuevo;
	}else *cab=nuevo;
	
}
str load(){
	str cab;
	cab=NULL;
	char c;
	c=getchar();
	
	while(c!='\n'){
		iporCola(&cab, c);
		c=getchar();
	}
	return cab;
}	

void print(str ini){
	str aux;
	if(ini!=NULL){
		aux=ini;
		while(aux!=NULL){
			printf("%c",aux->dato);
			aux=aux->sig;
		}
	}else printf("\nLista vacia");
	
}

str load2(const char* frase){
	str cab=NULL;
	int i;
	for(i=0; frase[i] != '\0';i++){
		iporCola(&cab,frase[i]);
	}
	return cab;
}

str concat(str cad1, str cad2){
	str cadR=NULL;
	str aux=NULL;
	if(cad1!=NULL){
		cadR=cad1;
		aux=cadR;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=cad2;
	}else{
		cadR=cad2;
	}
	return cadR;
	
}
str beforeToken(str cad, char token){
	str rdo=NULL;
	while(cad!=NULL && compareStrChar(cad->dato,token)==1){
		iporCola(&rdo,cad->dato);
		cad=cad->sig;
		
	}
	return rdo;
	
}
str afterToken(str cadena, char token){
	str rdo=NULL;
	while(cadena!=NULL && compareStrChar(cadena->dato,token)==1){
		cadena=cadena->sig;
	}
	if(cadena!=NULL){
		cadena=cadena->sig;
		rdo=cadena;
	}
	
	return rdo;
}
//liberar memoria
	void liberarLista(str lista){
		str temp;
		while(lista!=NULL){
			temp=lista;
			lista=lista->sig;
			free(temp);
		}
	}

str load3(const char* nombreArchivo){
	FILE* archivo= fopen(nombreArchivo, "r"); //abre el archivo en modo lectura
	if(archivo == NULL){
		printf("Error, no se pudo abrir el archivo ");
		
	}
	str lista =NULL;
	char c;
	//leer el archivo caracter por caracter
	while((c=fgetc(archivo))!= EOF){
		iporCola(&lista,c);
	}
	fclose(archivo);
	return lista;
	
}
int isin(str c1, str c2){ //verifica si uno se encuentra contenido en otro
	int rdo=1; //inicia en true
	while(c1!=NULL && c2!=NULL && rdo==1){
		if(c1->dato==c2->dato){
			c1=c1->sig; //muevo los dos, porque es componente a componenete
			c2=c2->sig;
		}else{
			rdo=0; //false, hay un elemento que no es igual
		}
	}
}


int compare2str(str A, str B){
	str auxA=A;
	str auxB=B;
	int rdo;
	while(auxA!=NULL && auxB!=NULL && rdo!=0){
		
		if(auxA->dato==auxB->dato){
			auxA=auxA->sig;
			auxB=auxB->sig;
		}else{
			rdo=1;
		}
	}
	if(auxA!=NULL || auxB!=NULL){
		rdo=0;
	}else{
			rdo=1;
	}
	// 0 iguales 1 diferentes
	return rdo;
	
}

int compareStrChar(char carac, char token){
	
	int rdo;
	
	if(carac==token){
		rdo=0;
	}else rdo=1;
	return rdo;
}

	int sonIguales(str a, str b) {
		while (a != NULL && b != NULL) {
			if (a->dato != b->dato) return 0; // Caracteres diferentes
			a = a->sig;
			b = b->sig;
		}
		// Ambas cadenas deben terminar al mismo tiempo
		return (a == NULL && b == NULL);
	}
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
											}
