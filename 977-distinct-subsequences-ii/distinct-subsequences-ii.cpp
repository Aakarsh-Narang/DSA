class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        long long tot = 0, prev = 0, dp[26]{};

        for (auto& c : s) {
            c -= 'a';
            prev = (1 + tot) % MOD;
            tot = ((2LL*tot)%MOD + 1 - dp[c] + MOD) % MOD;
            dp[c] = prev;
        }

        return (int)(tot % MOD);
    }
};