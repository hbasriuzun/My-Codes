#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, num,i,typ,sum=0;
    scanf("%d\n",&n);
    char *ptr = (char*) malloc(n*sizeof(char));
    scanf("%c",&ptr[0]);    
    
    for ( i = 1; i < n;)
    {
        n--;
        scanf("%c",&ptr[i]);
        if (ptr[i-1] != ptr[i])
        {
            i++;
            n++;
        }
        
    }

    for ( i = 0; i < n; i++)
    {
        printf("%c",ptr[i]);
    }
    
    return 0;
}