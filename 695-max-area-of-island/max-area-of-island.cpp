class Solution {
public:
    int expand(vector<vector<int>>& grid, int r, int c){
        int cnt = 0, m = grid.size(), n = grid[0].size();
        int dir[5] = {-1, 0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            cnt++;

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc]){
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }

        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    ans = max(ans, expand(grid, i, j));
                }
            }
        }

        return ans;
    }
};