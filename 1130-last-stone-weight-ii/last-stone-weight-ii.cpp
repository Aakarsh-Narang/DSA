class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;

    int solve(vector<int>& stones, int idx, int sum) {
        if (idx == stones.size()) {
            if (sum < 0) return INT_MAX;   // prune
            return sum;
        }

        if (dp[idx].count(sum))
            return dp[idx][sum];

        int add = solve(stones, idx + 1, sum + stones[idx]);
        int sub = solve(stones, idx + 1, sum - stones[idx]);

        return dp[idx][sum] = min(add, sub);
    }

    int lastStoneWeightII(vector<int>& stones) {
        return solve(stones, 0, 0);
    }
};