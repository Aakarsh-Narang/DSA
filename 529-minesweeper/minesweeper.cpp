class Solution {
public:
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    int countAdj(vector<vector<char>>& board, int r, int c){
        int cnt = 0;
        for(int i = 0; i<8; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size()) 
                continue;
            
            if(board[nr][nc] == 'M') cnt++;
        }
        return cnt;
    }
    void explore(vector<vector<char>>& board, int r, int c){
        queue<pair<int, int>> q;
        q.push({r,c});
        board[r][c] = 'B';
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            int adjMines = countAdj(board, x, y);
            if(adjMines != 0){
                board[x][y] = adjMines + '0';
            }
            else{
                for(int i = 0; i<8; i++){
                    int nr = x + dx[i];
                    int nc = y + dy[i];

                    if(nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size()) 
                        continue;
                    
                    if(board[nr][nc] == 'E'){
                        q.push({nr,nc});
                        board[nr][nc] = 'B';
                    }
                }
            } 
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0], c = click[1];
        if(board[r][c] == 'M'){
            board[r][c] = 'X';
            return board;
        }
        if(board[r][c] == 'E'){
            int adjMines = countAdj(board, r, c);
            if(adjMines == 0) explore(board, r, c);
            else board[r][c] = adjMines + '0';
        }
        return board;
    }
};