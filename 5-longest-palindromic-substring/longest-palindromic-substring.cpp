class Solution {
public:
    bool isPalindrome(string& s, vector<vector<int>>& dp, int l, int r){
        if(l >= r) return true;

        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] != s[r]) return dp[l][r] = 0;

        return dp[l][r] = isPalindrome(s, dp, l+1, r-1);
    }
    string longestPalindrome(string s) {
        int sz = s.size(), start = 0, len = 1;
        vector<vector<int>> dp(sz, vector<int>(sz, -1));

        for(int l = 0; l < sz; l++){
            for(int r = 0; r < sz; r++){
                if(r - l + 1 > len && isPalindrome(s, dp, l, r)){
                    start = l;
                    len = r-l+1;
                }
            }
        }

        return s.substr(start, len);
    }
};