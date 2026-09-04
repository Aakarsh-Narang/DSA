class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;

        for(auto& n : nums) mp[n]++;

        for(auto& n : nums){
            if(mp[n-k] > 0){
                ans += (mp[n] * mp[n-k]);
            }
            if(mp[n+k] > 0){
                ans += (mp[n] * mp[n+k]);
            }
            mp[n] = 0;
        }

        return ans;
    }
};