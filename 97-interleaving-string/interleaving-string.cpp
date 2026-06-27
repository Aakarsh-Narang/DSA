class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp){
        if(i >= s1.size() && j >=s2.size()){
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j] == 1;

        bool takeFrom1 = false, takeFrom2 = false;
        if(i < s1.size() && s1[i] == s3[i+j])
            takeFrom1 = solve(s1, s2, s3, i+1, j, dp);
        if(j < s2.size() && s2[j] == s3[i+j])
            takeFrom2 = solve(s1, s2, s3, i, j+1, dp);

        return dp[i][j] = takeFrom1 || takeFrom2;
    }

    // Tabulation
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(s3.size() != m+n) return false;

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;

        for(int i = m; i >= 0; i--){
            for(int j = n; j>=0; j--){
                if(i == m && j == n) continue;

                bool takeFrom1 = 0, takeFrom2 = 0;
                if(i < m && s1[i] == s3[i+j])
                    takeFrom1 = dp[i+1][j];
                if(j < n && s2[j] == s3[i+j])
                    takeFrom2 = dp[i][j+1];

                dp[i][j] = takeFrom1 || takeFrom2;
            }
        }

        return dp[0][0];
    }
};