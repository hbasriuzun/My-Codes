#include <stdio.h>
#include <string.h>
typedef struct {
    float lenght;
    float width;
    float diagonal;
}rectangle;

int main()
{
    rectangle a = {16,5};
    rectangle *ptr;
    ptr = &a;
    printf("%   .1f",a.lenght);
    ptr->lenght = 13;
    printf("\n%.1f",a.lenght);

    printf("\n%d",sizeof(ptr));
    printf("\n%d",sizeof(a));
    return 0;
}