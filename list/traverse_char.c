#include "mylist.h"
#include <stdio.h>


void traverse_char(struct s_node *head){
	if(head == NULL){
		return;
	}

	while(head -> next != NULL){
		printf("%c ", *((char *) (head -> elem)));
		head = head -> next;
	}

	printf("\n");

}