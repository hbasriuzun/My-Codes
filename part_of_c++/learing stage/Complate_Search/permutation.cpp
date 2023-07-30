#include <iostream>
#include <vector>

using namespace std;

void permuteRecursive(vector<int>& nums, int start, vector<vector<int>>& result) {
    int l = nums.size() - 1;
    if (start == l) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i <= l; ++i) {
        swap(nums[start], nums[i]);
        permuteRecursive(nums, start + 1, result);
        swap(nums[start], nums[i]); // Geri almak için tekrar swap işlemi yapılıyor
    }
}

void printPermutations(vector<int>& nums) {
    vector<vector<int>> result;
    permuteRecursive(nums, 0, result);

    for (const auto& perm : result) {
        for (const auto& num : perm) {
            cout << num;
        }
        cout << endl;
    }
}

int main() {
    vector<int> nums = {1, 2, 3};

    cout << "Permutasyonlar:" << endl;
    printPermutations(nums);

    return 0;
}
