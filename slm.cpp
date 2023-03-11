#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double f(double x)
{
    double sum = x*x;
    return sum;
}
int main(int argc, char const *argv[])
{
    double dx ,sum=0;
    dx = 0.125;

    for (int i = 0; i < 8; i++)
    {
        double before = f(i*dx)*dx;
        sum += before;
    }
    cout << sum << endl;
}