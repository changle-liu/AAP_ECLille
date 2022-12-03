#include <assert.h> // assert

//#define DEBUG
#include "../include/check.h" 

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

#include "stack_cld.h" // type et protypes liés à T_stack

// typedef T_node * T_stack;

#ifdef IMPLEMENTATION_DYNAMIC_LINKED

T_stack newStack() {
	// Créer une pile vide

	return NULL; 
}

void freeStack (T_stack *p) {
	// Libérer la mémoire associée à une pile 

	freeList(*p);
}

void push(T_elt e, T_stack *p) {
	// Opération consistant à empiler un élément e
	// sur la pile modifiant ainsi son état

	*p = addNode(e, *p);
}

void showStack (const T_stack * p) {
	// Afficher la pile
	// On affiche en commençant par le sommet de la pile 

	showList(*p);
}

T_elt pop(T_stack *p) {
	// Cette opération extrait de la pile, l’élément au sommet, 
	// modifiant ainsi son état

	T_elt e = getFirstElt(*p);
	(*p) = removeFirstNode(*p); 
	return e; 
}

T_elt top(const T_stack *p) {
	// Cette opération permet d’accéder à l’élément en sommet de pile

	return getFirstElt(*p); 
}

void emptyStack (T_stack *p) {
	// Vider la pile 

	freeStack (p);
	*p=NULL;
}

int isEmpty (const T_stack * p) {
	// Cette opération permet de tester si la pile est vide

	return ((*p)==NULL); 
}

#endif


