#include "my.h"

void my_num_base(int num, char* s){

  int base, pow, a;

  if(s == NULL || my_strlen(s) == 0){
    my_str("Error, no base.");
    return ;
  }

  base = my_strlen(s);

  if(num < 0){
    my_char('-');
    a = num*-1;  
  }

  else{
    a = num;
  }

  if(base == 1){
    while(a-- > 0) my_char(s[0]);
  }

  else{
    pow = 1;

  while(pow*base<a){
    pow*=base;
  }

  while(pow > 0){
    my_char(s[a/pow]);
    a%=pow;
    pow/=base;
  }

  }
}
