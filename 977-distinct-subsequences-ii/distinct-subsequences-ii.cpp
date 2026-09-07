class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        long long total = 0, prev = 0;
        vector<long long> dp(26, 0);

        for (auto& c : s) {
            c -= 'a';
            prev = (1 + total) % MOD;
            total = ((2LL * total)%MOD + 1 - dp[c] + MOD) % MOD;
            dp[c] = prev;
        }

        return (int)(total % MOD);
    }
};