#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>

#define endl "\n"
const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

map <char,int> mp;

int control(string s, int l, int r){
    bool isValid = true;
    map <char,int> mp2;

    for(int i=l;i<=r;i++){
        char c = s[i];
        mp2[s[i]]++;
        for(auto& it:mp2){
            if(it.first < c)
                it.second--;
        }
    }

    for(auto it:mp2){
        if(it.second > 0)
            return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = {"abcdeeeeeacebobbabdlskdfmakcbaalksdmcdbdubscynbcdabcodnka"}

    mp["a"]  = 2;
    mp["b"]  = 1;
    mp["c"]  = 1;
    mp["d"]  = 1;

    int min = INT_MAX 

    int l = 0, r = 0;

    while(r < s.size()){
        if(l == r){
            r++;
            continue;
        }
        if(control(s,i,j)){
            min_size = min(min_size, r-l+1);
            r++;
        }
        else{
            r++;
            continue;
        }
    }

    return 0;
}