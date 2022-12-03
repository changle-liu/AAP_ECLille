#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt
#include "elt.h"	// T_elt 


int main(int argc, char ** argv) {
	T_elt e1,e2;  

	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	// Développer les fichiers elt.h et elt.c
	/////////////////////////////////////////////////////////////////////////

	// Générer un elt
	e1 = genElt();
	e2 = genElt();

	// Afficher l'élément
	printf("Elt e1 : %s \n", toString(e1));
	printf("Elt e2 : %s \n", toString(e2));

	printf("Elts extraits : %s et %s \n", toString(e1),toString(e2) );
	// Est-ce que cette manière de faire fonctionne pour tous les types ? 
	// NON !!! Pourquoi ??? Cf. implémentation des fonctions toString()

	return 0;
}







