class Solution {
public:
    const int INF = 1e8;
    int solve(vector<int>& coins, vector<vector<int>>& dp, int idx, int amount){
        if(amount == 0) return 0;
        if(idx==0){
            if(amount % coins[0] == 0) return amount/coins[0];
            return INF;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int take = INF, notTake = solve(coins, dp, idx-1, amount);
        if(coins[idx]<=amount)
            take=1 + solve(coins, dp, idx, amount-coins[idx]);

        return dp[idx][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

        int ans = solve(coins, dp, coins.size()-1, amount);
        return ans>=INF ? -1 : ans;
    }
};