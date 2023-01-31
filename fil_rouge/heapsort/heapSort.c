#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h> 
// ceil, floor : #include <math.h>


#include "../include/traces.h" 
#include "../include/check.h" 

#include "elt.h"
#include "test_utils.h"
// #include "heapSort.h"

#define HEAP_ALLOCATION_OFFSET 5

typedef struct {
	unsigned int nbElt;
	unsigned int nbMaxElt;
	T_elt * tree;	
} T_heap;

#define iPARENT(i) 			(i-1)/2
#define iLCHILD(i) 			(2*i)+1
#define iRCHILD(i) 			(2*i)+2
#define iLASTINTERNAL(n)	n/2 -1
#define isINTERNAL(i,n) 	(2*i<(n-1))
#define isLEAF(i,n) 			(2*i>=(n-1))
#define isINTREE(i,n)		(i<n)
#define isROOT(i)				(i==0)
#define nbINTERNALS(n) 		n/2
#define nbLEAVES(n) 			ceil((double)n/2)
#define VALP(pHeap, i)		pHeap->tree[i]		
#define VAL(heap, i)			heap.tree[i]		

T_heap * newHeap(unsigned int nbMaxElt);
void freeHeap(T_heap *p); 
T_heap * initHeap(T_elt t[], int n) ;
void showHeap(T_heap *p);
void showHeap_rec(T_heap *p, int root, int indent); 

void swap(T_heap *p, int i, int j);
void siftUp(T_heap *p, int k);
void addElt(T_heap *p, T_elt e);
void buildHeapV1(T_heap * p);

void siftDown(T_heap *p, int k);
T_elt getMax(const T_heap *p);
T_elt removeMax(T_heap *p);
void buildHeapV2(T_heap * p); 

void heapSortV1(T_heap *p);
void heapSortV2(T_heap *p);
T_data heapSortV3(T_data d, int n);

void  Swap (int array[], int i, int j);
void heap_ajust(int arr[], int start, int end);
void heap_sort(int arr[], int len);

// Une constante symbolique permet de sélectionner l’ordre de tri est defini dans elt.h
 


T_heap * newHeap(unsigned int nbMaxElt){

	T_heap * pAux;
	CHECK_IF(pAux = malloc(sizeof(T_heap)), NULL, "erreur malloc");
	CHECK_IF(pAux->tree = malloc(nbMaxElt * sizeof(T_elt)), NULL, "erreur malloc");
	pAux->nbElt = 0; 
	pAux->nbMaxElt = nbMaxElt; 
	
	return pAux; 

}

void freeHeap(T_heap *p) {
	assert(p!=NULL);
	free(p->tree);
	free(p);
}


T_heap * initHeap(T_elt t[], int n) {
	T_heap *pAux = newHeap(n + HEAP_ALLOCATION_OFFSET); 
	memcpy(pAux->tree, t, n * sizeof(T_elt)); 
	pAux->nbMaxElt = n + HEAP_ALLOCATION_OFFSET;
	pAux->nbElt = n; 
	return pAux; 
}

void showHeap(T_heap *p) {
	assert(p!=NULL);
	printf("Affichage du tas (nbElt : %d)\n",p->nbElt);
	showHeap_rec(p,0,0); 
}

void showHeap_rec(T_heap *p, int root, int indent) {
	// affiche récursivement en mode pseudo graphique 
	// ordre de récurrence  : taille du sous-arbre 
	int i; 
	assert(p!=NULL);
	if (! isINTREE(root,p->nbElt)) return;  
	
	showHeap_rec(p, iRCHILD(root), indent+1);
	for(i=0;i<indent;i++) {
		printf("\t"); 
	}
	printf("%s(i:%d)\n",toString(VALP(p,root)), root);
	showHeap_rec(p, iLCHILD(root), indent+1);
}

void swap(T_heap *p, int i, int j) {
	T_elt aux; 
	assert(p!=NULL);
	aux = p->tree[i]; 
	p->tree[i] = p->tree[j];
	p->tree[j] = aux; 
	stats.nbOperations++;
}


