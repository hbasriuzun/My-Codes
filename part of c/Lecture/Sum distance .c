#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct {
    int m;
    int cm;
} Distance;
    Distance product (Distance A, Distance B)
{
    Distance sum;
    sum.m = 0; sum.cm = 0;
    sum.m = A.m + B.m;

     if(A.cm + B.cm <= 100)
     {
         sum.cm = A.cm + B.cm;
     } 
     else
     {
         sum.cm = A.cm + B.cm - 100;
         ++sum.m;
     }
    return sum;
}
int main () 
{
    Distance z1, z2, result;
    int n;
    printf("Enter m part of the 1st number: ");
    scanf("%d",&z1.m);
    printf("Enter cm part of the 1st number: ");
    scanf("%d",&z1.cm);
    printf("Enter m part of the 2st number: ");
    scanf("%d",&z2.m);
    printf("Enter cm part of the 2st number: ");
    scanf("%d",&z2.cm);
    
    result = product(z1, z2);
    printf("The sum is: %dm + %dcm\n", result.m, result.cm);
    return 0; 
}

