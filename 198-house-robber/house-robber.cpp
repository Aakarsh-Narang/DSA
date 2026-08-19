class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int indx){
        if(indx >= nums.size()) return 0;

        if(dp[indx] != -1) return dp[indx];

        int rob = nums[indx] + solve(nums, dp, indx+2);
        int skip = solve(nums, dp, indx+1);

        return dp[indx] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(nums, dp, 0);
    }
};