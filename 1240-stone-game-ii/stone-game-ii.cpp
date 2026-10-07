class Solution {
public:
    int solve(int i, int M, vector<int>& piles, vector<int>& suffixSum, vector<vector<int>>& dp) {
        int n = piles.size();
        if (i >= n) return 0;
        
        // If you can take all remaining piles, just take them all!
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }
        
        if (dp[i][M] != -1) return dp[i][M];
        
        int maxStones = 0;
        
        // Try taking X piles (from 1 up to 2*M)
        for (int X = 1; X <= 2 * M; X++) {
            // Opponent's best score from the resulting state
            int opponentsBest = solve(i + X, max(M, X), piles, suffixSum, dp);
            
            // My score is whatever is left over from the total available
            int myStones = suffixSum[i] - opponentsBest;
            
            maxStones = max(maxStones, myStones);
        }
        
        return dp[i][M] = maxStones;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // suffixSum[i] stores the sum of all piles from index i to the end
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        // dp[i][M]
        // M can grow up to n (if someone takes all remaining piles)
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        // Alice starts at index 0 with M = 1
        return solve(0, 1, piles, suffixSum, dp);
    }
};