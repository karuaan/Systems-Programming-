#include "mylist.h"

struct s_node *new_node(void *elem, struct s_node *next, struct s_node *previous){

	struct s_node *newNode = (struct s_node*) malloc(sizeof(struct s_node));
	newNode -> elem = elem;
	newNode -> next = next; 
	newNode -> prev = previous; 

	return newNode;
	
}