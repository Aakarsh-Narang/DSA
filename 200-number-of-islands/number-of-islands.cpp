class Solution {
public:
    void expand(vector<vector<char>>& grid, int row, int col){
        int m = grid.size(), n = grid[0].size();
        int dir[] = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;

        q.push({row, col});
        grid[row][col] = '0';

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];

                if(nr >= 0 && nr < m && nc >=0 && nc < n && grid[nr][nc] == '1'){
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    expand(grid, i, j);
                }
            }
        }

        return ans;
    }
};