#include <stdio.h>

typedef struct 
{
    double x;
    double y;
    double z;
    double t;
}vector;

double companant(const vector u, int k)
{
    double *p = &u.x;
    return *(p+k-1);
}

int main(int argc, char const *argv[])
{
    vector a ={1,2,3,4};
    double num;

    num=companant(a,2);
    printf("%lf",num);
    return 0;
}

