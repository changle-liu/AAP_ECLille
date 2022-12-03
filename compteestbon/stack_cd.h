#include "elt.h"


#ifdef IMPLEMENTATION_DYNAMIC_CONTIGUOUS
typedef struct {
	int sp; 
	int nbMaxElt;
	T_elt * data;
} T_stack;

void showStack (const T_stack * p);
void freeStack (T_stack *p);
void emptyStack (T_stack *p);
T_stack newStack();
T_elt pop(T_stack *p);
T_elt top(const T_stack *p);
void push(T_elt e, T_stack *p);
int isEmpty (const T_stack * p);
#endif 


