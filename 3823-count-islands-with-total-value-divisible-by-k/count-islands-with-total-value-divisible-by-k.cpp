class Solution {
public:
    long long expand(vector<vector<int>>& grid, int row, int col){
        int dir[5] = {-1, 0, 1, 0, -1}, m = grid.size(), n = grid[0].size();
        long long sum = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        sum += grid[row][col];
        grid[row][col] = 0;

        while(!q.empty()){
            auto[r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != 0){
                    q.push({nr, nc});
                    sum += grid[nr][nc];
                    grid[nr][nc] = 0;
                }
            }
        }

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt = 0, m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    long long sum = expand(grid, i, j);
                    cnt += (sum % k == 0);
                }
            }
        }

        return cnt;
    }
};