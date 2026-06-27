class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp){
        if(i >= s1.size() && j >=s2.size()){
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j] == 1;

        bool takeFrom1, takeFrom2;
        if(s1[i] == s3[i+j])
            takeFrom1 = solve(s1, s2, s3, i+1, j, dp);
        if(s2[j] == s3[i+j])
            takeFrom2 = solve(s1, s2, s3, i, j+1, dp);

        return dp[i][j] = takeFrom1 || takeFrom2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(s3.size() != m+n) return false;

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        string curr = "";

        return solve(s1, s2, s3, 0, 0, dp);
    }
};