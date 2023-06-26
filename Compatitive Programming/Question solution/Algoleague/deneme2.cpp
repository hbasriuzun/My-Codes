#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){
    ll n,num;
    cin >> n;
    if(n==1){
        cin >> num;
        cout << abs(num) << endl;
        return 0;
    }
    vector <ll> minus(n),plus(n);
    for(ll i=0,j=0,k=0; i<n;i++){
        cin >> num;
        if(num<0)
            minus[j++] = num;
        else
            plus[k++] = num;
    }
    ll min_sum = 1000000000;
    sort(minus.begin(),minus.end());
    sort(plus.begin(),plus.end());
    
    if(minus.size() == 0)
        min_sum = plus[0] + plus[1];
    else if(plus.size() == 0)
        min_sum = abs(minus[minus.size()-1] + minus[minus.size()-2]);
    

    for(ll i=0; i<minus.size(); i++){
        for(ll j=0; j<plus.size(); j++){
            if(abs((minus[i] + plus[j]) < min_sum))
                min_sum = abs(minus[i] + plus[j]);
        }
    }
    cout << min_sum << endl;
}