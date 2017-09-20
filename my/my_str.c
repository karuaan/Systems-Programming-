#include "my.h"

void my_str(char *c){
	if(c == NULL || (char)*c == '\0'){
		return ;
	}

	my_char((char)*c);
	my_str(++c);
}