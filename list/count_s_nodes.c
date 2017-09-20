#include "mylist.h"

int count_s_nodes(struct s_node *head){
	
	int count = 1;  

	if(head == NULL){
		return 0;
	}

	while(head -> next != NULL){
		head = head -> next;
		count++; 
	}

	return count; 


}