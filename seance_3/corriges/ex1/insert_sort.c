#include "test_utils.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

T_data insertSort(T_data d, int n) {
	int i,j; 
	T_elt aux;
	T_elt * A = d.pElt; // Le tableau à trier  

	i = 1;
	while (i < n) {
		aux = A[i] ; stats.nbOperations ++;
		j = i - 1;
		while (j >= 0 && A[j] > aux) {
			stats.nbComparisons ++;
			A[j+1] = A[j] ;	stats.nbOperations ++;
			j-- ;
		}
		if (j>=0) 
			stats.nbComparisons ++;
		A[j+1] = aux ; stats.nbOperations ++;
		i++;
	}

	return genData(0,A);
}
