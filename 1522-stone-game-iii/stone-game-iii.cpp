class Solution {
public:
    // dp[i][turn] -> turn 0 is Alice, turn 1 is Bob

    int solve(vector<int>& stones, vector<vector<int>>& dp, int i, int turn) {
        if (i >= stones.size()) {
            return 0; // No more stones, score added is 0
        }

        // Return memoized result
        if (dp[i][turn] != -1) {
            return dp[i][turn];
        }

        int n = stones.size();
        
        if (turn == 0) { 
            // ALICE'S TURN: Maximize her own score
            int take1, take2 = INT_MIN, take3 = INT_MIN;
            
            // Alice takes 1 stone, next turn is Bob's (1)
            take1 = stones[i] + solve(stones, dp, i + 1, 1);
            
            if (i < n - 1) { // Alice takes 2 stones
                take2 = stones[i] + stones[i + 1] + solve(stones, dp, i + 2, 1);
            }
            
            if (i < n - 2) { // Alice takes 3 stones
                take3 = stones[i] + stones[i + 1] + stones[i + 2] + solve(stones, dp, i + 3, 1);
            }
            
            return dp[i][turn] = max(take1, max(take2, take3));
        } 
        else { 
            // BOB'S TURN: Minimize Alice's score
            int take1, take2 = INT_MAX, take3 = INT_MAX;
            
            // Bob takes 1 stone. Alice gets 0 points for this stone. Next turn is Alice's (0)
            take1 = solve(stones, dp, i + 1, 0);
            
            if (i < n - 1) { // Bob takes 2 stones
                take2 = solve(stones, dp, i + 2, 0);
            }
            
            if (i < n - 2) { // Bob takes 3 stones
                take3 = solve(stones, dp, i + 3, 0);
            }
            
            return dp[i][turn] = min(take1, min(take2, take3));
        }
    }

    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();
        
        // Initialize 2D DP table: n rows, 2 columns. Filled with -1.
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Start from index 0, turn 0 (Alice)
        int score1 = solve(stones, dp, 0, 0); 
        
        // Calculate Bob's score
        int total = accumulate(stones.begin(), stones.end(), 0);
        int score2 = total - score1;

        if (score1 > score2) return "Alice";
        if (score2 > score1) return "Bob";
        return "Tie";
    }
};