#include "my.h"

int my_strrindex(char *s, char c){
	int count = 0;
	int curr = -1;

	if(s == NULL){
		return -1; 
	}

	while((char) *s != '\0'){
		if(*s++ == c){
			curr = count;
		}

		count++;
	}

	if(curr != -1){
		return curr; 
	}
	
	return -1; 
}