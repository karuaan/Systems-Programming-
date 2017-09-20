#include "my.h"

int my_strcmp(char *a, char *b){

	int valA = 0;
	int valB = 0;

	if(a == NULL && b==NULL){
		return 0;
	}

	if(a == NULL && b != NULL){
		return -1;
	}

	if(a != NULL && b == NULL){
		return 1;
	}

	while((char) *a != '\0'){
		valA += (int)*a++;
	}

	while((char) *b != '\0'){
		valB += (int)*b++;
	}


	if(valA == valB){
		return 0;
	}

	if(valA < valB){
		return -1;
	}

	else{
		return 1; 
	}
	
}