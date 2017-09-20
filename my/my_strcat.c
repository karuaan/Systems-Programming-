#include "my.h"


char *my_strcat(char *dst, char* src){

	int x = my_strlen(dst);
	int count = 0;

	while(src[count] != '\0'){
		dst[x] = src[count];
		x++;
		count++; 
	}

	dst[x] = '\0';


	return dst; 

}