void siftUp(T_heap *p, int k) {
	assert(p!=NULL);
	while ( !isROOT(k) && (eltCmp(VALP(p,k),VALP(p,iPARENT(k))) > 0 ) ) {
		stats.nbComparisons++;
		swap(p,k,iPARENT(k)); 
		k = iPARENT(k); 
	}
}

void addElt(T_heap *p, T_elt e) {
	assert(p!=NULL);
	p->tree[p->nbElt] = e; 
	p->nbElt++; 
	siftUp(p,p->nbElt-1);
}

void buildHeapV1(T_heap * p){
	int k; 
	assert(p!=NULL);
	for(k=1;k<p->nbElt; k++) {
		siftUp(p, k);
	}
}

void siftDown(T_heap *p, int k) {

	int n; 
	assert(p!=NULL);
	n = p->nbElt; 
	int i; 
	if (! isINTREE(k,n)) return; 
	 
	while ( ! isLEAF(k,n) ) {
		stats.nbComparisons++;
		if (isINTREE(iRCHILD(k),n) && (eltCmp(VALP(p,iRCHILD(k)),VALP(p,iLCHILD(k))) > 0)  ) i = iRCHILD(k); 
		else i = iLCHILD(k); 
		stats.nbComparisons++;
		if (eltCmp(VALP(p,k),VALP(p,i)) < 0) {
			swap(p, k,i);
			k = i; 
		} else break;  
		
	}
}


T_elt getMax(const T_heap *p){
	assert(p!=NULL);
	return p->tree[0];
}


T_elt removeMax(T_heap *p) {
	T_elt aux; 
	assert(p!=NULL);
	aux = p->tree[0]; 
	swap(p,0,p->nbElt-1);
	p->nbElt--; 
	siftDown(p,0);
	return aux; 

}





void buildHeapV2(T_heap * p){
	int k; 
	int n; 
	assert(p!=NULL);
	n =p->nbElt; 
	for(k=iLASTINTERNAL(n); k>=0; k--) {
		siftDown(p,k);
	}
}


void heapSortV1(T_heap *p) {
	assert(p!=NULL);
	buildHeapV1(p);
	while(p->nbElt>1) {
		swap(p,0,p->nbElt-1); 
		p->nbElt--; 
		siftDown(p,0);
	}
}

void heapSortV2(T_heap *p) {
	assert(p!=NULL);
	buildHeapV2(p);
	while(p->nbElt>1) {
		removeMax(p); 
	}
}

T_data heapSortV3(T_data d, int n){
	/*
	T_heap * maximier = NULL;
	maximier = initHeap(d.pElt, n);
	heapSortV2(maximier);
	maximier->nbElt = n; 
	//showHeap(maximier);
	T_heap * maxi = initHeap(maximier->tree, n);
	T_elt * A;
	CHECK_IF(A = malloc(n * sizeof(T_elt)), NULL, "erreur malloc");
	memcpy(A, maxi->tree, n * sizeof(T_elt));
	*/
	T_elt * A = d.pElt; // Le tableau à trier
	heap_sort(A, n);
	
	return genData(0, A);
}

void  Swap (int array[], int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
 



void heap_ajust(T_elt * arr, int start, int end) {  
 
    int dad = start;  
    int son = iLCHILD(dad);  
    while (son <= end) {  
        if (son + 1 <= end && eltCmp(arr[son], arr[son + 1]) < 0){ 
            son++;  
            stats.nbComparisons++;
            }
        stats.nbComparisons++;
        if (eltCmp(arr[dad], arr[son]) > 0)  
            return;  
        else { 
            Swap(arr,dad,son);  stats.nbOperations++;
            dad = son;  
            son = iLCHILD(dad);  
        }  
    }  
}  

 

void heap_sort(T_elt * arr, int len) {  
    int i;  
    for (i = len / 2 - 1; i >= 0; i--){
        heap_ajust(arr, i, len - 1);  
 
    }       
    for (i = len - 1; i > 0; --i) {  
        
        Swap(arr,0,i); stats.nbOperations++;
        heap_ajust(arr, 0, i-1);  
    }  
}  











