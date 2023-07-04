#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

bool compare(int a, int b) {
    return a > b;  // Büyükten küçüğe sıralama için ">" operatörünü kullanıyoruz
}

int main(){
    string s,s2;
    cin >> s;

    ll s_size = s.size();
    map<char,ll> mp;

    if(s_size == 1){
        cout << s;
        return 0;
    }

    for(ll i=0; i<s_size; i++){
        mp[s[i]]++;
    }

    short odd = 0;
    char check;
    for(auto i : mp){
        if(i.second % 2 == 1){
            check = i.first;
            odd++;
        }
        if(odd == 2){
            cout << "NO SOLUTION";
            return 0;
        }
    }
    mp[check]--;
    for(auto i : mp){
        if(i.second % 2 == 0){
            for(ll j=0; j<i.second/2; j++){
                s2.push_back(i.first);
            }
        }
    }

    cout << s2;
    cout << check;

    sort(s2.begin(), s2.end(), compare);
    cout << s2;

    return 0;

}