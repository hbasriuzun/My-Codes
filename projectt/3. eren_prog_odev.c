#include <stdio.h>
#include <stdlib.h>
 #include <stdio.h>
#include <stdlib.h>
void calculate_fibonacci_sequence(){
    char line[100] = "", c  = '\n';
    int x;
    
    int i;
    int toplam;
    while(c != '*'){
    int first_term = 0 ; 
    int second_term = 1;
        toplam = 0;
    printf("Terim sayisi giriniz : ");
    scanf("%d",&x);
    scanf("%c",&c);
    if(c == '*') break;
    while (c != '\n' || x < 0){
        toplam = 0;
            if(c == 42) break;
            if(c != '\n'){
                printf("Sayisal bir deger giriniz:");
                scanf("%d",&x);
                scanf("%c",&c);
            }
            if (x < 0)
            {
                if(c == 42) break;
                printf("pozitif bir deger girin lutfen:");
                scanf("%d",&x);
                scanf("%c",&c);
            }
            
        }

   if(c != 42){
       printf("\nfibonacci serisi:\n\n %d\n ",second_term);} 
    i=1;    
    while (i<x)
    {
        toplam = 0;
        toplam=first_term+second_term;
        first_term=second_term;
        second_term=toplam;
        ++i;
        printf("%d\n ",toplam);
    }
    }
}    
int main(){
    calculate_fibonacci_sequence();
}