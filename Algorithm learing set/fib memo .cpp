// CPP program to find the Nth term
// of Fibonacci series
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long term[1000];
// Fibonacci Series using memoized Recursion
long fib(long n)
{
    // base case
    if (n <= 1)
        return n;
 
    // if fib(n) has already been computed
    // we do not do further recursive calls
    // and hence reduce the number of repeated
    // work
    else if (term[n] != 0)
        return term[n];
 
    else {
 
        // store the computed value of fib(n)
        // in an array term at index n to
        // so that it does not needs to be
        // precomputed again
        term[n] = fib(n - 1) + fib(n - 2);
 
        return term[n];
    }
}
 
// Driver Code
int main()
{
    long n = 3;
    printf("%d", fib(n));
    return 0;
}