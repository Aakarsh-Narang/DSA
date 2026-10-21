class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, 0)), col(9, vector<bool>(9, 0)), block(9, vector<bool>(9, 0));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '1';
                int blockNo = 3*(i/3) + (j/3);
                if(!row[i][num] && !col[j][num] && !block[blockNo][num]){
                    row[i][num] = 1;
                    col[j][num] = 1;
                    block[blockNo][num] = 1;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};