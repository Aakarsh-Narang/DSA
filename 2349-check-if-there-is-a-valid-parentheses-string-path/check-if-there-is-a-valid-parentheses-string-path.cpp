class Solution {
public:
    bool solve(vector<vector<char>>& grid, vector<vector<vector<int>>>& dp, int r, int c, int bal){
        int m = grid.size(), n = grid[0].size();
        if(r >= m || c >= n) return false;

        if(grid[r][c] == '(') bal++;
        else bal--;

        if(bal < 0) return false;
        
        if(dp[r][c][bal] != -1) return dp[r][c][bal];
        if(r == m-1 && c == n-1) return dp[r][c][bal] = (bal == 0);

        int right = solve(grid, dp, r, c+1, bal);
        int down = solve(grid, dp, r+1, c, bal);

        return dp[r][c][bal] = right || down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m+n, -1)));

        return solve(grid, dp, 0, 0, 0);
    }
};