#include "mylist.h"
#include <stdio.h>

void print_char(struct s_node *node){

	if(node == NULL){
		return;
	}

	if(node -> elem == NULL){
		my_str("NULL");
	}

	my_char(*((char *) (node -> elem)));	
}