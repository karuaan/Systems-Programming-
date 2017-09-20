#include "mylist.h"
#include <stdio.h>

void debug_string(struct s_node *head){
	
	if(head == NULL){
		return;
	}

	printf("NULL ");

	while(head -> next != NULL){

		char *s = (head -> elem); 
		printf("<- ");

		while( (char) *s != '\0'){
			printf("%c", *s++);
		}

		printf(" ");
		printf("-> ");
		head = head -> next;
	}

	char *t = (head -> elem); 
	printf("<- ");

	while( (char) *t != '\0'){
		printf("%c", *t++);
	}


	printf(" -> NULL");
	printf("\n");

}