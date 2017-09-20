#include "mylist.h"
#include <stdio.h>

void debug_int(struct s_node *head){

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
		printf("%d ", *((int *) elem_at(head,0)));
		printf("-> ");
		head = head -> next;
	}

	printf("%d", *((int *)elem_at(head,0)));


	printf(" -> NULL");

	printf("\n");
}