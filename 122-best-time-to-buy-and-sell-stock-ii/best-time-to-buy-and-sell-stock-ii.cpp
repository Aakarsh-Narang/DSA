class Solution {
public:
    int trade(vector<int>& prices, vector<vector<int>>& dp, int indx, bool holding){
        if(indx == prices.size()) return 0;
        
        if(dp[indx][holding] != -1) return dp[indx][holding];
        if(holding){
            int sell = prices[indx] + trade(prices, dp, indx+1, 0);
            int hold = trade(prices, dp, indx+1, 1);

            return dp[indx][holding] = max(sell, hold);
        }
        else{
            int buy = -prices[indx] + trade(prices, dp, indx+1, 1);
            int hold = trade(prices, dp, indx+1, 0);

            return dp[indx][holding] = max(buy, hold);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));  // {indx, holding}

        return trade(prices, dp, 0, 0);
    }
};