class Solution {
public:
    int subarrays(vector<int>& nums, int k){
        if(k <= 0) return 0;
        int ans = 0, distinct = 0;
        unordered_map<int, int> mp;
        int l = 0, r = 0, n = nums.size();

        while(r < n){
            if(mp[nums[r]] == 0){
                distinct++;
            }
            mp[nums[r]]++;

            while(l < r && distinct > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    distinct--;
                }
                l++;
            }

            ans += r - l + 1;
            r++;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrays(nums, k) - subarrays(nums, k-1);
    }
};