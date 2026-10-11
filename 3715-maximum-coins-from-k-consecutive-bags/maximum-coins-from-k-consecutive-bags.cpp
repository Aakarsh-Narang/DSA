class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());

        int n = coins.size();
        long long ans = 0, curr = 0;

        int l = 0, r = 0;

        // Window starts at coins[l][0]
        while (l < n) {
            while (r < n && coins[r][1] <= coins[l][0] + k - 1) {
                curr += 1LL * (coins[r][1] - coins[r][0] + 1) * coins[r][2];
                r++;
            }

            if (r < n) {
                long long partial = 1LL *
                    max(0, coins[l][0] + k - coins[r][0]) * coins[r][2];

                ans = max(ans, curr + partial);
            }

            curr -= 1LL * (coins[l][1] - coins[l][0] + 1) * coins[l][2];
            l++;
        }

        // Window ends at coins[l][1]
            l = 0, r = 0, curr = 0;

        while (r < n) {
            curr += 1LL * (coins[r][1] - coins[r][0] + 1) * coins[r][2];

            while (l < r && coins[l][1] < coins[r][1] - k + 1) {
                curr -= 1LL * (coins[l][1] - coins[l][0] + 1) * coins[l][2];
                l++;
            }

            long long partial = 1LL *
                max(0, coins[r][1] - k - coins[l][0] + 1) * coins[l][2];

            ans = max(ans, curr - partial);

            r++;
        }

        return ans;
    }
};