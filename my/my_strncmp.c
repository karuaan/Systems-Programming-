#include "my.h"

int my_strncmp(char *a, char *b, int n){

	int countA = 0;
	int countB = 0;
	int valA = 0;
	int valB = 0;

	if(n == 0 || n < 0) {
		return 0;
	}

	if(a == NULL && b==NULL){
		return 0;
	}

	if(a == NULL && b != NULL){
		return -1;
	}

	if(a != NULL && b == NULL){
		return 1;
	}

	while(countA < n && ((char) *a != '\0')){

		valA += (int)*a++;
		countA++;

	}

	while(countB < n && ((char) *b != '\0')){

		valB += (int)*b++;
		countB++;
		
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