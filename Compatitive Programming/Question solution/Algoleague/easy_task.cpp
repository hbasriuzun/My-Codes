#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;



int main(){
    ll n,m,sum = 0;
    cin >> n >> m;
    vector<ll> v(n),w(m);
    for(ll i=0;i<n;i++){
        cin >> v[i];
    }
    for(ll i=0;i<m;i++){
        cin >> w[i];
    }
    sort(v.begin(),v.end());
    sort(w.begin(),w.end());

    for(ll i=0;i<m;i++){
        sum += upper_bound(v.begin(),v.end(),w[i]) - v.begin();
    }
    cout << sum << endl;
    return 0;
}