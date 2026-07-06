class Solution {
public:
    bool expand(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col){
        bool isSub = grid1[row][col] == grid2[row][col];
        int m = grid1.size(), n = grid1[0].size();
        int dir[] = {-1,0,1,0,-1};
        queue<pair<int, int>> q;
        q.push({row, col});
        grid2[row][col] = 0;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i){
                int nr = r + dir[i], nc = c + dir[i+1];

                if(nr >= 0 && nr < m && nc >=0 && nc < n && grid2[nr][nc] == 1){
                    if(grid1[nr][nc] != grid2[nr][nc]) 
                        isSub = false;
                    grid2[nr][nc] = 0;  // Change after comparing
                    q.push({nr, nc});
                }
            }
        }
        return isSub;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size(), ans = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid2[i][j] == 1){
                    if(expand(grid1, grid2, i, j)) ans++;
                }
            }
        }

        return ans;
    }
};