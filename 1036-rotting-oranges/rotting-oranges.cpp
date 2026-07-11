class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, minutes = 0, m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<int> dir = {-1, 0 , 1, 0, -1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        q.push({-1, -1});

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            if(r == -1 && c == -1){
                if(!q.empty()) q.push({-1, -1});
                minutes++;
                continue;
            }
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    grid[nr][nc] = 2;
                    fresh--;
                }
            }
        }
        if(fresh == 0) return minutes-1;
        return -1;
    }
};