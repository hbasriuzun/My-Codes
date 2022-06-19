#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c;
    int k, i;
    FILE *f ;

    f = fopen("sample.txt","r+");

    if(f==NULL && tmp == NULL)
    {
        printf("The file could not be opened\n");
        exit(1);
    }
    
    fseek(f,0,SEEK_END);
    k=ftell(f);

    for ( i = 0; i < k; i++)
    {
        fseek(f,i, SEEK_CUR);
        c=fgetc(f);
    }
    return 0;
}



Sample
elpmaS