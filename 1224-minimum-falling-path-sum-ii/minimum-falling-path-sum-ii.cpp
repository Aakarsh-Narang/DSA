class Solution {
public:
    int shortest_path(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid[0].size(), m = grid.size();
        if(c < 0 || c >= n) return INT_MAX;
        if(r == m-1) return dp[r][c] = grid[r][c];
        if(dp[r][c] != INT_MAX) return dp[r][c];

        int nc = INT_MAX;
        for(int i = 0; i < n; i++){
            if(i == c) continue;
            nc = min(nc, shortest_path(r+1, i, grid, dp));
        }

        return dp[r][c] = grid[r][c] + nc;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            ans = min(ans, shortest_path(0, i, matrix, dp));
        }
        return ans;
    }
};