class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto& n : nums) mp[n]++;

        for(auto& n : nums){
            if(!mp.count(n-1) && !mp.count(n+1) && mp[n] == 1)
                ans.push_back(n);
        }

        return ans;
    }
};