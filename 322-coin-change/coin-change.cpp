class Solution {
public: 
    long long solve(vector<int>& coins, vector<vector<long long>>& dp, long long curr, int indx, int amount){
        if(indx == coins.size()){
            if(curr == amount) return 0;
            return 1e8;
        }
        if(curr > amount) return 1e8;
        if(dp[indx][curr] != -1) return dp[indx][curr];

        long long take = 1 + solve(coins, dp, curr + coins[indx], indx, amount);
        long long notTake = solve(coins, dp, curr, indx + 1, amount);

        return dp[indx][curr] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1, -1));

        int ans = solve(coins, dp, 0LL, 0, amount);

        if(ans >= 1e8) return -1;
        return ans;
    }
};