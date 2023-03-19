#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll count = 0, t, num, sum = 0;
    unordered_map <ll, ll> map;
    cin >> t;
    vector <ll> vec;
    while (t--)
    {
        cin >> num;
        map[num] = count++;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    for (ll i = 0; i < vec.size() - 1; i++)
    {
        sum += abs(map[vec[i]] - map[vec[i+1]]);
    }

    cout << sum;
}