class Solution {
public:
    bool isPalindrome(vector<vector<int>>& dp, string& s, int l, int r){
        if(l >= r) return true;

        if(dp[l][r] != -1) return dp[l][r];
        if(s[l] != s[r]) return dp[l][r] = false;

        return dp[l][r] = isPalindrome(dp, s, l+1, r-1);
    }
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, len = 1;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int l = 0; l < n; l++){
            for(int r = l+1; r < n; r++){
                if(r-l + 1 > len && isPalindrome(dp, s, l, r)){
                    len = r-l+1;
                    start = l;
                }
            }
        }

        return s.substr(start, len);
    }
};