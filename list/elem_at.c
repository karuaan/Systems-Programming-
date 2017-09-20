#include "mylist.h"

void *elem_at(struct s_node *head, int n){
	int count = 0; 

	if(head == NULL){
		return NULL;
	}

	while(count < n){
		if(head -> next == NULL){
			break;
		}

		head = head -> next; 
		count++;
	}

	return &(head -> elem); 
}