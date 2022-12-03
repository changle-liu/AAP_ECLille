#include "elt.h" // T_elt 

#ifndef _LIST_H_
#define _LIST_H_

typedef struct node {
	T_elt data;
	struct node *pNext;
} T_node, * T_list;

T_node * addNode (T_elt e, T_node * n);
void showList(T_list l);
void freeList(T_list l);
T_elt getFirstElt(T_list l);
T_list removeFirstNode(T_list l);
void showList_rec(T_list l);
void showList_inv_rec(T_list l);
void freeList_rec(T_list l);

#endif 


