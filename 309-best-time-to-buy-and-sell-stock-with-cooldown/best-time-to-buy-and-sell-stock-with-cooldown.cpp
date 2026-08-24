class Solution {
public:
    int solve(vector<int>& prices, vector<vector<int>>& dp, int indx, int holding){
        if(indx >= prices.size()) return 0;

        if(dp[indx][holding] != -1) return dp[indx][holding];

        if(holding){
            int hold = solve(prices, dp, indx+1, holding);
            int sell = prices[indx] + solve(prices, dp, indx+2, 0);

            return dp[indx][holding] = max(hold, sell);
        }
        else{
            int wait = solve(prices, dp, indx+1, holding);
            int buy = -prices[indx] + solve(prices, dp, indx+1, 1);

            return dp[indx][holding] = max(wait, buy);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(prices, dp, 0, 0);
    }
};