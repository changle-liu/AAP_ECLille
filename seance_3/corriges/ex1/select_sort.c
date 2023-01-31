#include "test_utils.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

T_data selectSort(T_data d, int n) {
	int i,j; 
	int imin;
	T_elt aux;
	T_elt * A = d.pElt; // Le tableau à trier 

	for (i = 0; i < n-1; i++) {
		imin = i;
		for (j = i+1; j < n; j++) {
			stats.nbComparisons ++;
			if (A[j] < A[imin])
				imin = j;
		}
		if (i != imin){
			aux = A[imin];	stats.nbOperations ++;
			A[imin] = A[i];	stats.nbOperations ++;
			A[i] = aux;	stats.nbOperations ++;
		}
	}

	return genData(0,A); 
}



