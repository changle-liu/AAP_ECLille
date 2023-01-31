#include <stddef.h> 
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 20

typedef struct elt{
	int val;
	char str[MAXLEN];
}T_elt;

typedef struct node {
	T_elt e;
	struct node *pNext;
} T_node, * T_list;

static T_node * newNode(int e);
T_node * findMaxByVal(T_list l, T_node * position);
T_node * addEltSortByVal(T_list l, T_elt e);
void freeList_rec(T_list l);


