class Solution {
public:
    int solve(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        if(i >= word1.size()) return word2.size() - j;
        if(j >= word2.size()) return word1.size() - i;

        if(dp[i][j] != -1) return dp[i][j];
        // Match
        if(word1[i] == word2[j]){
            return dp[i][j] = solve(word1, word2, i+1, j+1, dp);
        }
        // Mismatch
        else{
            // Delete
            int del = 1 + solve(word1, word2, i+1, j, dp);
            // Insert
            int ins = 1 + solve(word1, word2, i, j+1, dp);
            // Replace
            int rep = 1 + solve(word1, word2, i+1, j+1, dp);

            return dp[i][j] = min({del, ins, rep});
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));

        return solve(word1, word2, 0, 0, dp);
    }
};