#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    if (nums.size() == 0) return 0;
        else if(nums.size() == 1) return 1;
        
        map<int,bool> check;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                check[nums[i] + 1000000000] = true;
            else if(nums[i] == 0)
                check[1000000000] = true;
            else if(nums[i] < 0)
                check[nums[i] + 1000000000] = true;
        }
         int count = 0, max_count = 0, i = 0;

        if(check.size() == 1) return 1;
         for(auto it = check.begin(); i != nums.size()-1; i++){
             if(it->first + 1 == (++it)->first){
                count++;
                if(count == 1) count++;

             }else {
                 max_count = max(count,max_count);
                 count = 0;
             }
         }
    max_count = max(count,max_count);
    cout << max_count << endl;
    sort(nums.begin(),nums.end());
    return 0;
}