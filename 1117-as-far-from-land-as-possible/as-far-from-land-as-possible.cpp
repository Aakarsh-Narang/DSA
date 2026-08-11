class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = -1;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        int dir[] = {-1, 0, 1, 0, -1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i, j});   
                }
            }
        }

        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                auto [r, c] = q.front();
                q.pop();
                
                for(int k = 0; k < 4; k++){
                    int nr = r + dir[k], nc = c + dir[k+1];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == -1){
                        dist[nr][nc] = dist[r][c] + 1;
                        ans = max(ans, dist[nr][nc]);
                        q.push({nr, nc});
                    }
                }
            }
        }

        return ans;
    }
};