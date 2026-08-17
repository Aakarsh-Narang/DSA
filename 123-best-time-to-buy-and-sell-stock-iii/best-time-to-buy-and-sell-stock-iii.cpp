class Solution {
public:
    int trade(vector<vector<vector<int>>>& dp, vector<int>& prices, int i, int buy, int rem){
        if(i >= prices.size() || rem == 0) return 0;

        if(dp[i][buy][rem] != -1) return dp[i][buy][rem];

        if(buy == 0){
            int hold = trade(dp, prices, i+1, 0, rem);
            int newBuy = trade(dp, prices, i+1, 1, rem) - prices[i];
            return dp[i][buy][rem] = max(hold, newBuy);
        }
        else{
            int hold = trade(dp, prices, i+1, 1, rem);
            int sell = trade(dp, prices, i+1, 0, rem-1) + prices[i];
            return dp[i][buy][rem] = max(hold, sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return trade(dp, prices, 0, 0, 2);
    }
};