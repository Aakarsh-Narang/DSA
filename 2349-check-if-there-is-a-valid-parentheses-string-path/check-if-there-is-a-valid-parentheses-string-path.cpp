class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));

        if(grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;

        dp[0][0].insert(1);

        for(int r = 0; r < m; r++){
           for(int c = 0; c < n; c++){
                if(r == 0 && c== 0) continue;

                int delta = (grid[r][c] == '(') ? 1 : -1;

                if(r > 0){
                    for(auto& s : dp[r-1][c]){
                        if(s + delta < 0) continue;
                        dp[r][c].insert(s + delta);
                    }
                }
                if(c > 0){
                    for(auto& s : dp[r][c-1]){
                        if(s + delta < 0) continue;
                        dp[r][c].insert(s + delta);
                    }
                }
           }
        }

        return dp[m-1][n-1].count(0);
    }
};