#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char st[30];
	int i;
	
	fp = fopen("clients.txt","w");
	
	fprintf(fp,"Burcu Tas\n");
	
	for(i=0 ;i < 5; i++){
		printf("The %d. string: ");
		gets(st);
		fprintf(fp,"%s\n",st);
	}
	fclose(fp);
	
	return 0;
}