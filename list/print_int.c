#include "mylist.h"


void print_int(struct s_node *node){

	if(node == NULL){
		return;
	}

	if(node -> elem == NULL){
		my_str("NULL");
	}

	my_int(*((int *)node->elem));


}