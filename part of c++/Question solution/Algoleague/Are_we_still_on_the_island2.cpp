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
    int n,q;
    cin >> n >> q;
    vector<int> nums;
    int num;
    nums.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);
    }
    pair<int,int> query;
    queue<pair<int,int>> queries;
    for(int i = 0; i < q; i++){
        cin >> query.first >> query.second;
        queries.push(query);
    }

    while (!queries.empty())
    {
        int sum_left = 0, sum_right = 0;
        query = queries.front();
        queries.pop();
        int start = query.first, end = query.second, mid = (start + end) / 2;
        for(int i = start; i <= mid; i++){
            sum_left += nums[i];
        }
        for(int i = mid + 1; i <= end; i++){
            sum_right += nums[i];
        }
        int previous_differecce = abs(sum_left - sum_right);
        
    }
    
    
}