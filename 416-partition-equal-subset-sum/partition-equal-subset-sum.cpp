class Solution {
public:
    bool solve(vector<int>& nums, vector<vector<int>>& dp, int indx, int sum, int target){
        if(sum == target) return true;
        if(indx == nums.size() || sum > target) return 0;

        if(dp[indx][sum] != -1) return dp[indx][sum];

        bool take = solve(nums, dp, indx+1, sum + nums[indx], target);
        bool notTake = solve(nums, dp, indx+1, sum, target);
        
        return dp[indx][sum] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(nums, dp, 0, 0, target);
    }
};