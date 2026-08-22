class Solution {
public:
    bool isPalindrome(string& s, vector<vector<int>>& dp, int l, int r){
        if(l >= r) return true;

        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] != s[r]) return dp[l][r] = false;

        return dp[l][r] = isPalindrome(s, dp, l+1, r-1);
    }
    int countSubstrings(string s) {
        int sz = s.size(), ans = 0;

        vector<vector<int>> dp(sz, vector<int>(sz, -1));

        for(int i = 0; i < sz; i++){
            for(int j = i; j < sz; j++){
                if(isPalindrome(s, dp, i, j)) ans++;
            }
        }

        return ans;
    }
};