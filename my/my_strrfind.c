#include "my.h"


char *my_strrfind(char *s, char c){
	int x = my_strlen(s);

	for(int i = x; i > -1; i--){
		if(s[i] == c){
			return &s[i];
		}

	}

	return NULL;

}