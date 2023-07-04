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
typedef int long long ill;

bool bineary_search(vector<ll>& v,ll k){
    ll l=1,r=v.size()-1;
    while(l <= r){
        ll mid = (l+r+1)/2;
        if(v[mid] == k){
            return true;
        }
        else if(v[mid] > k){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,k;
    cin >> n >> k;


    vector<ll> array(n+1),queries(k);

    for(int i=1;i<=n;i++){
        cin >> array[i];
    }
    for(int i=0;i<k;i++){
        cin >> queries[i];
    }
    sort(array.begin()+1,array.end());
    for(int i=0;i<k;i++){
        if(bineary_search(array,queries[i])){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}