#include <stdio.h>

void decide_perfect_harmonic_number()
{
    int number;
    char char_ ;
    char positiveanswer[] = "Yes",negativeanswer[] = "No";
    while(number){
        if(number - (int)number == 0){
        int sum=0,i;
        double harmonicsum=0.0;
        printf("please enter a number :\n");
        scanf("%d",&number);
        scanf("%c",&char_);
       

        while (char_ != '\n' || number < 0){
            if(char_ != '\n'){
                printf("Please enter “numeric” term(s) number:");
                scanf("%d",&number);
                scanf("%c",&char_);
            }
            if (number < 0)
            {
                printf("Please enter “positive” term(s) number:");
                scanf("%d",&number);
                scanf("%c",&char_);
            }
            
        }

        
        printf("Natural divisors : ");
        for (int i=1;i<=number;i++){
            if (number%i==0) {
                printf("%d ",i);
                }}
        for(i = 1 ; i < number ; i++)   
        {   
            if(number % i == 0)   
            sum = sum + i ;   
        }
        printf("\n");
        printf("Is Perfect Number?:\n");
        if(sum == number){
            for (i = 0; i < 3; ++i) {
                printf("%c", positiveanswer[i]);
               }}

        else{
            for (i = 0; i < 2; ++i) {
                printf("%c", negativeanswer[i]);
               }
        }
        printf("\n");
        for ( int i=1;i<=number;i++){
            if (number%i==0) {
                harmonicsum += 1/i;
            }}
        printf("Is Harmonic Divisor Number? : ");
        if(harmonicsum - (int)harmonicsum == 0 )
        {
            printf("%s",positiveanswer);

        }
        else
        {
            printf("%s",negativeanswer);

        }
        printf("\n");
        }
        char_ = '~';
    }
    
}
int main()
{
    decide_perfect_harmonic_number();
}