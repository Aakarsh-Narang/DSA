class Solution {
public:
    bool expand(vector<vector<int>>& grid, int row, int col){
        int m = grid.size(), n = grid[0].size();
        bool isClosed = true;
        if(row == m-1 || col == n-1 || row == 0 || col == 0) isClosed = false;

        int dir[] = {-1, 0 , 1, 0, -1};
        queue<pair<int, int>> q;
        
        q.push({row, col});
        grid[row][col] = 1;
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >=0 && nc < n && grid[nr][nc] == 0){
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                    if(nr == m-1 || nc == n-1 || nr == 0 || nc == 0) isClosed = false;
                }
            }
        }
        // cout <<"Returning "<< isClosed <<" for "<<row<<","<<col<<endl;
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0, m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    if(expand(grid, i, j)) 
                        cnt++;
                }
            }
        }

        return cnt;
    }
};