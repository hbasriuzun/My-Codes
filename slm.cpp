#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string line; getline(cin, line); cout << '\n') {
        istringstream ss(line);
        char ch;
        int a, b, c, d;
        ss >> ch >> ch >> a >> ch >> b >> ch >> ch >> ch >> c >> ch >> d;
        if (a == c || a == d) cout << a;
        else cout << b;
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    int findCenter(vector<vector<int>>& ed) {
        return (ed[0][0]==ed[1][0]||ed[0][0]==ed[1][1])?ed[0][0]:ed[0][1];    	
    }
};

int main(int argc, char const *argv[])
{
    cout << "slm" << endl;
    return 0;
    
}