#include <stdio.h>
#include <assert.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

// Dans cette implémentation, une pile contient au maximum 10 éléments
#define STACK_NBMAX_ELT 10

#define IMPLEMENTATION_STATIC_CONTIGUOUS
//#define IMPLEMENTATION_DYNAMIC_CONTIGUOUS
//#define IMPLEMENTATION_DYNAMIC_LINKED

// Dans cette implémentation, les T_elt sont des entiers
typedef int T_elt; 

#ifdef IMPLEMENTATION_STATIC_CONTIGUOUS
typedef struct {
	int sp; 
	T_elt data[STACK_NBMAX_ELT];
} T_stack;
#endif 

void showStack (const T_stack * p);
void emptyStack (T_stack *p);
T_stack newStack(void);
T_stack exampleStack(int n); 


int main(int argc, char ** argv) {
	T_stack s = newStack(); 

	CLRSCR();
	WHOAMI(); 

	/////////////////////////////////////////////////////////////////////////
	// Développer les fonctions 
	// void showStack (const T_stack * p_s)
	// void emptyStack (T_stack *p_s);
	// T_stack newStack(void);
	// T_stack exampleStack(int n); 
	// Développer un programme de test permettant d’utiliser ces fonctions
	/////////////////////////////////////////////////////////////////////////

	// Développer un programme de test permettant d’utiliser ces fonctions

	// Afficher une pile vide
	showStack(&s);

	// Initialiser une pile d'exemple
	s = exampleStack(3);

	// Afficher la pile
	showStack(&s);

	NL();

	// Vider la pile
	emptyStack(&s);

 	// Afficher la pile 
	showStack(&s);

	return 0;
}

#ifdef IMPLEMENTATION_STATIC_CONTIGUOUS
void showStack (const T_stack * p) {	
	// Afficher la pile
	// On affiche en commençant par le sommet de la pile 
	// Hypothèse : les T_elt sont des int 
	
	int i; 

	if (p->sp ==0) {
		printf("Pile vide !\n"); // pile vide !
		return; 
	}
 
	printf("Sp = %d\n",p->sp);
	for(i=p->sp-1;i>=0; i--) {
		printf("P[%d]= %d\n",i, p->data[i]);
	}
}

void emptyStack (T_stack *p) {
	// Vider la pile 
	p->sp = 0; 
}

T_stack newStack(void) {
	// Créer une pile vide
	T_stack s = {0}; 
	return s; 
}

T_stack exampleStack(int n) {
	// Renvoie une nouvelle pile d'exemple, contenant n éléments
	int i; 
	T_stack s = newStack(); 

	// On peut tronquer le nombre d'éléments 
	// Ou utiliser de la programmation défensive avec assert()
	if (n>STACK_NBMAX_ELT) n = STACK_NBMAX_ELT; 

	s.sp = n; 
	for(i=0;i<n;i++) {
		s.data[i] =i; 
	}
	return s; 
}
#endif 






