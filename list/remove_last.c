#include "mylist.h"


void *remove_last(struct s_node **head){
	
	struct s_node *currNode = *head; 
	void *del = NULL;

	if(head == NULL || *head == NULL){
		return 0;
	}

	while(currNode -> next != NULL){
		currNode = currNode -> next;  
	}

	del = currNode -> elem; 
	*head = currNode -> next;
	(*head) -> prev = currNode -> prev;
	(*head) -> prev -> next = *head;
	free(currNode);

	return del;


}