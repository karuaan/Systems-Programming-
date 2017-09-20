#include "mylist.h"

void *remove_node_at(struct s_node **head, int n){ 

	int count = 0; 
	struct s_node *delNode = *head;  
	void* del = NULL;


	if(head == NULL || *head == NULL){
		return 0;
	}

	while(count < n){

		if(delNode -> next == NULL){
			break;
		}

		delNode = delNode -> next; 
		count++;

	}


	del = delNode -> elem;
	*head = delNode -> next;
	(*head) -> prev = delNode -> prev; 
	(*head) -> prev -> next = *head; 
	free(delNode);

	return del; 

}