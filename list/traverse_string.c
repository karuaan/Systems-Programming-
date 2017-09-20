#include "mylist.h"
#include <stdio.h>


void traverse_string(struct s_node *head){

	if(head == NULL){
		return;
	}

	while(head -> next != NULL){
		char *s = (head -> elem); 

		while( (char) *s != '\0'){
			printf("%c", *s++);
		}

		printf(" ");
		head = head -> next;
	}

	printf("\n");

}