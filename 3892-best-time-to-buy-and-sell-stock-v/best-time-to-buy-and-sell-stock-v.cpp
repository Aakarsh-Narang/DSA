class Solution {
public:
    typedef long long ll;
    ll solve(vector<int>& prices, vector<vector<vector<ll>>>& dp, int indx, int state, int rem){
        if(indx == prices.size() || rem == 0){
            if(state != 0) return -1e15;
            return 0;
        }

        if(dp[indx][rem][state] != LLONG_MIN) return dp[indx][rem][state];

        ll hold = 1LL* solve(prices, dp, indx+1, state, rem);
        
        // Neutral State
        if(state == 0){
            ll sell = prices[indx] + 1LL* solve(prices, dp, indx+1, 2, rem);
            ll buy = -prices[indx] + 1LL* solve(prices, dp, indx+1, 1, rem);

            return dp[indx][rem][state] = max({hold, buy, sell});  
        }
        // Long Transaction (Normal Buy -> Sell)
        else if(state == 1){
            ll sell = prices[indx] + 1LL* solve(prices, dp, indx+1, 0, rem-1);

            return dp[indx][rem][state] = max(hold, sell);
        } 
        // Short Transaction
        else{
            ll buy = -prices[indx] + 1LL* solve(prices, dp, indx+1, 0, rem-1);

            return dp[indx][rem][state] = max(hold, buy);  
        }
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // dp state : [indx][rem][state]
        // States: 0 -> Neutral  1-> Long  2-> Short
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k+1, vector<ll>(3, LLONG_MIN)));

        return solve(prices, dp, 0, 0, k);
    }
};