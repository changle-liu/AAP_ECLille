#include "test_utils.h"
#include "../include/traces.h"
#include <stdio.h>

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

T_data Puissance(T_data d , int n) {
	T_elt Result;
	T_elt x = d.elt; 

	if (n == 0) return genData(1, NULL);
		for (Result = x; n > 1; n--) {
			Result *= x;
			stats.nbOperations ++;
		}

	return genData(Result, NULL);
}

// Quelle complexité ? 
// T(n) = 1 + T(n-1)
// T(n) = 1 + 1 + T(n-2) = 1+1+1+T(n-3)=3+T(n-3)
// T(n) = n-1 + T(1) ⇒ T(n) = Θ( n )

// Quel problème se présente lorsque l’on calcule des puissances trop grandes avec la version récursive ?
// Trop d’appels récursifs : la pile d’exécution déborde

T_data Puissance_rec(T_data d , int n) {
	T_elt x = d.elt;
	T_data r; 

	// ordre de récurrence : n 
	// cas de base : 
	if (n == 0) return genData(1, NULL);
	if (n == 1) return genData(x, NULL);

	// cas général : 
	r = Puissance_rec(d , n-1) ; 
	stats.nbOperations ++;
	return genData(x * r.elt, NULL);
}


