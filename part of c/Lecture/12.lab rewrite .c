#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    char c;
    int k, i;
    FILE *f ,*tmp;

    f = fopen("sample.txt","r+");
    tmp = fopen("temp.txt","w+");

    if(f==NULL && tmp == NULL)
    {
        printf("The file could not be opened\n");
        exit(1);
    }
    
    fseek(f,0,SEEK_END);
    k=ftell(f);

    for ( i = 0; i < k; i++)
    {
        fseek(f,-i-1, SEEK_END);
        c=fgetc(f);
        fputc(c,tmp);
    }

    


    return 0;
}
