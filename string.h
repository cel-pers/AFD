#ifndef STRING_H
#define STRING_H

typedef struct Nodo{
	char dato;
	struct Nodo *sig;
}tNodo;
typedef tNodo * str;

str createStr();
str load();
str load2(const char*);
str load3(const char*);
void print(str);
str concat(str,str);
str beforeToken(str, char);
str afterToken(str,char);
void liberarLista(str); //agregada por mi
str cargaNodo(char);
int pertenece(str cab,str cad);
int compare2str(str,str);
int compareStrChar(str,char);
int comparacad(str ,str );
int sonIguales(str,str);
#endif
