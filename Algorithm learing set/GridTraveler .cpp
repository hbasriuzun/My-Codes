#include <iostream>
#include <stdlib.h>

//int *term = (int*)calloc(1000,sizeof(int));

using namespace std;

typedef struct term
{
    long n;
    long m;
}key;


key term[1000];

long grid_traveler(long n, long m)
{
    key key1;
    int a=0;
    key1.n = n;
    key1.m = m;

    if (n == 1 && m == 1 ) return 1;
    if (n == 0 || m == 0 ) return 0;

    if (term[key] != 0)
    {
        return term[key];
    }
    

   else {
    term[key1] = grid_traveler(n-1, m) + grid_traveler(n, m-1);
    a = term[key1];
    return term[key1];
   } 
}
int main(int argc, char const *argv[])
{
    long n=3;
    long m=3;
    cout << grid_traveler(n,m);
    cout << term[300] << endl;
    return 0;
}
