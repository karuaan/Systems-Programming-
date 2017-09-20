#include "my.h"

int my_strlen(char *s){
	int len = 0;

	if(s == NULL){
		return -1;
	}

	while((char) *s++ != '\0'){
		len++;
	}

	return len;
}