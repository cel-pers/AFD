#ifndef TAD_STR_H
#define TAD_STR_H
#include <stdio.h>
#include <stdlib.h>
/*ESTRUCTURA DE UN NODO*/
typedef struct nodo{
	char dato;
	struct nodo* sig;
}Tnodo;//definicion de la estructura de un nodo
typedef Tnodo* str; //declaración de la estructura de un ptr a nodo, cele puso que era str


/*FUNCIONES DE LA ESTRUCTURA*/
str create(); //crea nodo
str load (); // Ingresa una cadena
str load2(const char*);
str load3(const char*); //Lee archivo txt
void print (str); // muestra una cadena
str concat(str, str);//concatena dos cadenas
str beforeToken (str, char);// Recorre la cadena hasta que encuenta el caracter que estoy buscando y devuelve todo lo que venía antes
void freetarStr(str);
str afterToken(str, char);/*Supongo que recorre la cadena hasta que encuentra lo que estoy buscando y devuelve todo lo que hay despues*/
//int isin(string);/*********************//*verifica si un str está contenido en otro str*/
int comparaElem (str,str);
str CopiaStr (str); //copia un str y lo retorna en otra cabeza
int pertenece(str,str);
int comparacad(str,str);
int compareStrChar(str, char);


//nuevas funciones 
str tomar_dato(str*);
#endif
