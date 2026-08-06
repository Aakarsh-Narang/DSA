class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& mat, int r, int c, int m, int n){
        if(r < 0 || c < 0) return 0;

        if(dp[r][c] != -1) return dp[r][c];
        if(mat[r][c] == 1) return dp[r][c] = 0;
        if(r == 0 && c == 0) return dp[r][c] = mat[0][0] != 1;
        return dp[r][c] = solve(dp, mat, r-1, c, m, n) + solve(dp, mat, r, c-1, m, n);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(dp, obstacleGrid, m-1, n-1, m, n);
    }
};