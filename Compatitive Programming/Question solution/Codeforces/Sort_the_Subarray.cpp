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
#include <unordered_set>

#define endl "\n"
const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n,l=1,r=0;
        cin >> n;
        n++;
        vector<int> a(n), b(n);
        for(int i = 1; i < n; i++){
            cin >> a[i];
        }
        for(int i = 1; i < n; i++){
            cin >> b[i];
        }
        a[0] = N;
        b[0] = N;
        for(int i=1; i < n; i++){
            if(a[i] != b[i]){
                l = i;
                for(int j = i; j < n; j--){
                    if(b[j] >=  b[j-1]){
                        l = j-1;
                    }else{
                        break;
                    }
                }
                for(int j = i; j < n; j++){
                    if(b[j] <= b[j+1]){
                        r = j+1;
                    }else{
                        break;
                    }
                }
            }
            if(r != 0){
                cout << l << " " << r << endl;
                break;
            }
        }

    }


    return 0;
}