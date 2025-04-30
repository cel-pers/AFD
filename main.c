#include "setlist.h"
#include <stdio.h>

int main(){
	str ingreso=load2("{q0,q1},{0,1},{[q0,0,q0],[q0,1,q1],[q1,0,q0],[q1,1,q1]},q0,{q1}");
	
	tData automata=crear_AF(ingreso);
	//mostrar_AF(automata);
}
