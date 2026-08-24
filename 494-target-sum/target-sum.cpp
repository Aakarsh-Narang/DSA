class Solution {
public:
    int solve(vector<int>& nums, vector<unordered_map<int, int>>& dp, int indx, int sum, int target){
        if(indx == nums.size()){
            if(sum == target) return 1;
            return 0;
        }

        if(dp[indx].count(sum)) return dp[indx][sum];

        int add = solve(nums, dp, indx+1, sum+nums[indx], target);
        int sub = solve(nums, dp, indx+1, sum-nums[indx], target);

        return dp[indx][sum] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);

        return solve(nums, dp, 0, 0, target);
    }
};