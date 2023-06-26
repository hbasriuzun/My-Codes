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

vector <int> v[100001];
int n;

ll bfs(int cur,int pan,int dep){
    ll sum = 0;
    bool flag = true;

    for(auto i:v[cur]){
        if(i == pan){
            continue;
        }

        sum += bfs(i,cur,dep+1);
        flag = false;
    }
    if(flag){
        sum += 2*dep;
    }
    return sum;
}

int main(){
    int num1,num2;
    cin >> n;

    for(int i=1; i<n; i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }

    cout << bfs(1,0,0) << endl;

    return 0;
}