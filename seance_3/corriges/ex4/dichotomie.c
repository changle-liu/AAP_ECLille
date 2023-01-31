#include "test_utils.h"
#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations++;
// stats.nbComparisons++;

int Comparaison(T_elt e1, T_elt e2) {
	stats.nbComparisons++; 
	return e1-e2; 
}


T_data RechercheDicho (T_data d, int n) {
	int Debut = 0, Fin = n - 1, Milieu;
	int Test;
	T_elt * A = d.pElt; // Le tableau à trier 
	T_elt e = d.elt; // L'élément recherché

	while (Debut <= Fin) {
		Milieu = (Debut + Fin) / 2;
		Test = Comparaison(e , A[Milieu]);
		if (Test == 0)
			return genData(0,&(A[Milieu])); // On renvoie l'adresse de l'elt trouvé 
		if (Test < 0)
			Fin = Milieu - 1;
		else
			Debut = Milieu + 1;
	}
	return genData(0,NULL);	/* e n’est pas dans T : on renvoie l'adresse NULL */
}


T_data RechercheDicho_rec (T_data d, int n) {
	// données : 
	// pElt : début du tableau, 
	// elt : elt cherché 
	// n : taille du tableau 

	int Milieu = (n-1)/2; 
	int Test; 
	T_elt * A = d.pElt; // Le tableau à trier 
	T_elt e = d.elt; // L'élément recherché

	// cas de base : taille ==0
	if (n==0) return genData(0,NULL);
	
	// ordre de récurrence : n 
	Test = Comparaison(e , A[Milieu]);
	if (Test == 0)
			return genData(0,&(A[Milieu])); 
	if (Test < 0) {
		// partie gauche du tableau : 0 à Milieu-1
		return RechercheDicho_rec (d, Milieu); 
	} else {
		// On change l'adresse de début du tableau : 
		// = adresse de Milieu+1
		// ainsi que sa taille :
		// = indice dernier - indice premier +1 
		return RechercheDicho_rec (genData(e,&(A[Milieu+1])), (n-1)-(Milieu+1)+1);	
	}
}







