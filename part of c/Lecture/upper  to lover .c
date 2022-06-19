#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    int k, i;
    FILE *fp;
    fp = fopen("sample.txt","r+");
    if (fp == NULL)
    {
        puts("The file could not be opened.");
    }
    fseek(fp,0,SEEK_END);
    k=ftell(fp);
    for ( i = 0; i < k; i++)
    {
        fseek(fp, i, SEEK_SET);
        c=fgetc(fp);
        if (c>="A"  &&  c<="Z")     
        {
            c += "a" - "A";  
            fseek(fp, i, SEEK_SET);
            fputs(c,fp); 
        }
        
        if (c>="a"  &&  c<="z")     
        {
            c -= "a" - "A";  
            fseek(fp, i, SEEK_SET);
            fputs(c,fp); 
        }
    }
    

    return 0;
}
