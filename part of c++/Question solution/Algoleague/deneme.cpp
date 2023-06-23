#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
    ll n,min_sum=1000000000;
    cin>>n;
    if(n==1){
        ll num;
        cin>>num;
        cout<<abs(num)<<endl;
        return 0;
    }

    vector<ll> v(n);
    for(ll i=0; i<n; i++)
        cin>>v[i];

    for(ll i; i<n; i++){
        for(ll j=i+1; j<n; j++){
            if(abs(v[i]+v[j])<min_sum)
                min_sum = abs(v[i]+v[j]);
        }
    }
    
    cout<<min_sum<<endl;
    return 0;
}