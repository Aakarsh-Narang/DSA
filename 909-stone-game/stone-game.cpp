class Solution {
public:
    int play(vector<int>& nums, vector<vector<int>>& dp, int i, int j){
        if(i > j) return 0;
        if(i == j) return dp[i][j] = nums[i];

        if(dp[i][j] != -1) return dp[i][j];
        int takeLeft, takeRight;
        //Player 2 also has 2 choices so we change indices accordingly -> {takesleft, takesRight}
        takeLeft = nums[i] + min(play(nums, dp, i+2, j), play(nums, dp, i+1, j-1)); 
        takeRight = nums[j] + min(play(nums, dp, i+1, j-1), play(nums, dp, i, j-2));
        // min(Player2 Moves) -> Bcz player 2 will play the move that leaves smaller score for player1

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int alice = play(piles, dp, 0, n-1);
        int total = accumulate(piles.begin(), piles.end(), 0);
        int bob = total - alice;

        return alice >= bob;
    }
};