#include "my.h"

char *my_strncpy(char *dst, char *src, int n){

	int count = 0;

	if(dst == NULL || src == NULL){
		return NULL; 
	}

	while(src[count] != '\0' || (count < n)){

		dst[count] = src[count];
		count++;
	}

	dst[n] = '\0';

	return dst; 
}