#include <bits/stdc++.h>

const int N = 1e5+5;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll find(ll stair, ll x, ll y){
    if(stair == 0)
        return 1;
    else if(stair < 0)
        return 0;
    return find(stair - x, x, y) + find(stair - y, x, y);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll stair, x, y;
    cin >> stair >> x >> y;

    auto start = std::chrono::high_resolution_clock::now();

    cout << find(stair, x, y) << endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Program çalışma süresi: " << duration.count() << " saniye." << std::endl;
    return 0;
}