class Solution {
public:
    int expand(vector<vector<int>>& grid, int row, int col){
        int area = 0, m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int dir[5] = {-1, 0, 1, 0, -1};

        q.push({row, col});
        grid[row][col] = 0;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            area++;

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, expand(grid, i, j));
                }
            }
        }

        return ans;
    }
};