#include "my.h"

int my_revstr(char *s){

	int i=0;
	int len = my_strlen(s)-1;
    char t;

    while(i < (len/2 + 1)){
		t = s[i];
		s[i] = s[len - i];
		s[len - i] = t;
		i++;
	}

    return len+1;
}