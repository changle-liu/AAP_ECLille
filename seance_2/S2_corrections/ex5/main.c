#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"
#include "list.h"

int main(int argc, char ** argv) {
	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	T_list l = NULL; 
	T_elt e; 


	// ajouter des éléments dans la liste 

	l = addNode(genElt(), l); 
	l = addNode(genElt(), l); 
	l = addNode(genElt(), l); 
	l = addNode(genElt(), l); 


	// afficher la liste 
	showList(l); NL();

	// récupérer le premier élément d'une liste, et l'afficher 
	e = getFirstElt(l);
	printf("Premier elt : %s\n", toString(e));

	// supprimer le premier élément, et afficher la liste
	l = removeFirstNode(l);
	showList(l); NL();


	// continuer à supprimer jusqu'à ce qu'il n'y ait plus aucune maille
	l = removeFirstNode(l);
	showList(l); NL();

	l = removeFirstNode(l);
	showList(l); NL();

	l = removeFirstNode(l);
	showList(l); NL();

	// que se passe-t-il ? 
	l = removeFirstNode(l); // protégé par assert

	// test des fonctions récursives
	l = addNode(genElt(), l); 
	l = addNode(genElt(), l); 
	l = addNode(genElt(), l); 
	l = addNode(genElt(), l); 

	showList_rec(l);  NL();
	showList_inv_rec(l);  NL();
	freeList_rec(l);

	return 0;
}







