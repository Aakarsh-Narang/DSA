class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            dp[m-1][i] = matrix[m-1][i];
        }

        for(int i = m-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int nc = INT_MAX;
                for(int k = 0; k < n; k++){
                    if(j == k) continue;
                    nc = min(nc, dp[i+1][k]);
                }
                dp[i][j] = matrix[i][j] + nc;
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};