class Solution {
public:
        // Tabulation
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        // Mark 1 till no obstacle blocks the straight path
        for(int i = 0; i < rows; i++){
            if(mat[i][0] == 1) break;
            dp[i][0] = 1;
        }
        for(int i = 0; i < cols; i++){
            if(mat[0][i] == 1) break;
            dp[0][i] = 1;
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {

                if (mat[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    int up = dp[i - 1][j];
                    int left = dp[i][j - 1];
                    dp[i][j] = (up + left);
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
