#include "mylist.h"

void empty_list(struct s_node **head){
	
	if (head != NULL){
		while(*head != NULL){
			remove_node(head);
		}
	}
}