class Solution {
public:
    int solve(int n, int curr, vector<bool>& used) {
        if (curr == n + 1) return 1;

        int total = 0;

        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            if (i % curr != 0 && curr % i != 0) continue;

            used[i] = true;
            total += solve(n, curr + 1, used);
            used[i] = false;
        }

        return total;
    }

    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        return solve(n, 1, used);
    }
};