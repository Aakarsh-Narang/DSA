class Solution {
public:
    int solve(vector<int>& coins, vector<vector<int>>& dp, int indx, int amount){
        if(indx < 0 || amount < 0) return 0;
        if(amount == 0) return 1;
        if(dp[indx][amount] != -1) return dp[indx][amount];
        if(indx == 0){
            return (amount % coins[0]) == 0;
        }

        int take = solve(coins, dp, indx, amount - coins[indx]);
        int notTake = solve(coins, dp, indx-1, amount);

        return dp[indx][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return solve(coins, dp, n-1, amount);
    }
};