class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> mp;
        int l = 0, r = 0, ans = 0, n = nums.size();

        while(r < n){
            mp[nums[r]]++;
            while(mp.size() && abs(mp.begin()->first - mp.rbegin()->first) > limit){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
                
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};