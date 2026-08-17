class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& prices, int indx, int holding){
        if(indx == prices.size()) return 0;

        if(dp[indx][holding] != -1) return dp[indx][holding];

        if(holding){  // Already possessing a stock
            int skip = solve(dp, prices, indx+1, 1);
            int sell = prices[indx] + solve(dp, prices, indx+1, 0);

            return dp[indx][holding] = max(skip, sell);
        }
        else{  // No possession, free to buy
            int skip = solve(dp, prices, indx+1, 0);
            int buy = -prices[indx] + solve(dp, prices, indx+1, 1);

            return dp[indx][holding] = max(skip, buy);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(dp, prices, 0, 0);
    }
};