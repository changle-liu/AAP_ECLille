#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "test_utils.h"
#include "../include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;
T_data fusionSort(T_data d, int n);
//void fusionner(T_elt t [], int d, int m, int f); 
void fusionner(int *l, int l_size, int *r, int r_size);
void mergeSort(int a[], int n);
//void fusionsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

T_data fusionSort(T_data d, int n) {
	T_elt * A = d.pElt; // Le tableau à trier
	mergeSort(A,n);
	return genData(0, A);
/*
	int Milieu = n/2;
	
	if(n>1){
		T_elt * B = fusionSort(d, Milieu).pElt;
		T_elt * C = fusionSort(genData(0, &(A[Milieu+1])), (n-1)-(Milieu+1)+1).pElt;
		int i = 0;
		for(i=0;i<Milieu;i++) A[i] = B[i];
		for(i=Milieu;i<n;i++) A[i] = C[i-Milieu];
		fusionner(A, 0, Milieu, n-1);
	}
	return genData(0, A);
*/
}

/*
void fusionner(T_elt t [], int d, int m, int f) {
	T_elt aux[f - d + 1]; // !! Allocation dynamique sur la pile (standard C99) 
	int i, j, k;

	memcpy(aux, &t[d], (f - d + 1) * sizeof(T_elt));	// Copie des données à fusionner
	stats.nbOperations += (f - d + 1);

	i = 0; j = m - d + 1; k = 0;
	while (i <= m - d && j <= f - d) {
		stats.nbComparisons ++;
		if (aux[i] <= aux[j]) 	{
			t[d + k++] = aux[i++];	// aux[i] est plus petit : on le place dans t 
		}
		else {
	 		t[d + k++] = aux[j++];	// aux[j] est plus petit : on le place dans t 
		}
	}
	for (; i <= m - d; t[d + k++] = aux[i++]) stats.nbOperations ++; // le reste du tableau gauche
	for (; j <= f - d; t[d + k++] = aux[j++]) stats.nbOperations ++; // le reste du tableau droit
}
*/

void fusionner(int *l, int l_size, int *r, int r_size){
	int i, j, k, temp[l_size+r_size];
	i = j = k = 0;
	while (i<l_size && j<r_size){
		stats.nbComparisons ++;
		if (l[i]<r[j]){
			temp[k++] = l[i++];
			stats.nbOperations ++;
		}
		else{
			temp[k++] = r[j++];
			stats.nbOperations ++;
		}
	}
	while (i<l_size){
		temp[k++] = l[i++];
		stats.nbOperations ++;
	}
	while (j<r_size){
		temp[k++] = r[j++];
		stats.nbOperations ++;
	}
 
	for (i = 0; i<l_size + r_size; i++){
		l[i] = temp[i];
	}
}
 

void mergeSort(int a[], int n)
{
	// left start point
	int *l = a;
	// right start point
	int *r = a + n / 2;
	// left size
	int l_size = n / 2;
	// right size
	int r_size = n - l_size;
 
	if (n>1)	// recursion condition
	{
		mergeSort(l, l_size);	//sort left group
		mergeSort(r, r_size);	//sort right group
		fusionner(l, l_size, r, r_size);	//merge left and right group together
	}
}

/*

Produire une fonction fusionsort pouvant être utilisée comme la fonction standard qsort et respectant le prototype suivant : 
void fusionsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

*/
/*
void fusionsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)){
	assert(base != NULL && size >= 1 && compar != NULL);
	mergesort(base, nmemb, size, compar);
	return genData(0, A);
}


void mergesort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
	// left start point
	void *l = base;
	// right start point
	void *r = abase + nmemb / 2;
	// left size
	size_t l_size = nmemb / 2;
	// right size
	size_t r_size = nmemb - l_size;
 
	if (n>1)	// recursion condition
	{
		mergeSort(l, l_size, size, compar);	//sort left group
		mergeSort(r, r_size, size, compar);	//sort right group
		fusionner(l, l_size, r, r_size, size, compar);	//merge left and right group together
	}
}


void fusionner(void *l, size_t l_size, void *r, size_t r_size, int (*compar)(const void *, const void *)){
	size_t i, j, k, temp[l_size+r_size];
	i = j = k = 0;
	while (i<l_size && j<r_size){
		stats.nbComparisons ++;
		if (compar(l[i],r[j]) < 0){
			temp[k++] = l[i++];
		}
		else{
			temp[k++] = r[j++];
		}
	}
	while (i<l_size){
		temp[k++] = l[i++];
	}
	while (j<r_size){
		temp[k++] = r[j++];
	}
 
	for (i = 0; i<l_size + r_size; i++){
		l[i] = temp[i];
	}
}
*/












