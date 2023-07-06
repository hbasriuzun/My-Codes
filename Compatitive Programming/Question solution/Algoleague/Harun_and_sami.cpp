#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;

    int countH = 0;
    for (char i : a) {
        if(i == 'H'){
            countH++;
        }
    }

    int countS = k - countH;

    if(countS > n /2){
        cout<<"Sami";
    }else if(countH > n/2){
        cout<<"Harun";
    }else{
        cout<<"Cilek";
    }



    return 0;
}