class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int i, int j){
        int n = nums.size();

        if(i < 0 || j >= n || i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int currCost, totalCost = 0;
        int leftVal = i <= 0 ? 1 : nums[i-1];
        int rightVal = j >= n-1 ? 1 : nums[j+1];

        for(int k = i; k <= j; k++){
            int currCost = leftVal * nums[k] * rightVal;
            int left = solve(nums, dp, i, k-1);
            int right = solve(nums, dp, k+1, j);
            totalCost = max(totalCost, left + currCost + right);
        }

        return dp[i][j] = totalCost;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(nums, dp, 0, n-1);
    }
};