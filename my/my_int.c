#include "my.h"

void my_int(int num){

	int x, pow = 1;

	if(num < 0){
		my_char('-');
		x = num* -1; 
	}

	else{
		x = num;
	}

	while(pow <= x/10){
    	pow *= 10;
  	}

 	while(pow>0){
    	my_char('0'+x/pow);
    	x %= pow;
    	pow /= 10;
  	}


}