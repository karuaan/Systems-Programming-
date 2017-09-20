#include "my.h"
#include <stdio.h>

int main(int argc, char const *argv[]){

	
	char *dst = (char*) malloc(20 * sizeof(char));
	char *src = (char*) malloc(20 * sizeof(char));

	dst = my_strcpy(dst, "hello");
	src = my_strcpy(src, "world");

	char *x[3] = {dst,src,NULL};

	printf("%s\n", my_vect2str(x));

	// printf("%s\n", my_strdup(dst));
	// printf("%s\n", my_strconcat(dst,src));
	// printf("%s\n", my_strnconcat(dst,src,3));

	free(dst);
	free(src);
	



	return 0;
}


