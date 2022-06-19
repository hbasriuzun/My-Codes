#include <iostream>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    char S[30];

    fp = fopen("sample.txt","w");

    if(fp==NULL)
    {
        printf("The file could not be opened\n");
        exit(1);
    }

    printf("The file has been opened\n");
    
    for (int i = 0; i < 4; i++)
    {
        printf("the %d. string:", i);
        gets(S);
        fprintf(fp,"%s ",S);
    }
    
    
    
    
    fclose(fp);

    return 0;
}
