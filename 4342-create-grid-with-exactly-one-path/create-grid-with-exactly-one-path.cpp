class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string temp(n, '#'), firstrow(n, '.');
        vector<string> grid(m, temp);
        grid[0] = firstrow;
        for(int i = 1; i < m; i++){
            grid[i][n-1] = '.';
        }

        return grid;
    }
};