#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    //long long x = 123456789123456789LL;
    
    long long x = 1,m=31,n=6;
for (int i = 2; i <= n; i++) {
x = (x*i)%m;
}

cout << x%m << "\n";
cout << 720%m << "\n";

    return 0;
}
