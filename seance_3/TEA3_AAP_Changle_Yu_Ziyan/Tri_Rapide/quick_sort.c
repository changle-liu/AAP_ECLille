#include<stdio.h>
#include "test_utils.h"
#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

void Swap(int *, int *);  
void QuickSort(int *, int, int);  

/*
void quicksort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
void QSort(void *base, size_t low, size_t high, size_t size, int (*compar)(const void *, const void *);

*/

/*
int Partitionnement (T_elt t [], int g, int d); 

int comparer(T_elt e1, T_elt e2) {
	return e1-e2;
}

void echanger(T_elt t[], int i1, int i2) {
	T_elt s = t[i1];
	t[i1] = t[i2];
	t[i2] = s;
}
*/

//void Tri_rapide( T_elt t[], int debut, int fin) {

T_data quickSort(T_data d, int n) {
	
	T_elt * A = d.pElt;
	QuickSort(A, 0, n);
	
/*
	if(n = 1) return genData(0, A);
	int pivot = Partitionnement(A, 0, n-1);
	* (A+pivot+1) = *(quickSort(genData(0, &(A[pivot+1])), n-pivot-1).pElt);
	* A = *(quickSort(d, pivot+1).pElt);
*/
	
	return genData(0 ,A);

	
}

/*
int Partitionnement (T_elt t [], int g, int d){ 
	int pg=g , pd=d-1; // On utilise g et d comme « pointeurs » qui se déplacent
	// On choisit le dernier élément comme pivot

	while (pg<pd) {
		// On déplace pg et pd jusqu’à trouver des valeurs incohérentes % pivot

		while ( (pg<pd) &&  (comparer(t[pg],t[d]) <=0) ) {pg++ ;	stats.nbComparisons ++;}
		while ( (pg<pd) && (comparer(t[pd],t[d])>0) ) {pd-- ; stats.nbComparisons ++;}

		// Comment compter correctement ? On utilise une fonction de comparaison...
		if (pg < pd) {
			echanger(t,pg,pd); 
			stats.nbOperations ++;
			pg++ ; pd-- ; 
		}
	}
	if (comparer(t[pg],t[d]) <= 0) pg++ ;  
		stats.nbOperations ++;
		echanger(t, pg, d) ;

	return pg ; 
}
*/

void Swap(int *p, int *q)
{
    int buf;
    buf = *p;
    *p = *q;
    *q = buf;
    return;
}
void QuickSort(int *a, int low, int high)
{
	int i = low;
	int j = high;
	int key = a[low];
	if (low >= high){
		return ;
	}
	while (low < high){
		while (low < high && key <= a[high]){
			--high; 
			stats.nbComparisons ++;
		}
		if (key > a[high]){
			stats.nbOperations ++;
			Swap(&a[low], &a[high]);
			++low;
		}
		while (low < high && key >= a[low]){
			stats.nbComparisons ++;
			++low;  
		}
		if (key < a[low]){
			stats.nbOperations ++;
			Swap(&a[low], &a[high]);
			--high;
		}
	}
	QuickSort(a, i, low-1);  
	QuickSort(a, low+1, j);  
}


/*
void quicksort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)){
	void *l = base;
	QSort(base, 0, nmemb, size, compar);
}

void QSort(void *base, size_t low, size_t high, size_t size, int (*compar)(const void *, const void *){
	size_t i = low;
	size_t j = high;
	size_t key = base[low];
	if (low >= high){
		return ;
	}
	while (low < high){
		while (low < high && compar(key, a[high]) <= 0){
			--high; 
		}
		if (compar(key, a[high]) > 0){
			QSwap(&a[low], &a[high]);
			++low;
		}
		while (low < high && compar(key, a[low]) >= 0){
			++low;  
		}
		if (compar(key, a[low]) > 0){
			QSwap(&a[low], &a[high]);
			--high;
		}
	}
	QSort(base, i, low-1, size, compar);  
	QSort(base, low+1, j, size, compar);
}

void QSwap(void *p, void *q)
{
    void buf;
    buf = *p;
    *p = *q;
    *q = buf;
    return;
}
*/




