#include "mylist.h"
#include <stdio.h>


void debug_char(struct s_node *head){

	int count = 0; 
	
	if(head == NULL){
		return;
	}

	printf("NULL <- "); 

	while(head -> next != NULL){
		if(count > 0){
			printf("<- ");
		}
		count++;
		printf("%c ", *((char *) elem_at(head,0)));
		printf("-> ");
		head = head -> next;
	}

	printf("%c", *((char *) elem_at(head,0)));

	printf(" -> NULL");

	printf("\n");

}