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

    int arr[n][n],arr2[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    arr2[0][0] = arr[0][0];

    for(int i=1;i<n;i++){
        arr2[0][i] = arr2[0][i-1] + arr[0][i];
    }
    for(int i=1;i<n;i++){
        arr2[i][0] = arr2[i-1][0] + arr[i][0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            arr2[i][j] =  min(arr2[i-1][j] + arr[i][j], arr2[i][j-1] + arr[i][j]);
        }
    }
    cout << arr2[n-1][n-1] << endl;
    return 0;
}