class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = -1;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dir[5] = {-1, 0, 1, 0, -1};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            if(dist[r][c] != 0)
                ans = max(ans, dist[r][c]);

            for(int i = 0; i < 4; i++){
                int nr= r + dir[i], nc = c + dir[i+1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == INT_MAX){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};