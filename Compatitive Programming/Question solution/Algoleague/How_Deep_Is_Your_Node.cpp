#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>


using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int find_deph(vector <int>& v,int target,int deph){
    if(v[target-1] == 1){
        return deph;
    }  
    return find_deph(v,v[target-1],deph+1);
}

int main(){

    int n,target;
    cin >> n;
    vector <int> v(n+1);

    for(int i=1; i<n; i++){
        cin >> v[i];
    }

    cin >> target;
    if(target == 1)
        cout << 0 << endl;
    else
        cout << find_deph(v,target,1) << endl;
    return 0;
}