#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int account;
	char name[30];
	double balance;
	
	FILE *fp;
	fp = fopen("FOF.txt","w");
	
	if(fp == NULL){
		printf("File could not be opened");
		exit(1);
	}


	return 0;
}
