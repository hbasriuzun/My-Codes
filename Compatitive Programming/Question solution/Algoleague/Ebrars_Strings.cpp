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
    
    string s1,s2;
    cin >> s1 >> s2;

    int s1_size = s1.size();
    int s2_size = s2.size();

    int dp[s1_size+1][s2_size+1];

    for(int i=0;i<=s1_size;i++){
        for(int j=0;j<=s2_size;j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout << dp[s1_size][s2_size] << endl;

    return 0;
}