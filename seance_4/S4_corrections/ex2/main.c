#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h> 
// ceil, floor : #include <math.h>


#include "../include/traces.h" 
#include "../include/check.h" 

#include "elt.h"

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
 

int main(void) {

	T_elt e1; 
	T_heap * maximier = NULL; 
	
	int ex1[] = { 3, 6, 8, 1, 10, 2, 9, 4};   // 10
	int ex2[] = { 18, 16, 11, 10, 15, 6, 1, 7, 4, 9, 3}; // 11
	int ex3[] = { 3, 1, 8, 5, 9, 6, 11, 7, 4, 12, 0 }; // 10
	int ex4[] = { 7, 15, 1, 9, 15, 10, 11, 4, 18, 6 }; //10 
	

	// allocation et l'initialisation d'un tas à partir d'un tableau 
	maximier = initHeap(ex1, 8);
	showHeap(maximier);
	buildHeapV1(maximier); 
	showHeap(maximier);
	/*
	// ajouter elt, remonter
	addElt(maximier, 16);
	showHeap(maximier);
	
	// création d'un maximier V1
	free(maximier);
	maximier = initHeap(ex4, 10);
	showHeap(maximier);
	buildHeapV1(maximier); 
	showHeap(maximier);
	
	// getMax
	free(maximier);
	maximier = initHeap(ex2, 11);
	showHeap(maximier);
	e1 = getMax(maximier);
	printf("max : %s\n", toString(e1));
	
	// suppression element, redescendre
	e1 = removeMax(maximier);
	printf("max : %s\n", toString(e1));
	showHeap(maximier);
	
	// création d'un maximier V2 
	free(maximier);
	maximier = initHeap(ex3, 10);
	showHeap(maximier);
	buildHeapV2(maximier);
	showHeap(maximier);
	*/
}


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
}


void siftUp(T_heap *p, int k) {
	assert(p!=NULL);
	while ( !isROOT(k) && (eltCmp(VALP(p,k),VALP(p,iPARENT(k))) < 0 ) ) {
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
		if (isINTREE(iRCHILD(k),n) && (eltCmp(VALP(p,iRCHILD(k)),VALP(p,iLCHILD(k))) > 0)  ) i = iRCHILD(k); 
		else i = iLCHILD(k); 
		
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













