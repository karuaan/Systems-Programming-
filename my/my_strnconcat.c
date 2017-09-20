#include "my.h"

char *my_strnconcat(char *a, char *b, int n){

	if(a == NULL && b == NULL){
		return NULL;
	}

	int x = my_strlen(a) + 1;

	if(n > my_strlen(b)){
		x += my_strlen(b);
	} 

	else {
		x += n;
	}

	int count = 0;
	char *str = (char*) malloc(x * sizeof(char));

	while(count < n){
		str[count] = b[count];
		count ++;
	}


	char *dst = (char*) malloc(x * sizeof(char));

	return my_strcpy(dst,my_strcat(a,str));


}