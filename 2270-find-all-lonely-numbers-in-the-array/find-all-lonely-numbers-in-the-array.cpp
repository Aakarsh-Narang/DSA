class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto& n : nums) mp[n]++;

        for(int i = 0; i < nums.size(); i++){
            if(!mp.count(nums[i]-1) && !mp.count(nums[i]+1) && mp[nums[i]] == 1)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};