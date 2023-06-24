#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

#define int long long

bool find_num(vector <int> v, int num){
    for(int i=0; i<v.size(); i++){
        if(v[i] == num)
            return true;
    }
    return false;
}

int32_t main(){

    int n,m,num1,num2;
    cin >> n >> m;
    set <pair<int,int>> v2;
    vector <vector <int>> v(n+1);

    for(int i=0; i<m; i++){ 
        cin >> num1 >> num2;
        if(num1 == num2)
            continue;
        v[num1].push_back(num2);
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<v[i].size(); j++){
            for(int k=0; k<v[v[i][j]].size(); k++){
                if(v[v[i][j]][k] == i){
                    v2.insert(make_pair(i,v[i][j]));
                    v[v[i][j]].erase(v[v[i][j]].begin() + k);
                    k--;
                }
            }
        }
    }

    cout << v2.size() << endl;


    for(auto p: v2){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}