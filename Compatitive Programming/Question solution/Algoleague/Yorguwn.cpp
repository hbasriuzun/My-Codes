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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    pair<set<int>,int> v[n];

    for(int i=0;i<n;i++){
        cin >> v[i].second;
    }
    int i=1;
    v[0].first.insert(0);
    v[i].first.insert(abs(v[i-1].second - v[i].second)); 
    
    for(i=2; i<n; i++){
        v[i].first.insert(abs(v[i-1].second - v[i].second)+*(v[i-1].first.cbegin()));
        v[i].first.insert(abs(v[i-2].second - v[i].second)+*(v[i-2].first.cbegin())); 
    }

    cout << *(v[n-1].first.cbegin()) << endl;

    return 0;
}