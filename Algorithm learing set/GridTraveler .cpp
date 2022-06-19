#include <iostream>

using namespace std;
long term[1000];

long grid_traveler(long n, long m)
{
    long key = n + m;

    if (n == 1 && m == 1 ) return 1;
    if (n == 0 || m == 0 ) return 0;

    else if (term[key] != 0)
    {
        return term[key];
    }
    

   else {
    term[key] = grid_traveler(n-1, m) + grid_traveler(n, m-1);
    return term[key];
   } 
}
int main(int argc, char const *argv[])
{
    long n=18;
    long m=18;
    cout << grid_traveler(n,m) << endl;
    return 0;
}
