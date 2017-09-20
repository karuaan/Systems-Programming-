#include "mylist.h"


void *remove_node(struct s_node **node){
	
	void *del = NULL;
	struct s_node *delNode;

	if(node != NULL && *node != NULL){
		
		delNode = *node; 
		del = delNode -> elem; 
		*node = delNode -> next; 
		(*node) -> prev = delNode -> prev;  
		delNode -> prev -> next = *node;
		free(delNode);

	}

	return del;
}