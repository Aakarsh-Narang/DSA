class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // We do reverse engineering here
        // Instead of taking water from each cell to the boundaries, 
        // We bring water from boudnaries back into the grid with reversed logic
        // At end we check at what cells have received watere from both oceans

        int m = heights.size(), n = heights[0].size();
        int dir[5] = {-1, 0, 1, 0, -1};
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<int>> ans;

        queue<pair<int, int>> q;

        // Pacific
        for(int i = 0; i < m; i++){
            pacific[i][0] = 1;
            q.push({i, 0});
        }
        for(int j = 0; j < n; j++){
            pacific[0][j] = 1;
            q.push({0, j});
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && heights[r][c] <= heights[nr][nc] && !pacific[nr][nc]){
                    q.push({nr, nc});
                    pacific[nr][nc] = 1;
                }
            }
        }


        // Atlantic
        for(int i = 0; i < m; i++){
            atlantic[i][n-1] = 1;
            q.push({i, n-1});
        }
        for(int j = 0; j < n; j++){
            atlantic[m-1][j] = 1;
            q.push({m-1, j});
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && heights[r][c] <= heights[nr][nc] && !atlantic[nr][nc]){
                    q.push({nr, nc});
                    atlantic[nr][nc] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};