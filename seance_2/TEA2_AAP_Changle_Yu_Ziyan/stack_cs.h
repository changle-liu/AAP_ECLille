#include "elt.h"
#define STACK_NBMAX_ELT 10

#ifdef IMPLEMENTATION_STATIC_CONTIGUOUS
typedef struct {
	int sp; 
	T_elt data[STACK_NBMAX_ELT];
} T_stack;

void showStack (const T_stack * p);
void emptyStack (T_stack *p);
T_stack newStack(void);
//T_stack exampleStack(int n);
T_elt pop(T_stack *p);
T_elt top(const T_stack *p);
void push(T_elt e, T_stack *p);
int isEmpty (const T_stack * p);
#endif 


