#include <stdio.h>
void calculate_fibonacci_sequence(){
    char line[100] = "", c  = '\n';
    int x,terim_sayisi;
    int flag = 0;
    int first_term = 0 ; 
    int second_term = 1;
    int i;
    int toplam;

    printf("Terim sayisi giriniz : ");
    scanf("%d",&x);
    scanf("%c",&c);

    while (c != '\n' || x < 0){
            if(c != '\n'){
                printf("Please enter “numeric” term(s) number:");
                scanf("%d",&x);
                scanf("%c",&c);
            }
            if (x < 0)
            {
                printf("Please enter “positive” term(s) number:");
                scanf("%d",&x);
                scanf("%c",&c);
            }
            
        }

   printf("\nfibonacci serisi:\n\n %d\n ",second_term); 
    i=1;    
    while (i<x)
    {
        toplam=first_term+second_term;
        first_term=second_term;
        second_term=toplam;
        ++i;
        printf("%d\n ",toplam);
    }
}

int main(){
    calculate_fibonacci_sequence();
    return(0);
}