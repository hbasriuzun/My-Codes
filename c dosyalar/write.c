#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int account;
	char name[30];
	double balance;
	
	FILE *fp;
	fp = fopen("read.txt","r");
	
	if(fp == NULL){
		printf("File could not be opened");
		exit(1);
	} 
	
	printf("%-10s%-13s%s\n","Account","Name","Balance");
	fscanf(fp,"%d %29s %lf",&account,name,&balance);
	
	while(!feof(fp)){
		
		printf("%-10d%-13s%7.2f\n",account,name,balance);
		fscanf(fp,"%d %29s %lf",&account,name,&balance);

	}

	
	fclose(fp);
	
	return 0;
}
