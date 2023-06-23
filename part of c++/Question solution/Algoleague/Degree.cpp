#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){

    int n,m,num1,num2;
    cin >> n >> m;

    vector <vector<int>> v(n + 1);

    for(int i=0; i<m; i++){
        cin >> num1 >> num2;
        v[num1].push_back(num2);
    }

    for (int  i = 1; i < n; i++)
    {
        cout << v[i].size() << " ";
    }
    

    return 0;
}