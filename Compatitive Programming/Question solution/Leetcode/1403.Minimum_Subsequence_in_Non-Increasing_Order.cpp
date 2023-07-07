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

    vector<int> minSubsequence(vector<int> nums) {
        int sum = 0, temp = 0; 
        sort(nums.begin(), nums.end()); 
        vector<int> res; 
        int k = nums.size()-1; 

        for(int i=0; i<nums.size(); i++) 
            sum += nums[i]; 
        
        while(temp <= sum - temp){
            temp += nums[k];  
            res.push_back(nums[k]); 
            k--;
        }
        return res; 
        
    }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(auto s: minSubsequence({4,3,10,9,8}))
        cout << s << " ";
    cout << endl;

    return 0;
}