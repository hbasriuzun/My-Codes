#include <bits/stdc++.h>

#define endl "\n"
const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int sum = 0;
    for(int i =1; i < 1000; i++)
        if(i%3==0 || i%5==0) sum+=i;
    cout << sum << endl;
    

    return 0;
}