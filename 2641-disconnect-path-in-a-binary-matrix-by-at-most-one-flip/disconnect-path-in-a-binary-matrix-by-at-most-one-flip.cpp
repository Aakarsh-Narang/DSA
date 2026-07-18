class Solution {
public:
    int dir[3] = {1,0,1};
    
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c){
        int m = grid.size(), n = grid[0].size();
        if(r == m-1 && c == n-1) return true;
        vis[r][c] = 1;
        for(int i = 0; i < 2; i++){
            int nr = r + dir[i], nc = c + dir[i+1];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1){
                if(dfs(grid, vis, nr, nc)){
                    grid[r][c] = 0;
                    return true;
                }
            }
        }
        return false;
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));

        bool firstVis = dfs(grid, vis, 0, 0);
        
        if(!firstVis) return true;
        grid[m-1][n-1] = 1;
        grid[0][0] = 1;
        vis.assign(m, vector<bool>(n, 0));

        bool secondVis = dfs(grid, vis, 0, 0);

        return !secondVis;
    }
};