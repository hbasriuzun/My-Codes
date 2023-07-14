class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> mp;
        using pair_type = decltype(mp)::value_type;

        int n = nums.size();
        for(int i = 0; i < n;i++){
            if(mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 1;
            else
                mp[nums[i]]++;

        }
        
    cout << mp[1];
    std::map<int,int>::iterator best
        = std::max_element(mp.begin(),mp.end(),[] (const std::pair<int,int>& a, const    std::pair<int,int>& b)->bool{ return a.second < b.second; } );

    return best->first ;

    }
};