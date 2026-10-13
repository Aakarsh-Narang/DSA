class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int dir[5] = {-1, 0, 1, 0, -1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    q.push({i, j});
                }
                else{
                    grid[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [r, c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nr = r + dir[i], nc = c + dir[i+1];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == -1){
                        grid[nr][nc] = grid[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return grid;
    }
};