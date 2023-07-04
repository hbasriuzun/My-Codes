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
    
    int n,croc,fruit,max_num=0;
    cin >> n >> croc >> fruit;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }
     int r=0,l=0;
    while(l != v.size()){
        if(v[r] == 0){
            r++;
            max_num = max(max_num,r-l);
        }
        
                else if(v[r] == 1 && croc > 0){
                    r++;
                    max_num = max(max_num,r-l);
                    croc--;
                }
                else if(v[r] == 2 && fruit > 0){
                    r++;
                    max_num = max(max_num,r-l);
                    fruit--;
                }
            else if(v[l] == 1){
                l++;
                croc++;
            }else if(v[l] == 2){
                l++;
                fruit++;
            }else{
                l++;
            }

            if(r == v.size()){
                break;
            }
            
        
    }
    cout << max_num << endl;
    return 0;
}