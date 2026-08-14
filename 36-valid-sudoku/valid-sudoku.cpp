class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9, 0)),col(9,vector<bool>(9, 0)),box(9,vector<bool>(9, 0));
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                char val=board[r][c];
                if(val=='.') 
                    continue;
                int boxno=3*(r/3)+c/3;
                if(!row[r][val-'1'] && !col[c][val-'1'] && !box[boxno][val-'1'])
                    row[r][val-'1']=col[c][val-'1']=box[boxno][val-'1']=1;                
                else
                    return false;
            }
        }
        return true;
    }
};