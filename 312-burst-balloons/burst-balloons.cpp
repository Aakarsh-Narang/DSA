class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& nums, int i, int j){
        if(i < 0 || j >= nums.size() || i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int currCost, totalCost=0;
        int leftVal = (i > 0) ? nums[i-1] : 1;
        int rightVal = (j < nums.size()-1) ? nums[j+1] : 1;

        // K is the last baloon that will be popped
        // Before that i...k-1 & k+1...j will be popped
        for (int k = i; k <= j; k++) {
            int currCost = leftVal * nums[k] * rightVal;
            int left = solve(dp, nums, i, k-1);
            int right = solve(dp, nums, k+1, j);
            totalCost = max(totalCost, left+currCost+right);
        }
        
        return dp[i][j] = totalCost;
    }
    int maxCoins(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n , -1));

        return solve(dp, nums, 0, n-1);
    }
};