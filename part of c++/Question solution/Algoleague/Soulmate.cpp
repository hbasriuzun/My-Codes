#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ll size, divisible;
    cin >> size >> divisible;
    vector<ll> nums;
    ll num;
    for(ll i = 0; i < size; i++){
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());

    

}