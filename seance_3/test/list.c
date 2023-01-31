#include "list.h" 



static T_node * newNode(T_elt e) {

	T_node * pNode; 
	pNode = malloc(sizeof(T_node)); 
	pNode->T_elt = e; 
	pNode->pNext = NULL;

	return pNode;
}

T_node * findMaxByVal(T_list l, T_node * position){
	if (l==NULL) {
		return postion;
	}
	
	while(l != NULL){
		int i = 0;
		if((l->T_elt).val > i){
			i = (l->T_elt).val;
			position = l;
			
		} 
	}
	return position;
}

T_node * addEltSortByVal(T_list l, T_elt e){
	T_node * position = NULL;
	
	if(l == NULL){
		position = &e;
		return position;	
	}
	while(l != NULL){
		int i = 0;
		if(e.val > l->(T_elt).val){
			position = l;
		} 
	}
	T_node * p = position;
	position->pNext = e;
	e.pNext = p;
	
}

void freeList_rec(T_list l) {

	if (l == NULL) {
		return;
	} else {
		freeList_rec(l->pNext);
		free(l); 
	}
}



