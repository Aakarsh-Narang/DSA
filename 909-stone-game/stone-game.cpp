class Solution {
public:
    int play(vector<int>& nums, vector<vector<int>>& dp, int i, int j){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int takeLeft, takeRight;
        // Player1 tries to maximise the score
        // After taking left or right, we check both cases if 2nd player took left or right in the next turn and take max of our turns further
        takeLeft = nums[i] + max(play(nums, dp, i+2, j), play(nums, dp, i+1, j-1));
        takeRight = nums[j] + max(play(nums, dp, i+1, j-1), play(nums, dp, i, j-2));

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