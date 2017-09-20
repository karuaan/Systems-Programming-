#include "my.h"


char *my_strconcat(char *a, char *b){

	if(a == NULL && b == NULL){
		return NULL;
	}

	int x = my_strlen(a) + my_strlen(b) + 1;


	char *dst = (char*) malloc(x * sizeof(char));

	return my_strcpy(dst,my_strcat(a,b));


}