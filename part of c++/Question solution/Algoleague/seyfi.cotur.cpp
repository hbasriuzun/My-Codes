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

int main(){

    int n,s1,s2,s3;
    cin >> n;

    vector <vector<int>> v(n+1);

    for(int i=1; i<n; i++){
        int num1,num2;
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }

    cin >> s1 >> s2 >> s3;

    


    return 0;
}