#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>

#define endl "\n"
const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int fac(int n){ // 1 * 2* 3* 4 *5
    if(1 == n)
        return 1;

    return n * fac(n-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cout << fib(10) << endl;
    cout << fac(5) << endl;
    return 0;
}