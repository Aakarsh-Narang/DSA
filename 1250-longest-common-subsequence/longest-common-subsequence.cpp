class Solution {
public:
    int solve(string& text1, string& text2, vector<vector<int>>& dp, int i, int j){
        if(i >= text1.size() || j >= text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int take01 = 0, take10= 0;
        if(text1[i] == text2[j]) return dp[i][j] = 1 + solve(text1, text2, dp, i+1, j+1);

        take01 = solve(text1, text2, dp, i, j+1);
        take10 = solve(text1, text2, dp, i+1, j);

        return dp[i][j] = max(take10, take01);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size(), s2 = text2.size();
        vector<vector<int>> dp(s1, vector<int>(s2, -1));

        return solve(text1, text2, dp, 0, 0);
    }
};