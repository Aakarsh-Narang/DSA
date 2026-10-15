class Solution {
public:
    bool canReach(vector<vector<int>>& grid, vector<vector<int>>& minTime, int startTime){
        if(minTime[0][0] <= startTime)
            return false;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        queue<tuple<int, int, int>> q;  // {row, col, time}
        q.push({0, 0, startTime});
        vis[0][0] = 1;

        int dir[5] = {-1, 0, 1, 0, -1};

        while(!q.empty()){
            auto [r, c, time] = q.front();
            q.pop();

            if(r == m-1 && c == n-1) return true;

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]  && grid[nr][nc] != 2){
                    int nt = time + 1;
                    if (nr == m-1 && nc == n-1) {
                        if (nt <= minTime[nr][nc]) {
                            q.push({nr, nc, nt});
                            vis[nr][nc] = 1;
                        }
                    }
                    else if (nt < minTime[nr][nc]) {
                        q.push({nr, nc, nt});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }

        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int INF = INT_MAX;
        vector<vector<int>> minTime(m, vector<int>(n, INF));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    minTime[i][j] = 0;
                }
            }
        }

        int dir[5] = {-1, 0, 1, 0, -1}, maxTime = 0;

        while(!q.empty()){
            auto[r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && minTime[nr][nc] == INF){
                    q.push({nr, nc});
                    minTime[nr][nc] = minTime[r][c] + 1;
                    maxTime = max(maxTime, minTime[nr][nc]);
                }
            }
        }

        int lo = 0, hi = 1e9, ans = -1;

        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;

            if(canReach(grid, minTime, mid)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }
};