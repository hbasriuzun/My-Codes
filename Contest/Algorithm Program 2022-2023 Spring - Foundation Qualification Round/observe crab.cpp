#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll t, t2,num;
    cin >> t;
    cin >> t2;
    while (--t)
    {
        cin >> num;
        if(t2 != num){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
    
}