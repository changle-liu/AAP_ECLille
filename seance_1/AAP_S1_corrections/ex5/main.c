#include <stdio.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h"  

//#define DEBUG
#include "../include/check.h"  

#define MAXLEN 10

int main(int argc, char ** argv) {

	int * p; 

	CLRSCR(); 
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	// Provoquer une segmentation fault à cause de l’utilisation 
	// d’un pointeur sur int mal/non initialisé
	/////////////////////////////////////////////////////////////////////////
	
	CODE(int * p);
	
	DUMPHEAD();		
	DUMPAD(p); 		
	DUMPINT(*p);
	NL();

	CODE(*p = 3); 
	NOTE("Cette affectation peut provoquer une erreur car p pointe n'importe où \n");
	
	// correction	
	//*p = 3; // TODO: A commenter : risque de SEGFAULT ! 

	ENTER2CONTINUE();
	HR();

	CODE(p = N \bULL);
	p = NULL;

	DUMPHEAD();		
	DUMPAD(p); 	
	NL();	

	CODE(*p = 4); 
	NOTE("Cette affectation provoque une erreur car p pointe vers NULL \n");
	 	
	// correction
	//*p = 4; // TODO: A commenter : SEGFAULT !

	/////////////////////////////////////////////////////////////////////////
	// Résoudre le problème en utilisant une allocation dynamique de mémoire
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	printf("Allocation de mémoire pour un entier\n");

	// Les fonctions malloc()  et  calloc()  renvoient  un  pointeur
	// vers  la mémoire  allouée. 
	// Si elles échouent, elles renvoient NULL. 

	// TODO: p doit pointer vers une zone de mémoire que l'on peut modifier, sur le tas
	// TODO: Il faut tester les valeurs de retour des appels système : malloc peut échouer !

	TOUCH_HERE("Ben là, c'est à vous ! \n");	
	// correction
	CODE(p = (int *) malloc(sizeof(int))); 
	CHECK_IF(p = (int *) malloc(sizeof(int)), NULL, "malloc"); 

	/*	
	// équivalent à : 
	p = (int *) malloc(sizeof(int));
	if (p == NULL) {
		perror("malloc"); 
		exit(EXIT_FAILURE);
	}
	*/
	
	CODE(*p = 4);
	*p = 4;	// Cette fois on n'a plus besoin de commenter... 

	DUMPHEAD();		
	DUMPAD(p); 		
	DUMPINT(*p);
	
	// TODO : Inscrire les adresses des variables manipulées sur le tas 
	// dans la représentation mémoire située sur le slide suivant

	return 0;
}
