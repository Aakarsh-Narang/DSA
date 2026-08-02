class Solution {
public:
    int play(vector<int>& nums, vector<vector<vector<int>>>& dp, int i, int j, bool isPlayer1){
        if(i > j) return 0;

        if(dp[i][j][isPlayer1] != -1) return dp[i][j][isPlayer1];

        int takeLeft, takeRight;
        // Player1 tries to maximise the score
        if(isPlayer1){
            takeLeft = nums[i] + play(nums, dp, i+1, j, 0);
            takeRight = nums[j] + play(nums, dp, i, j-1, 0);
            return dp[i][j][1] = max(takeLeft, takeRight);
        }
        // Player2 tries to minimize the score
        else{
            takeLeft = play(nums, dp, i+1, j, 1);
            takeRight = play(nums, dp, i, j-1, 1);
            return dp[i][j][0] = min(takeLeft, takeRight);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2,-1)));

        int score1 = play(piles, dp, 0, n-1, 1);
        int total = accumulate(piles.begin(), piles.end(), 0);
        int score2 = total - score1;

        return score1 >= score2;
    }
};