#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
#include "list.h"
#include "stack_cld.h"

int main(int argc, char ** argv) {
	T_stack s = NULL; 
	T_elt e;
	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	// Ajouter un élément 
	push(genElt(),&s);
	push(genElt(),&s);
	push(genElt(),&s);

	// Afficher la pile
	showStack(&s);NL();

	// Afficher le sommet 
	printf("Sommet : %s\n", toString(top(&s)));

	NL();

	// Dépiler un élément
	e = pop(&s);

	// Afficher la pile
	showStack(&s);NL();

	// Afficher l'élément extrait
	printf("Elt extrait : %s\n", toString(e));

	NL();

	// Vider la pile
	emptyStack(&s);

 	// Afficher la pile 
	showStack(&s);
 	

	return 0;
}







