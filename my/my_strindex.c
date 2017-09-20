#include "my.h"

int my_strindex(char *s, char c){

	int count = 0;

	if(s == NULL){
		return -1; 
	}

	while((char) *s != '\0'){
		if(*s++ == c){
			return count;
		}

		count++;
	}

	return -1; 
}