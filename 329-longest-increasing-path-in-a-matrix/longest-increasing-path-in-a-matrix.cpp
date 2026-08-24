class Solution {
public:
    int longestPath(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c){
        if(dp[r][c] != -1) return dp[r][c];

        int dir[5] = {-1, 0, 1, 0, -1}, m = matrix.size(), n = matrix[0].size(), ans = 0;

        for(int i = 0; i < 4; i++){
            int nr = r + dir[i], nc = c + dir[i+1];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if(matrix[nr][nc] > matrix[r][c])
                ans = max(ans, longestPath(matrix, dp, nr, nc));            
        }

        return dp[r][c] = 1 + ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, longestPath(matrix, dp, i, j));
            }
        }

        return ans;
    }
};