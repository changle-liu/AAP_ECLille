#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"	// T_elt 
#include "stack_cs.h"


int main(int argc, char ** argv) {
	T_stack s;
	T_elt e=6;  

	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	// Développer les fichiers elt.h et elt.c
	// Développer les fichiers stack_sc.h et stack_sc.c
	// Développer un programme de test permettant d’utiliser ces fonctions
	/////////////////////////////////////////////////////////////////////////
	printf("%s\n",toString(e));
 	// Récupérer une pile d'exemple
	s = exampleStack(5); 

	// Afficher la pile
	showStack(&s);

	// Ajouter un élément 
	push(genElt(),&s);

	// Afficher la pile
	showStack(&s);

	// Afficher le sommet 
	printf("Sommet : %s\n", toString(top(&s)));

	// Dépiler un élément
	e = pop(&s);

	// Afficher l'élément extrait
	printf("Elt extrait : %s\n", toString(e));

	// Afficher la pile
	showStack(&s);

	// Vider la pile
	emptyStack(&s);

 	// Afficher la pile 
	showStack(&s);

	return 0;
}







