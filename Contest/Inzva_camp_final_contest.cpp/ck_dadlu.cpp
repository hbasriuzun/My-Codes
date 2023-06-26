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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int count = 0,max_num = 0;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
        max_num = max(max_num,v[i]);
    }
    
    for (size_t i = 0; i < max_num ;i++ )
    {
        for(int j=0;j<n;j++){
            if(v[j] >= i){
                continue;
            }
            
        }
    }
    
    cout << count << endl;


    return 0;
}