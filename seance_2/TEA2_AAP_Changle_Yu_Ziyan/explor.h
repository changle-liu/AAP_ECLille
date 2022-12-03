#include "rpn.h"
#define FIN 0
#define ECART 1000

#include <stdlib.h>
#include <stdio.h>

char* explor(int n1, int n2 , int n3, int n4, int n5, int n6, int num_goal);
int develop(int * rest, int num_goal, int * resolu, T_elt t, int min_ecart, char * best);
char * tab2s(int * tab);
