class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), time = 0, fc = 0;
        int dir[5] = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    fc++;
                }
            }
        }
        q.push({-1, -1});

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            if(r == -1 && c == -1){
                time++;
                if(q.size()){
                    q.push({-1, -1});
                }
                continue;
            }

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fc--;
                }
            }
        }

        return fc == 0 ? time-1 : -1;
    }
};