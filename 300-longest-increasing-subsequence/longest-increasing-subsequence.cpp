class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int idx, int prevIdx){
        if(idx >= nums.size()) return 0;

        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];

        int take = 0;
        if(prevIdx == -1 || nums[prevIdx] < nums[idx]){
            take = 1 + solve(nums, dp, idx+1, idx);
        }
        int notTake = solve(nums, dp, idx+1, prevIdx);

        return dp[idx][prevIdx + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(nums, dp, 0, -1);
    }
};