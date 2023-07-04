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
    int max_num = 1;
    int n;
    int a;
    cin >> n;
    cin >> a;
    vector<pair<int,int>> arr(n);
    arr[0].first = a;
    arr[0].second = 1;

    for(int i=1;i<n;i++){
        cin >> a;
        arr[i].first = a;
        arr[i].second = 1;
        for(int j=i;j>0;){
            j--;
            if(arr[j].first <= arr[i].first)
                arr[i].second = max(arr[j].second + 1,arr[i].second);
            
            max_num = max(max_num,arr[i].second);
            
        }
    }
    cout << max_num << endl;
    return 0;
}