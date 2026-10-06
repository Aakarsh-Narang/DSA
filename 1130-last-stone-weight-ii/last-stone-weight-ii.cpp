class Solution {
public:
    int solve(vector<int>& stones, vector<vector<int>>& dp, int indx, int& totalSum, int curr){
        int n = stones.size();
        if(indx == n) return abs(totalSum - 2 * curr);

        if(dp[indx][curr] != -1) return dp[indx][curr];

        int take = solve(stones, dp, indx+1, totalSum, curr + stones[indx]);
        int notTake = solve(stones, dp, indx+1, totalSum, curr);

        return dp[indx][curr] = min(take, notTake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), totalSum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

        return solve(stones, dp, 0, totalSum, 0);
    }
};