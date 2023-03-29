#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
            
        map<ll,ll> mp;
        ll ans = 0;

        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            ans += mp[x-i];
            mp[x-i]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}