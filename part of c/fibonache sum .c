#include <stdio.h>
int fib (int index)
{
    //We can solve fibonaccie sum problem but this foncion make a lot of time. Just like n^2.
    printf("%d\n",index);
    if (index <= 2) return 1;
    return fib(index-1) + fib (index-2);
}
int main()
{
    int num = 20
    ;
    printf("%d",fib(num));
    return 0;
}