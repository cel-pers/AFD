#include "TAD_str.h"

str cargaNodo(char c){
	str nvo;
	nvo=create();
	nvo->dato=c;
	return nvo;
}
str create(){//creanodo()
	str nvo;
	nvo=(str)malloc(sizeof(Tnodo));
	nvo->sig=NULL;
	return nvo;
}
str load(){//ingresa una cadena
	str lis, aux,nvo;
	lis=nvo=aux=NULL;
	char c;
	lis=NULL; //porque está vacía
	aux=lis;
	printf("\n\n\ningrese la cadena de caracteres: ");
	c=getchar();
	while(c=='\n'){
		c=getchar();/*ignora saltos de linea iniciales*/
	}
		while (c!= '\n'){
		if(aux==NULL){/*La lista está vacía?*/
			lis=cargaNodo(c);
			aux=lis;
		}
		else /*la lista no está vacía*/{
			nvo=cargaNodo(c);
			aux->sig=nvo;
			aux=aux->sig;
		}
		c=getchar();
	}
	return lis;
}
	
	
void print (str cab){//muestra la lista
	str aux;
	aux=NULL;
	aux=cab;
	if (aux!=NULL){
		//printf("\nla cadena resultante:  ");
		while (aux!= NULL){
			printf("%c", aux->dato);
			aux=aux->sig;
		}
	}
	else{
		printf("\nLa lista esta vacia");
	}
	
}
	
str CopiaStr (str ori){
	str nva, R_nva, R_ori;/* cabeza, recorre nva, recorre ori*/
	R_nva=NULL;
	R_ori=ori; 
	
	if (ori == NULL)
		nva=NULL;
	else{
		/*por la estructura del create, debemos reemplazar
		el primer nodo por uno con un dato*/
		nva = cargaNodo(R_ori->dato);//la cabeza
		R_nva=nva;//copiamos la cabeza en otra función para recorrer
		R_ori=R_ori->sig;
		
		/*copiamos el resto de los nodos*/
		while(R_ori != NULL){
			R_nva->sig=cargaNodo(R_ori->dato);
			R_nva=R_nva->sig;
			R_ori=R_ori->sig;
		}
	}
	return nva;
}
		
		
str concat (str s1, str s2){
	str concat, cop1, cop2,aux;
	concat=create();
	
	if (s1 != NULL){
		cop1=CopiaStr(s1);//si la primera cadena era vacía
		concat=cop1;//entonces la ponemos en concat, siendo cop1 una copia de s1 y no un puntero al mismo, como el error de antes
		aux=concat; //para recorrer concat y pegar lo que sigue en la otra cadena
		while(aux->sig!=NULL){
			aux=aux->sig;}
		//enganchamos lo que nos faltaba
		cop2=CopiaStr(s2);
		aux->sig=cop2;
	}
	else {
		cop2=CopiaStr(s2);
		concat=cop2;
	}
	return concat;
}

	
str beforeToken (str s1, char letra){
	str bef, aux, nvo,befAux;
	bef=aux=befAux=nvo=NULL;
	aux=s1;
	while(aux!=NULL && aux->dato!=letra){
		if(bef==NULL){//si la lista aun esta vacia
			bef=cargaNodo(aux->dato);// ingreso el primer dato
			befAux=bef;
		}
		else{
			nvo=cargaNodo(aux->dato);
			befAux->sig=nvo;
			befAux=befAux->sig;
		}
		aux=aux->sig;
	}
	return bef;
}

	
	
str load2 (const char* cad /*esto de aqui adentro es un vector*/){//Agarra una cadena constante y la guarda como una lista enlazada
	str aux=NULL;
	str cab = NULL;
	int i;
	for(i=0; cad[i] != '\0'; i++){
		if(cab==NULL){
			cab=cargaNodo(cad[i]);
			aux=cab;
		}
		else{
			aux->sig=cargaNodo(cad[i]);
			aux=aux->sig;
		}
	}
	return cab;
}
	
void freetarStr(str s) {
	str actual = s;
	while (actual != NULL) {
		str sgte = actual->sig;
		free(actual);
		actual = sgte;
	}
}



str afterToken(str list, char tok ){
	str nlist, aux;
	nlist=create();
	aux=list;
	while(aux != NULL && (aux->dato) != tok)/* se fija si lo encuentra */
		aux=aux->sig;
	if (aux!=NULL){
		aux=aux->sig;
		nlist=aux;
	}
	return nlist ;
}
int comparaDato (char a, char b){
	int band=0;
	if (a==b)
		band=1;
	return band;
}
int comparaElem (str a,str b){
	str auxA, auxB;
	auxA=a;
	auxB=b;
	int ban=1;//empieza suponiendo como que todos los elem son iguales
	while (ban==1 && auxA != NULL && auxB != NULL){
		if (comparaDato(a->dato, b->dato)==0 )//si una comparación es falsa se cambia la bandera
			ban=0;
		auxA=auxA->sig;
		auxB=auxB->sig;
	}
	if (auxB != NULL){/*por si la cadena a estuviese incluida en la cadena b*/
		ban=0;
	}
	return ban;
}
	

	int pertenece(str cab,str cad){
		int b;
		b=0;
		while((cab!=NULL && cad!=NULL) && b==0){
			if(cab->dato==cad->dato){
				cab=cab->sig;
				cad=cad->sig;
			}
			else b=1;
		}
		if(b==1)
			return -1;
		else
			if(cab==NULL && cad==NULL)
			return 0;
			else return-1;
	}

		
		
	int comparacad(str a,str b){
		while((a!=NULL && b!=NULL)){
			if(a->dato!=b->dato)
				return -1;
			a=a->sig;
			b=b->sig;
		}
		if(a==NULL && b==NULL)
			   return 0;
		else 
			return -1;
	}

		
		
		int compareStrChar(str a, char token){
			
			int rdo;
			
			if(a->dato==token){
				rdo=0;
			}else rdo=-1;
			return rdo;
		}

// nuevas funciones

str tomar_dato(str *cadena){
	*cadena = afterToken(*cadena, '{'); //actualiza la cadena para que apunte a lo que le sigue a la llave que abre
	str dato = beforeToken(*cadena, '}'); //me devuelve lo que esta antes de la llave que cierra, osea el dato que quiero
	
	*cadena = afterToken(*cadena,'}'); //me devuelve lo que le sigue a la llave que abre
	*cadena = afterToken(*cadena, ','); //actualiza la cadena para que apunte a lo que le sigue a la coma
	//para ver si funciona
	printf("\n Cadena modificada: ");
	print(*cadena);
	printf("\n Datos extraidos: ");
	print(dato); 
	return dato; //devuelvo el dato que le sigue a la llave que abre
}
