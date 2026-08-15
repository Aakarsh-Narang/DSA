class Solution {
public:
    const long long MOD = 1e9 + 7;
    int decode(string& s, int i, vector<int>& dp) {
        int n = s.size();
        if (i == n)
            return 1;

        if (s[i] == '0') return dp[i] = 0;

        if(dp[i] != -1) return dp[i];

        long long skip = 0, group = 0;
        if (s[i] == '*') {
            skip = (9LL * decode(s, i + 1, dp)) % MOD;
            if (i < n - 1) {
                if (s[i + 1] == '*') {
                    group = (15LL * decode(s, i + 2, dp)) % MOD;
                } 
                else if(s[i+1] <= '6'){
                    group = (2LL * decode(s, i+2, dp)) % MOD;
                }
                else {
                    group = (1LL * decode(s, i + 2, dp)) % MOD;
                }
            }
        } 
        else {
            skip = decode(s, i + 1, dp);
            if (i < n - 1) {
                if (s[i] == '1') {
                    if (s[i + 1] == '*') {
                        group = (9LL * decode(s, i + 2, dp)) % MOD;
                    } else {
                        group = decode(s, i + 2, dp) % MOD;
                    }
                }
                if (s[i] == '2') {
                    if (s[i + 1] == '*') {
                        group = (6LL * decode(s, i + 2, dp)) % MOD;
                    } 
                    else if (s[i + 1] <= '6') {
                        group = decode(s, i + 2, dp) % MOD;
                    }
                }
            }
        }
        return dp[i] = (skip % MOD + group % MOD) % MOD;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return decode(s, 0, dp);
    }
};