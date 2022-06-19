#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *f;
    int k;
    char ch;
    f = fopen("FOF.txt","r");
    if (f == NULL)
    {
        printf("File could not be opened.");
    }
    

    k = ftell(f);

    ch = fgetc(f);

    while (!feof(f))
    {
        printf("%d --> %c\n",k,ch);
        k = ftell(f);
        ch = fgetc(f);
            if (ch == EOF)
            {
                printf("%d --> EOF\n",k);
            }
            
    }
    
    fclose(f);
    return 0;
}
