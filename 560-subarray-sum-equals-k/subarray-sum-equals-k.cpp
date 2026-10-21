class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int curr = 0, ans = 0;
        for(auto& n : nums){
            curr += n;
            ans += mp[curr-k];
            mp[curr]++;
        }

        return ans;
    }
};