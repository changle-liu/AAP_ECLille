#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h> 
#include "../include/traces.h" 
#include "../include/check.h" 

#define MAXLEN 1000
#define MAX_ASCII 128
#define HEAP_ALLOCATION_OFFSET 5

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
#define VALP(pHeap, i)		pHeap->data[pHeap->tree[i]]		
#define VAL(heap, i)		heap.data[heap.tree[i]]
#define CHAR_P(pHeap, i)	pHeap->tree[i]
#define CHAR_C(heap, i)		heap.tree[i]

typedef struct {
	unsigned int nbElt;
	unsigned int nbMaxElt;
	int * tree; // Les ascii
	int data[256];	// Les occurrences
} T_heap;

typedef struct {
	int longueur; // Longueur du code
	int code[128];	// Code
} Code;

void addElt(T_heap *p, int e);
char * getDocu();
T_heap * analyserDocument(char * Docu);
void siftUp(T_heap *p, int k);
void siftDown(T_heap *p, int k);
void swap(T_heap *p, int i, int j);
void showHeap(T_heap *p);
void showHeap_rec(T_heap *p, int root, int indent);
void transformerEnMinimierV2(T_heap *p);
void initHuffmanTree(int * Ht);
void AjouterNoeud(int * Ht, int Ni, int C1, int C2);
T_heap * insererMI(T_heap * Mi, int Ni, int c);
T_heap * huffman(char * Docu, int * Ht);
void EncodeHt(Code p[], int * Ht);
void Affiche(T_heap * tree, Code p[]);
void AfficheCode(T_heap * tree, Code p[], char * Docu);

void addElt(T_heap *p, int e) {
	assert(p!=NULL);
	p->tree[p->nbElt] = e; 
	p->nbElt++; 
	siftUp(p,p->nbElt-1);
}

void siftUp(T_heap *p, int k) {
	assert(p!=NULL);
	while ( !isROOT(k) && (VALP(p,k) - VALP(p,iPARENT(k))) < 0 ) {
		swap(p,k,iPARENT(k)); 
		k = iPARENT(k); 
	}
}

void siftDown(T_heap *p, int k) {

	int n; 
	assert(p!=NULL);
	n = p->nbElt; 
	int i; 
	if (! isINTREE(k,n)) return; 
	
	while ( ! isLEAF(k,n) ) {
		if (isINTREE(iRCHILD(k),n) && (VALP(p,iRCHILD(k)) - VALP(p,iLCHILD(k)) < 0)  ) i = iRCHILD(k); 
		else i = iLCHILD(k); 
		
		if (VALP(p,k) - VALP(p,i) > 0) {
			swap(p, k,i);
			k = i; 
		} else break; 
		
	}
	
}

void swap(T_heap *p, int i, int j) {
	int aux; 
	assert(p!=NULL);
	aux = p->tree[i]; 
	p->tree[i] = p->tree[j];
	p->tree[j] = aux; 
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
	printf("%d(%d)(i:%d)\n",CHAR_P(p,root), VALP(p,root), root);
	showHeap_rec(p, iLCHILD(root), indent+1);
}


char * getDocu(){
	char Docu[MAXLEN];
	char c;
	int i = 0;
	while ( ( c = getchar() ) != EOF) {
		Docu[i++] = c;
	}
	Docu[i] = '\0';
	char *docu;
	strcpy(docu,Docu);
	return docu;
}

T_heap * analyserDocument(char * Docu){
	T_heap *Mi;
	CHECK_IF(Mi = malloc(sizeof(T_heap)), NULL, "erreur malloc");
	CHECK_IF(Mi->tree = malloc((MAX_ASCII+HEAP_ALLOCATION_OFFSET) * sizeof(int)), NULL, "erreur malloc");
	Mi->nbElt = 0; 
	Mi->nbMaxElt = MAX_ASCII + HEAP_ALLOCATION_OFFSET;
	int i;
	for(i=0;i<256;i++){
		(Mi->data)[i] = 0;
	}
	int c;
	for(i=0;i<strlen(Docu);i++){
		c = (int)Docu[i];
		(Mi->data)[c] ++;
	}
	for(i=0;i<=127;i++){
		if( ((Mi->data)[i]) != 0) addElt(Mi, i);
	}
	return Mi;
}

