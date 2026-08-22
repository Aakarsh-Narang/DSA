class Solution {
public:
    int collect(vector<int>& coins, vector<vector<int>>& dp, int indx, long long curr, int& amount){
        if(curr == amount) return 0;
        if(curr > amount || indx == coins.size()) return 1e7;

        if(dp[indx][curr] != -1) return dp[indx][curr];

        long long take = 1e7;
        if(coins[indx] <= amount - curr)
            take = 1 + collect(coins, dp, indx, curr+coins[indx], amount);
        long long skip = collect(coins, dp, indx+1, curr, amount);

        return dp[indx][curr] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = collect(coins, dp, 0, 0, amount);

        if(ans >= 1e7) return -1;
        return ans; 
    }
};