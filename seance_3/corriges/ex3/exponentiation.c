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


T_data PuissanceRapide(T_data d, int n){
	T_elt Result = 1;
	T_elt x = d.elt;

	while (n > 0) {
		if ((n % 2) == 1){
			Result *= x; stats.nbOperations ++;
			n--;
		}
		x = x*x;	stats.nbOperations ++;
		n = n>>1;	// équivalent à n=n/2
	}
	return genData(Result, NULL);
}

/*
T(n) = 1 + T(n/2) meilleur cas 
T(n) = 2 + T(n/2) pire cas 
= 2 + 2 + T(n/4)
= 2 + 2 + 2 + T(n/8) = 3 * 2 + T(n/2^3) 
= i * 2 + T(n/2^i)
Quand i est tel que n = 2^i ⇔ i = log2(n) 
T(n) =  log2(n) *  2 + T(1) 
*/

T_data PuissanceRapide_rec(T_data d, int n){
	T_elt x = d.elt;
	T_data r;

	// ordre de récurrence : n 
	// cas de base : 
	if (n == 0) return genData(1, NULL);
	if (n == 1) return genData(x, NULL);

	// cas général :
	if (n%2) {
		// impair
		stats.nbOperations ++;
		r = PuissanceRapide_rec(genData(x*x, NULL), (n-1)/2);
		stats.nbOperations ++;
		return genData(x*r.elt, NULL);
		
	} else {
		// pair 
		stats.nbOperations ++;
		return  PuissanceRapide_rec(genData(x*x, NULL), n/2);
	}
	
}


