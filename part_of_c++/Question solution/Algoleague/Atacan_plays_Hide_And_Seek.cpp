#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){
    ll n,m,x;
    cin >> n >> m;
    vector <ll> v(m);
    map <ll, pair<ll,ll>> mp;

    for(ll i=0; i<n; i++){
        cin >> x;
        pair<ll,ll> p;
        p.first = x;
        if(mp.find(x)==mp.end()){
            mp[x].first = 1;
            mp[x].second = i+1;
        }else
            mp[x].first += 1;
    }

    for(ll i=0; i<m; i++){
        cin >> v[i];
        if(mp[v[i]].first == 1){
            cout << mp[v[i]].second << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
        

    return 0;
}