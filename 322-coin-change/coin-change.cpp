class Solution {
public: 
    const int INF = 1e8;
    int solve(vector<int>& coins, vector<vector<int>>& dp, int curr, int indx, int amount){
        if(indx == -1){
            if(curr == amount) return 0;
            return INF;
        }
        if(curr > amount) return INF;

        if(dp[indx][curr] != -1) return dp[indx][curr];

        if((amount - curr) % coins[indx] == 0) return dp[indx][curr] = (amount - curr) / coins[indx];

        int take = 1 + solve(coins, dp, curr + coins[indx], indx, amount);
        int notTake = solve(coins, dp, curr, indx-1, amount);

        return dp[indx][curr] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = solve(coins, dp, 0, n-1, amount);

        if(ans >= INF) return -1;
        return ans;
    }
};