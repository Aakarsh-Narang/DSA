class Solution {
public:
    int solve(int n, int curr, int mask, vector<int>& dp) {
        if (curr == n + 1) return 1;

        if (dp[mask] != -1) return dp[mask];

        int total = 0;

        for (int num = 1; num <= n; num++) {
            int bit = 1 << (num - 1);

            if (mask & bit) continue;
            if (num % curr != 0 && curr % num != 0) continue;

            total += solve(n, curr + 1, mask | bit, dp);
        }

        return dp[mask] = total;
    }

    int countArrangement(int n) {
        vector<int> dp(1 << n, -1);
        return solve(n, 1, 0, dp);
    }
};