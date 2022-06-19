#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int account;
    char name[30];
    double balance;

    FILE *f;
    f = fopen("read.txt","r");
    if (f == NULL)
    {
        printf("File could not be opened");
        exit(1);
    }
    
    
    printf("Positive Balance:\n");
    printf("%-10s%-13s%s\n","Account","Name","Balance");
    fscanf(f,"%d %s %lf",&account,name,&balance);

    while (!feof(f))
    {
        if (balance >= 0)
            printf("%-10d %-13s %7.2f\n",account,name,balance);
        fscanf(f,"%d %s %lf",&account,name,&balance);
        
    }
    rewind(f);
    printf("NEGATIVE BALANCE:\n");
printf( "%-10s%-13s%s\n", "Account", "Name", "Balance");
fscanf( f, "%d %29s %lf", &account, name, &balance);
while (!feof(f)) {
if(balance<0)
printf("%-10d%-13s%7.2f\n", account, name, balance);
fscanf(f, "%d %29s %lf", &account, name, &balance);
}
fclose(f);

    return 0;
}
