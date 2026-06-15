class Solution {
public:
    void expand(vector<vector<char>>& grid, int row, int col){
        vector<int> dir = {-1, 0, 1, 0 , -1};
        queue<pair<int, int>> q;
        q.push({row,col});
        grid[row][col] = '0';

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];

                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1'){
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    expand(grid, i, j);
                }
            }
        }   

        return cnt;
    }
};