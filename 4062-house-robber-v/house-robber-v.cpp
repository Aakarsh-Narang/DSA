class Solution {
public:
    typedef long long ll;
    ll loot(vector<int>& nums, vector<int>& colors, vector<ll>& dp, int indx){
        int n = nums.size();
        if(indx >= n) return 0;

        if(dp[indx] != -1) return dp[indx];

        ll rob = 0, notRob = 0;
        
        if(indx < n-1 && colors[indx] != colors[indx+1])
            rob = nums[indx] + loot(nums, colors, dp, indx+1);
        else
            rob = nums[indx] + loot(nums, colors, dp, indx+2);

        notRob = loot(nums, colors, dp, indx+1);

        return dp[indx] = max(rob, notRob);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<ll> dp(n, -1);

        return loot(nums, colors, dp, 0);
    }
};