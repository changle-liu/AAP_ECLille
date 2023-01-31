#include <stdio.h>
#include "test_utils.h"
#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

T_data hanoi(T_data d, int n) {
	// data : 
	// n : nombre de disques à déplacer 
	// d.pElt[0] : num. tige départ 
	// d.pElt[1] : num. tige arrivée
	// d.pElt[2] : num. tige intermediaire
	// On utilisera un tableau trié 
	// Contiendra 0,1,2 : passer de la tige 0 à la tige 1

	// si d.elt vaut 1, il faut afficher des messages
	// si d.elt = 0 : ne rien afficher 

	// Attention : on ne peut réutiliser le même tableau 
	// pour passer les paramètres QUE si on sauvegarde les paramètres
	// reçus dans des variables locales à chaque fonction 
	// sitôt qu'on les reçoit 

	T_elt origine = d.pElt[0]; 
	T_elt destination = d.pElt[1]; 
	T_elt intermediaire = d.pElt[2]; 

	// ordre de la récurrence : n 
	
	if (n==1) {	// cas de base
		if (d.elt) printf("Tige %d => %d\n", origine+1,destination+1);
		stats.nbOperations ++; 
	} else { // cas général
		d.pElt[0] = origine; // départ  
		d.pElt[1] = intermediaire ; // arrivée 
		d.pElt[2] = destination; // intermediaire
		hanoi(d, n-1); // or->inter

		if (d.elt) printf("Tige %d => %d\n", origine+1,destination+1);
		stats.nbOperations ++;
		// or->dest

		d.pElt[0] = intermediaire; // départ  
		d.pElt[1] = destination; // arrivée 
		d.pElt[2] = origine; // intermediaire
		hanoi(d, n-1); // inter-> dest
	}
	return genData(0,NULL);
}
