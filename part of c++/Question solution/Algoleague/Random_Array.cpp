#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int size, count = 0, a, num;
    cin >> size;
    vector<int> nums, check;

    for(int i = 0; i < size; i++){
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(),nums.end());

    check.push_back(nums[0]);

    for(int i = 0; i < size - 1; i++){
        a = check[i] - nums[i+1] + 1;
        count += a;
        check.push_back(nums[i+1] + a);
    }
    cout << count << endl;
}