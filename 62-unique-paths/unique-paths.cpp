class Solution {
public:
    int solve(vector<vector<int>>& dp, int r, int c, int m, int n){
        if(r < 0 || c < 0 || r >= m || c >= n) return 0;

        if(dp[r][c] != -1) return dp[r][c];
        if(r == 0 || c == 0) return 1;

        return dp[r][c] = solve(dp, r-1, c, m, n) + solve(dp, r, c-1, m, n);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(dp, m-1, n-1, m, n);
    }
};