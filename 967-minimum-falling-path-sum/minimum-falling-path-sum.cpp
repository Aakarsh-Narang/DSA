class Solution {
public:
    int shortestPath(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(c < 0 || c >= matrix[0].size()){
            return 1e7;
        }
        if(dp[r][c] != INT_MAX) return dp[r][c];

        if(r == matrix.size()-1){
            return dp[r][c] = matrix[r][c];
        }

        int left = shortestPath(r+1, c-1, matrix, dp);
        int down = shortestPath(r+1, c, matrix, dp);
        int right = shortestPath(r+1, c+1, matrix, dp);

        return dp[r][c] = matrix[r][c] + min(left, min(down, right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++){
            ans = min(ans, shortestPath(0, i, matrix, dp));
        }

        return ans;
    }
};