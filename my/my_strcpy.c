#include "my.h"

char *my_strcpy(char *dst, char *src){

	if(dst == NULL || src == NULL){
		return NULL;
	}

	int x = my_strlen(src);

	for(int i = 0; i < x; i++){
		dst[i] = src[i];
	}

	dst[x] = '\0';

	return dst;

}