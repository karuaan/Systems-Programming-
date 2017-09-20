#include "mylist.h"


void append(struct s_node *node, struct s_node **head){

	struct s_node *currNode; 

	if(head == NULL){
		return;
	}

	if(node == NULL || node -> elem == NULL){
		return; 
	}

	if(*head == NULL){
		node -> next = NULL;
		node -> prev = NULL;
		*head = node;
	}
	
	currNode = *head;

	while(currNode -> next != NULL){
		currNode = currNode -> next; 
	}

	node -> next = NULL;
	node -> prev = currNode; 
	currNode -> next = node; 



}