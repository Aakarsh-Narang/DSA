class Solution {
public:
    const long long MOD = 1e9 + 7;
    int decode(string& s, int i, vector<int>& dp) {
        int n = s.size();
        if (i == n)   // Successfully decode the pattern without any breakage
            return 1;

        if (s[i] == '0') return dp[i] = 0;  // No decoding starts with 0

        if(dp[i] != -1) return dp[i];  // Memoization

        long long skip = 0, group = 0;

        if (s[i] == '*') {
            skip = (9LL * decode(s, i + 1, dp)) % MOD;

            // Grouping Cases
            if (i < n - 1) {
                if (s[i + 1] == '*') {
                    // 11 - 26 Except 20
                    group = (15LL * decode(s, i + 2, dp)) % MOD;
                } 
                else if(s[i+1] <= '6'){
                    // Can be both 1 or 2
                    group = (2LL * decode(s, i+2, dp)) % MOD;
                }
                else {
                    // Can be only 1
                    group = (1LL * decode(s, i + 2, dp)) % MOD;
                }
            }
        } 
        else {
            skip = decode(s, i + 1, dp);

            if (i < n - 1) {
                if (s[i] == '1') {
                    if (s[i + 1] == '*') {
                        // 11 - 19
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
        return dp[i] = ((skip % MOD) + (group % MOD)) % MOD;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return decode(s, 0, dp);
    }
};