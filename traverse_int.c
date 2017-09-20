#include "mylist.h"
#include <stdio.h>


void traverse_int(struct s_node *head){
	
	if(head == NULL){
		return;
	}

	while(head -> next != NULL){
		printf("%d ", *((int *) (head -> elem)));
		head = head -> next;
	}

	printf("\n");

}