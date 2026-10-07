class Solution {
public:
    int play(vector<int>& stones, vector<vector<int>>& dp, int i, int j){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int takeLeft = stones[i] + min(play(stones, dp, i+2, j), play(stones, dp, i+1, j-1));
        int takeRight = stones[j] + min(play(stones, dp, i+1, j-1), play(stones, dp, i, j-2));

        return dp[i][j] = max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int score1 = play(piles, dp, 0, n-1);
        int total = accumulate(piles.begin(), piles.end(), 0);
        int score2 = total - score1;

        return score1 >= score2;
    }
};