#include "my.h"
#include <stdio.h>


char *my_vect2str(char **x){


	char **newSA = x; 
	char *currStr; 
	int len = 0; 

	if(x != NULL){

        for(; *x != NULL; x++)
        {
            if(x + sizeof(char*) != NULL && len > 1)
                len++;

            len += my_strlen(*x);
        }


        currStr = (char *) malloc(len * sizeof(char)); 
        x = newSA; 

        for(; *x != NULL; x++)
        {
            currStr = my_strcat(currStr, *x);
            currStr = my_strcat(currStr, " ");
        }

        currStr[len] = '\0';
    }

    return currStr;

}











