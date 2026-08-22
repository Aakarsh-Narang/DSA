class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int i) {
        if(dp[i] != -1)
            return dp[i];

        int ans = 1;  // include nums[i]

        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[j] > nums[i]) {
                ans = max(ans, 1 + solve(nums, dp, j));
            }
        }

        return dp[i] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans = max(ans, solve(nums, dp, i));
        }

        return ans;
    }
};