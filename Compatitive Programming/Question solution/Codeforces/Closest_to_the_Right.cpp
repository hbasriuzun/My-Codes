#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    n++;
    int a[n], b[m];
    for(int i = 1; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
        
    for(int i = 0; i < m; i++){
        auto lower = lower_bound(a+1, a+n, b[i]);
        int index = distance(a, lower);
        cout << index << endl;
    }
    return 0;
}