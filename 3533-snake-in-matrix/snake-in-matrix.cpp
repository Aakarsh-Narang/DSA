class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0, col = 0;

        for(auto& c : commands){
            if(c == "UP") row--;
            else if(c == "DOWN") row++;
            else if(c == "LEFT") col--;
            else col++;
        }

        return row * n + col;
    }
};