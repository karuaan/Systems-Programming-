#include "my.h"

int my_atoi(char *str){

  int i=0;
  int s=1;
  int seenInt = 0; 

  for (; *str == ' ' || *str == '\t'; str++){
  	;
  }
	

  for (; *str != '\0' ; str++) {

    if (*str == ' ' || *str == '.'){
      	break;
    }

    else if(seenInt == 1 && (*str < '0' || *str > '9')){
    	break;
    }
  

    else if (*str == '-'){
      	s *= -1;
    }

    else if (*str >= '0' && *str <= '9') {

    	seenInt = 1; 

      	if (i > 0){

			i *= 10;
      	}

      	i += *str - '0';
    }
  }

  return i * s;


}