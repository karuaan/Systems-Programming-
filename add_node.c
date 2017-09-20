#include "mylist.h"

void add_node(struct s_node *node, struct s_node **head){

	if(node == NULL || (node -> elem = NULL)){
		return;
	}

	if(*head == NULL){
		node -> prev = NULL; 
		node -> next = NULL; 
		*head = node; 
	}

	else{

		node -> prev = NULL; 
		node -> next = *head; 
		*head = node; 

	}




}