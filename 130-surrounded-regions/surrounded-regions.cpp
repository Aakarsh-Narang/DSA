class Solution {
public:
    int dir[5] = {-1, 0, 1, 0 , -1};
    
    void bfs(vector<vector<char>>& board, int row, int col) {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;  //{row, col}
        q.push({row,col});
        board[row][col] = '#'; 

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
        
            for(int i = 0; i < 4; i++){
                int nextr = r + dir[i], nextc = c + dir[i+1];

                if(nextr >= 0 && nextr < m && nextc >= 0 && nextc < n && board[nextr][nextc] == 'O'){
                    q.push({nextr, nextc});
                    board[nextr][nextc] = '#';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O') bfs(board, 0, i);
            if(board[m-1][i] == 'O') bfs(board, m-1, i);
        }
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') bfs(board, i, 0);
            if(board[i][n-1] == 'O') bfs(board, i, n-1);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};