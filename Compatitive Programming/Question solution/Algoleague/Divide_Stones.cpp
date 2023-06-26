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
    int sum_dizi = 0;
    cin >> n;
    ll arr[n][n] = {0};
    ll dizi[n] = {0};
    for(int i=0; i<n; i++){
        cin >> dizi[i];
    }

    for(int i=0; i<n; i++){
        sum_dizi += dizi[i];
    }
    if(sum_dizi % 2 != 0){
        cout << "false" << endl;
        return 0;
    }
    sum_dizi /= 2;

        for(int i=0; i<n; i++){
            if(dizi[i] == sum_dizi){
                cout << "true" << endl;
                return 0;
            }
        }

        for(int i=0; i<n-1; i++){
            arr[0][i+1] = dizi[0] + dizi[i+1];
            if(arr[0][i+1] == sum_dizi){
                cout << "true" << endl;
                return 0;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=i+1; j<n; j++){
                arr[i][j] = arr[i-1][j] + dizi[i];
                if(arr[i][j] == sum_dizi){
                    
                    cout << "true" << endl;
                    return 0;
                }
            }
        }

    cout << "false" << endl;

    return 0;
}