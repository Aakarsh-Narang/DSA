class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int indx, int end){
        if(indx > end) return 0;

        if(dp[indx] != -1) return dp[indx];

        int rob = nums[indx] + solve(nums, dp, indx+2, end);
        int skip = solve(nums, dp, indx+1, end);

        return dp[indx] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); 
        int rob1 = solve(nums, dp, 2, n-2) + nums[0];

        dp.assign(n, -1);
        int rob2 = solve(nums, dp, 1, n-1);

        return max(rob1, rob2);  
    }
};