#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct {
    float real;
    float imag;
} Complex;
    Complex product (Complex A, int B)
{
    Complex C;
    float q,l,r;
    r = sqrt((pow(A.imag,2) + pow(A.real,2)));
    q = atan(A.imag/A.real);
    C.real = pow(r,B) * cos(B*q);
    C.imag = pow(r,B) * sin(B*q); 
     
    return C;
}
int main () 
{
    Complex z1, result;
    int n;
    printf("Enter real part of the 1st number: ");
    scanf("%f",&z1.real);
    printf("Enter imag part of the 1st number: ");
    scanf("%f",&z1.imag);
    printf("Enter power of number: ");
    scanf("%d",&n);
    result = product(z1, n);
    printf("The results is: %.2f + %.2fi\n", result.real, result.imag);
    return 0; 
}

