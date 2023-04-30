#include<stdio.h>
int result = 0;
void russian_multiplication (unsigned int* multiplicand, unsigned int* multiplier){
    if(*multiplier == 1) return;
    if(*multiplier % 2 == 1) result += *multiplicand;
    *multiplicand = *multiplicand*2;
    *multiplier = *multiplier/2;
    russian_multiplication(multiplicand,multiplier);
}
int main(int argc, char const *argv[])
{   
    unsigned int multiplicand,multiplier;
    printf("Enter multiplicand : ");
    scanf("%d",&multiplicand);
    printf("Enter multiplier : ");
    scanf("%d",&multiplier);
    
    russian_multiplication(&multiplicand,&multiplier);
    printf("%d",37*146);
    puts("");
    printf("%d",result);
    return 0;
}