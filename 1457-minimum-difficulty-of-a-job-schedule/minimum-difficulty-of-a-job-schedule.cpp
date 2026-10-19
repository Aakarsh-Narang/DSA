class Solution {
public:
    int solve(vector<int>& jobDifficulty, vector<vector<int>>& dp, int start, int d){
        if(d == 0 && start < jobDifficulty.size()) return 1e9;
        if(start == jobDifficulty.size() && d > 0) return 1e9;
        if(start == jobDifficulty.size()) return 0;

        if(dp[start][d] != -1) return dp[start][d];

        int currMax = jobDifficulty[start], ans = 1e9;

        for(int i = start; i < jobDifficulty.size(); i++){
            int next = solve(jobDifficulty, dp, i+1, d-1);
            currMax = max(currMax, jobDifficulty[i]);

            ans = min(ans, currMax + next);
        }

        return dp[start][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int>(d+1, -1));

        int ans = solve(jobDifficulty, dp, 0, d);

        if(ans == 1e9) return -1;
        return ans;
    }
};