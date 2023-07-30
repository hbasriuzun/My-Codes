#include <bits/stdc++.h>
using namespace std;

void printPermutations(vector<vector<int>>& nums) {

    for (const auto& perm : nums) {
        for (const auto& num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
};

class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> permute(vector<int>& nums) {
        recursive_permutation(nums,0);
        return result;
    }

    void recursive_permutation(vector<int>& nums, int left){   
        int l = nums.size() -1;
        if(left == l){ 
            this->result.push_back(nums);
            return;
        }


        for(int right = left; right < l+1; ++right){
            swap(nums[right],nums[left]); 
            recursive_permutation(nums,left + 1);
            swap(nums[right],nums[left]);
        }
    }

};

int main(){
    Solution slm;
    vector<int> a = {1,2,3,4};
    slm.recursive_permutation(a,0);
    printPermutations(slm.result);
}