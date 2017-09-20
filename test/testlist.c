#include "mylist.h"
#include <stdio.h>




int main(int argc, char const *argv[]){

  struct s_node *a;
  a = (struct s_node *) malloc(sizeof(struct s_node));
  a -> elem = (void *) 5;

  struct s_node *c;
  c = (struct s_node *) malloc(sizeof(struct s_node));
  c -> elem = (void *) 7;

  printf("%d\n", *((int *)elem_at(a,0)));
  printf("%d\n", *((int *)elem_at(c,0)));

  struct s_node *b;
  b = new_node((void *) 'b', c, a);
  printf("%d\n", *((int *)elem_at(b,0)));

  debug_int(a);
  debug_char(b);
  debug_string(b);

  // struct s_node **linkedList[10]; 

  // linkedList[0] = *a;
  // linkedList[1] = *b;
  // linkedList[2] = *c;



  // struct s_node *head;
  // head = NULL;
  // add_elem("CAT", &head);
  // my_str("\n");
  // debug_string(head);
  // free(head);


  



	// struct s_node *a;
	// struct s_node *b;
	// struct s_node *c;

	// a =(struct s_node *)malloc(sizeof(struct s_node));
	// a -> elem = (void *) 5; 

	// c =(struct s_node *)malloc(sizeof(struct s_node));
	// c -> elem = (void *) 7; 

	// b = new_node((void *) 6, c, a);

	// print_int(b);

 

  // free(a);
  // free(b);
  // free(c);


	return 0;
}