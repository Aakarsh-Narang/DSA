class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = grid[0][0];
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int dir[] = {-1, 0, 1, 0, -1};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        pq.push({grid[0][0],0,0});
        vis[0][0] = 1;

        while(!pq.empty()){
            auto [lvl, r, c] = pq.top();
            ans = max(ans, grid[r][c]);
            pq.pop();

            if(r == m-1 && c == n-1) return ans;

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]){
                    pq.push({grid[nr][nc], nr, nc});
                    vis[nr][nc] = 1;
                }
            }  
        }

        return -1;
    }
};