void initHuffmanTree(int * Ht){
	for(int i=0;i<256;i++){
		Ht[i] = -256;
	}
}

void transformerEnMinimierV2(T_heap *p){
	int k; 
	int n; 
	assert(p!=NULL);
	n =p->nbElt; 
	for(k=iLASTINTERNAL(n); k>=0; k--) {
		siftDown(p,k);
	}
}

int extraireMin(T_heap *p){
	int aux; 
	assert(p!=NULL);
	aux = p->tree[0]; 
	swap(p,0,p->nbElt-1);
	p->nbElt--; 
	siftDown(p,0);
	return aux;
}

void AjouterNoeud(int * Ht, int Ni, int C1, int C2){
	*(Ht+C1) = -Ni;
	*(Ht+C2) = Ni;
}

T_heap * insererMI(T_heap * Mi, int Ni, int c){
	(Mi->data)[Ni] = c;
	addElt(Mi, Ni);
	return Mi;
}

T_heap * huffman(char * Docu, int * Ht){
	T_heap * Mi = NULL;
	Mi = analyserDocument(Docu);
	initHuffmanTree(Ht);
	transformerEnMinimierV2(Mi);
	int i, C1, C2, Ni;
	for(i=0; i<n-1; i++){
		C1 = extraireMin(Mi);
		C2 = extraireMin(Mi);
		Ni = 128+i;
		AjouterNoeud(Ht, Ni, C1, C2);
		Mi = insererMI(Mi, Ni, VALP(C1) + VALP(C2));
	}
	return Mi;
}

void EncodeHt(Code p[], int * Ht){
	int i,j;
	for(i=0; i<128; i++){
		if(Ht[i] == -256) break;
		
		for(j=0;j<128;j++){
			*(p+i).code[j] = -1;
			*(p+i).longueur = 0;
		}

		while(Ht[i] != -256){
			if(Ht[i] < 0){
				*(p+i).code[ *(p+i).longueur ] = 0;
				(*(p+i).longueur) ++;
				i = Ht[i];
			}else{
				*(p+i).code[ *(p+i).longueur ] = 1;
				(*(p+i).longueur) ++;
				i = Ht[i];
			}
			
		}
	}
}

void Affiche(T_heap * tree, Code p[]){
	printf("car : occ | long |     bits     \n");
	printf("----+-----+------+--------------\n");
	int i, j;
	for(i=0;i<128;i++){
		if( *(p+i).code[ (*(p+i).longueur) ] != 0 ){
			printf("'%c' : %3d | %4d | ", (char)i, (tree->data)[i], *(p+i).longueur);
			for(j=0; j<*(p+i).longueur, j++){
				printf("%d", *(p+i).code[ *(p+i).longueur -j ]);
			}
			for(; j<12; j++){
				printf(" ");
			}
			printf("\n");
		}
	}
}

void AfficheCode(T_heap * tree, Code p[], char * Docu){
	FILE *f;
	f = fopen("CodeHt.txt", "w");
	int i = 0;
	int j;
	int LongueurHt = 0;
	int LongueurBi = 0;
	while(*(Docu+i) != '\0'){
		for(j=0; j<*(p+i).longueur, j++){
			fprintf(f, "%d", *(p+i).code[ *(p+i).longueur -j ]);
			LongueurCode ++;
		}
		LongueurBi += 8;
	}
	fclose(f);
	printf("Longueur du code binaire : %d bits\n", LongueurBi);
	printf("Longueur du code de huffman : %d bits\n", LongueurCode);
	printf("Ratio de compression : %.2f\n",(float)LongueurCode/LongueurCode*100);
}

void main(){
	
	char * Document;
	Document = getDocu()
	Code HtCode[128];
	int Ht[256];
	T_heap * tree = NULL;
	tree = huffman(Document, Ht);
	Encode(HtCode, Ht);
	Affiche(tree, HtCode);
	AfficheCode(tree, HtCode, Document);
	
}














