#include "elt.h"

/////////////////////////////////////////////////////////////////////////
// CHOISIR ICI L'IMPLEMENTATION DES PILES 
/////////////////////////////////////////////////////////////////////////

//#define IMPLEMENTATION_STATIC_CONTIGUOUS
#define IMPLEMENTATION_DYNAMIC_CONTIGUOUS
//#define IMPLEMENTATION_DYNAMIC_LINKED

#ifdef IMPLEMENTATION_DYNAMIC_CONTIGUOUS
typedef struct {
	int sp; 
	int nbMaxElt;
	T_elt * data;
} T_stack;

void showStack (const T_stack * p);
void freeStack (T_stack *p);
void emptyStack (T_stack *p);
T_stack newStack(int size);
T_stack exampleStack(int n);
T_elt pop(T_stack *p);
T_elt top(const T_stack *p);
void push(T_elt e, T_stack *p);
int isEmpty (const T_stack * p);
#endif 


