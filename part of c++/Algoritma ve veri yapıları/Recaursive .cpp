#include <bits/stdc++.h>
using namespace std;

void permutasyon(char A[], int ilk, int son),swap(char *x, char *y);

void swap(char *x, char *y){
    char temp = *x;
    *x=*y;
    *y=temp;
}

int main(int argc, char const *argv[])
{
    char dizi[3] = {'x','y','z'};
    permutasyon(dizi,0,2);  
    return 0;
}

void permutasyon(char A[], int ilk, int son)
{
    int i;

    if(ilk==son){
        for ( i = 0; i <= son; ++i)
            printf("%c",*(A+i));
        printf("\n");
    }else
        for ( i = ilk; i <= son; ++i)
        {
            swap(&A[ilk],&A[i]);
            permutasyon(A, (ilk+i), son);
            swap(&A[ilk],&A[i]);
        }
}

