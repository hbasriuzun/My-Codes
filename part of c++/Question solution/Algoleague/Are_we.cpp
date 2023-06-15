#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <queue>

using namespace std;
typedef long long ll;

int main(){
    ll n,q;
    cin >> n >> q;
    vector<ll> nums;
    ll num;
    nums.push_back(0);
    for(ll i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);
    }
    pair<ll,ll> query;
    queue<pair<ll,ll>> queries;
    for(ll i = 0; i < q; i++){
        cin >> query.first >> query.second;
        queries.push(query);
    }

    while (!queries.empty())
    {
        ll sum_left = 0, sum_right = 0;
        query = queries.front();
        queries.pop();
        ll sum_all = 0;
        ll start = query.first, end = query.second, mid = (start + end) / 2;
        for(ll i = start; i <= end; i++){
            sum_all += nums[i];
        }

        ll bolu2 = sum_all / 2;
        ll i = start;
        while(sum_left + nums[i] < bolu2){
            sum_left += nums[i];
            if(sum_left == bolu2){
                cout << i << endl;
                break;
            }
            i++;
        }
        
        if(sum_left == bolu2){
                continue;
        }
        ll left_difference = abs(sum_left - bolu2);
        ll right_difference = abs(sum_left - nums[i] - bolu2);

        if(left_difference > right_difference){
            cout << i  << endl;
        }else if(left_difference < right_difference){
            cout << i + 1<< endl;
        }
    }
    
    
}