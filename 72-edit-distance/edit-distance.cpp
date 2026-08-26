class Solution {
public:
    int solve(string& word1, string& word2, vector<vector<int>>& dp, int i, int j){
        if(i == word1.size()) return word2.size()-j;
        if(j == word2.size()) return word1.size()-i;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, dp, i+1, j+1);

        else{
            // Insert a char
            int insert = 1 + solve(word1, word2, dp, i, j+1);
            // Replace a char
            int replace = 1 + solve(word1, word2, dp, i+1, j+1);
            // Remove a char
            int remove = 1 + solve(word1, word2, dp, i+1, j);

            return dp[i][j] = min({insert, replace, remove});
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return solve(word1, word2, dp, 0, 0);
    }
};