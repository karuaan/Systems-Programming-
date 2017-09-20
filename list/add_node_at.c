#include "mylist.h"

void add_node_at(struct s_node *node, struct s_node **head, int n){
	
	int count = 0; 
	struct s_node *currNode = *head;  

	if(node == NULL || node -> elem == NULL){
		return;
	}

	if(*head == NULL){
		node -> prev = NULL; 
		node -> next = NULL; 
		*head = node; 
	}

	while(count < n){

		if(currNode -> next == NULL){
			break;
		}

		currNode = currNode -> next; 
		count++;

	}

	node -> next = currNode -> next;
	node -> prev = currNode; 
	currNode -> next = node; 

}