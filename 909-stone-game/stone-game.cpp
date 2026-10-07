class Solution {
public:
    int play(vector<int>& stones, vector<vector<int>>& dp, int i, int j){
        if(i == j) return stones[i];

        if(dp[i][j] != -1) return dp[i][j];

        int takeLeft = stones[i] - play(stones, dp, i+1, j);
        int takeRight = stones[j] - play(stones, dp, i, j-1);

        return dp[i][j] = max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return play(piles, dp, 0, n-1);
    }
};
/* 
 * MINIMAX VIA SCORE DIFFERENCE (ZERO-SUM GAMES)
 * 
 * 1. DP State Concept: 
 *    dp[i][j] stores the maximum relative score difference (Current Player - Opponent) 
 *    obtainable from the remaining subarray [i...j], assuming optimal play by both.
 * 
 * 2. State Transition:
 *    takeLeft  = piles[i] - solve(i + 1, j)
 *    takeRight = piles[j] - solve(i, j - 1)
 *    dp[i][j]  = max(takeLeft, takeRight)
 * 
 * 3. The "Minus Sign" Logic (Perspective Flipping):
 *    Instead of tracking turns, we subtract the recursive call. This mathematically 
 *    deducts the opponent's optimal future advantage from our current pile choice.
 *    
 *    Algebraic Proof:
 *    Total Diff = (My Points Now + My Future Points) - (Opponent's Future Points)
 *    Total Diff = My Points Now - (Opponent's Future Points - My Future Points)
 *    
 *    Since (Opponent's Future Points - My Future Points) is exactly what the 
 *    opponent calculates when it becomes their turn, this simplifies to:
 *    Total Diff = My Points Now - solve(Remaining Board)
 * 
 * 4. Win Condition: 
 *    The initial call solve(0, n-1) returns Player 1's final net advantage over 
 *    Player 2. If result > 0, Player 1 accumulated more points and wins.
 */