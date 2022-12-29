#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calculate_fibonacci_sequence(int n)

int fibonacci(int n){
    int a = 1, b = 1;
    printf("%d\n",b);
    printf("%d\n",a);
    for (int i = 0; i < n; ++i)
    {
        int c = a + b;
        printf("%d\n",c);
        a = b;
        b = c;
    }
}

int main(int argc, char const *argv[])
{
    int a=5;
    fibonacci(a);
    return 0;
}
