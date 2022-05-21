#include <iostream>
using namespace std;

int normal_factorial(int n){

 int result = 1;

 for( int i=1 ; i<=n ; i++)
 result *= i;

 return result;
 }

 int recurison_factorial(int n){
     if(n==0)
        return 1;
    return n * recurison_factorial(n-1);
 }

int main(int argc, char const *argv[])
{
    int a=6;
    cout << "Normal factoriel calculate: " <<normal_factorial(a)<< endl <<"Recursion factoriel calculate: " << recurison_factorial(a);
    return 0;
}
