#include <stdio.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

void incr(int * p);
void swap(int * p1, int * p2);

int main(int argc, char ** argv) {

	int i,j; 
	i=j=1; 

	CLRSCR();
	WHOAMI(); 

	CODE(i=j=1); 
	NOTE("Comment interpréter cette opération ?\n");

	/////////////////////////////////////////////////////////////////////////
	// Produire une fonction permettant d’incrémenter une valeur passée en paramètre
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	printf("i vaut %d\n",i);	
	printf("On incrémente i\n");
	incr(&i);
	printf("i vaut %d\n",i);	

	/////////////////////////////////////////////////////////////////////////
	// Produire une fonction permettant d’échanger les valeurs de deux variables
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	printf("i vaut %d, j vaut %d\n",i,j);	
	printf("On échange i et j\n");
	swap(&i,&j);
	printf("i vaut %d, j vaut %d\n",i,j);	

	return 0;
}

void incr(int * p) {
	//TODO : Produire une fonction permettant d’incrémenter une valeur dont l'adresse est passée en paramètre
	TOUCH_HERE("Ben là, c'est à vous ! \n");

	// correction 
	(*p)++;
}

void swap(int * p1, int * p2) {
	//TODO : Produire une fonction permettant d’échanger les valeurs de deux variables dont les adresses sont passées en paramètre
	TOUCH_HERE("Ben là, c'est à vous ! \n");

	// correction
	int aux = *p1; 
	*p1 = *p2; 
	*p2 = aux; 
} 

