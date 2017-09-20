#include "my.h"

char *my_strfind(char *s, char c){

	int x = my_strlen(s);

	for(int i = 0; i < x; i++){
		if(s[i] == c){
			return &s[i];
		}

	}

	return NULL;


}