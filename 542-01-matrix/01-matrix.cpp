class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        int dir[5] = {-1, 0, 1, 0, -1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
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

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == INT_MAX){
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return dist;
    }
};