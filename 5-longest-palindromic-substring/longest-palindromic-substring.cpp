class Solution {
public:
    bool isPalindrome(string& s, int i, int j, vector<vector<int>>& dp){
        if(i >= j) return true;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j]) return dp[i][j] = 0;

        return dp[i][j] = isPalindrome(s, i+1, j-1, dp);
    }
    string longestPalindrome(string s) {
        int start = 0, len = 0, n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(j - i + 1 > len && isPalindrome(s, i, j, dp)){
                    start = i;
                    len = j - i + 1;
                } 
            }
        }
        return s.substr(start, len);
    }
};