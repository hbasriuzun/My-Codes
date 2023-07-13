#include <bits/stdc++.h>

#define endl "\n"
const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int q;
    cin >> q;
    vector<array<ll,2>> b(q);

    for(int i = 0; i < q; i++){
        cin >> b[i][0] >> b[i][1];
    }

    for(int i = 0; i < q; i++){
        auto lower = lower_bound(a.begin(), a.end(), b[i][0]);
        auto upper = upper_bound(a.begin(), a.end(), b[i][1]);
        int index = distance(a.begin(), lower);
        int index2 = distance(a.begin(), upper);
         cout << index2 - index << endl;
    }
    return 0;
}