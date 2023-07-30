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
     
    using namespace std;
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        ll n,q;
        cin >> n >> q;
        
        ll a[n];
        
        for(ll& x : a){
            cin >> x;
        }
        
        while(q--){
            ll x,l = -1,r = n-1,mid;
            cin >> x;
     
            while (l<r)
            {
                mid = (l+r+1)/2;
                if(a[mid]<=x)
                    l = mid;
                else
                    r = mid-1;
            }
            
            cout << l+1 << endl;
            
     
     
        }
        
        return 0;
        
    }