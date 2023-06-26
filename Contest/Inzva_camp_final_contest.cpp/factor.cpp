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
#define mod 1000000009
 // Recursive version of the factorial finding algorithm.
 long long facRec(long long n){
 if(n == 1)
 return 1;
 return ( (n%mod) * (facRec(n-1)%mod) ) % mod ;
 }

 long long facIt(long long n){
 long long res = 1;

 for(long long i = 1; i <= n; i++)
 res = (res * i)%mod;

 return res;
 }

 int main() {
 long long n;
 scanf("%lld",&n);
    n--;
if(n == 0 || n == 1){
    printf("1");
    return 0;
}
    
 long long res = facIt(n);


 printf("%lld\n", res);
 return 0;
}
