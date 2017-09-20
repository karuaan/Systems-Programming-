#include "mylist.h"
#include <stdio.h>


void print_string(struct s_node *node){

	if(node == NULL){
		return;
	}

	char *s = (node -> elem);

	while((char) *s != '\0'){
		printf("%c",*s++);
	}

	printf("\n");

}