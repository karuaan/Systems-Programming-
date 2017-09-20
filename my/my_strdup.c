#include "my.h"


char *my_strdup(char *str){

	char *dst = (char*) malloc(my_strlen(str) * sizeof(char));

	my_strcpy(dst,str);

	return dst; 


}