#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"	//T_elt

// implémentation des piles contigüe dynamique
#include "stack_cd.h"

int main(int argc, char ** argv) {
	T_stack s;
	T_elt e;  

	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	// Développer les fichiers elt.h et elt.c
	// Développer les fichiers stack_cd.h et stack_cd.c
	// Développer un programme de test permettant d’utiliser ces fonctions
	/////////////////////////////////////////////////////////////////////////

 	// Récupérer une pile d'exemple
	s = exampleStack(5); 

	// Afficher la pile
	showStack(&s);

	// [DEBUG] Afficher le nbr max d'elts dans la pile
	printf("nbr max d'elements : %d\n", s.nbMaxElt);

	NL();

	// Ajouter un élément (dans une pile trop petite)
	push(genElt(),&s);

	// Afficher la pile
	showStack(&s);

	// [DEBUG] Afficher le nbr max d'elts dans la pile
	printf("nbr max d'elements : %d\n", s.nbMaxElt);

	// Afficher le sommet 
	printf("Sommet : %s\n", toString(top(&s)));

	NL();

	// Dépiler un élément
	e = pop(&s);

	// Afficher l'élément extrait
	printf("Elt extrait : %s\n", toString(e));

	// Afficher la pile
	showStack(&s);

	NL();

	// Vider la pile (et la libérer)
	freeStack(&s);

 	// Afficher la pile 
	showStack(&s);

	return 0;
}







