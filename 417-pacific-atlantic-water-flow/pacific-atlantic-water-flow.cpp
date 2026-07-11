class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n,0));
        vector<vector<bool>> atlantic(m, vector<bool>(n,0));
        queue<pair<int,int>> q;
        vector<int> dir={-1,0,1,0,-1};
        vector<vector<int>> ans;

        // BFS for pacific ocean

        for(int i = 0; i < m; i++){
            q.push({i, 0});
            pacific[i][0] = true;
        }
        for(int i = 0; i < n; i++){
            q.push({0, i});
            pacific[0][i] = true;
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && !pacific[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    q.push({nr, nc});
                    pacific[nr][nc] = true;
                }
            }
        }

        // BFS for atlantic ocean

        for(int i = 0; i < m; i++){
            q.push({i, n-1});
            atlantic[i][n-1] = true;
        }
        for(int i = 0; i < n; i++){
            q.push({m-1, i});
            atlantic[m-1][i] = true;
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && !atlantic[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    q.push({nr, nc});
                    atlantic[nr][nc] = true;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};