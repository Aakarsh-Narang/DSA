class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    void Backtrack(vector<vector<int>>& grid, int r, int c, int cv, int zc, int& m, int& n, int& ans){
        if(grid[r][c] == 2){
            if(cv == zc+1)
                ans++;
            return;
        }
        
        // Mark visited
        grid[r][c] = -1;
        for(int i = 0; i < 4; i++){
            int nr = r + dir[i], nc = c + dir[i+1];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] == -1) continue;

            Backtrack(grid, nr, nc, cv+1, zc, m, n, ans); 
        }
        // Backtrack and undo
        grid[r][c] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr, sc, zc = 0, ans = 0, m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    sr = i, sc = j;
                }
                if(grid[i][j] == 0) zc++;
            }
        }
        grid[sr][sc] = -1;
        Backtrack(grid, sr, sc, 0, zc, m, n, ans);

        return ans;
    }
};