#include <stdio.h>

void write_polynomial3(double a0, double a1, double a2, double a3){
    if(a0 != 0){
        if(a0 == 1.0)
            printf("x^3+");
        else if(a0 == -1.0)
            printf("-x^3+");
        else if(a1 < 0)
            printf("%dx^3",a0);
        else
            printf("%dx^3+",a0);
    }
    if(a1 != 0){
        if(a2 < 0 && a1 == 1.0)
            printf("x^2-",a1);
        else if(a2 < 0 && a1 == -1.0)
            printf("-x^2-",a1);
        else if(a1 == 1.0)
            printf("x^2+");
        else if(a1 == -1.0)
            printf("-x^2+");




        else if(a2 < 0)
            printf("%dx^2-",a1);
        else
            printf("%dx^2+",a1);
    }
        
}

int main(int argc, char const *argv[])
{
    write_polynomial3(-1.0,1.0,-3.2,0.0);
    return 0;
}
