#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

void fin_min(vector <ll> v, ll& min_value){
    
    ll sum = 0;

    for(auto i : v){
        sum += i;
    }
    sum = abs(sum);
    min_value = min(min_value, sum);
    for(ll i = 0; i < v.size(); i++){
        vector <ll> v2 = v;
        v2.erase(v2.begin() + i); 
        if(v.size() == 2){
            min_value = min(min_value, abs(v[0] + v[1]));
            return;
        }
        fin_min(v2, min_value);
    }
}

int main(){
    ll n;
    cin >> n;
    vector <ll> v(n);
    if(n == 1){
        ll a;
        cin >> a;
        cout << abs(a) << endl;
        return 0;
    }

    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }
    ll min_value = 100000000000;
    fin_min(v, min_value);
    cout << min_value << endl;
}