class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<pair<int, int>> rows(m), cols(n);
        vector<vector<int>> diff(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            int zc = 0, oc = 0;
            for(int j = 0; j < n; j++){
                zc += (grid[i][j] == 0);
                oc += (grid[i][j] == 1);
            }
            rows[i] = {zc, oc};
        }
        for(int i = 0; i < n; i++){
            int zc = 0, oc = 0;
            for(int j = 0; j < m; j++){
                zc += (grid[j][i] == 0);
                oc += (grid[j][i] == 1);
            }
            cols[i] = {zc, oc};
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                diff[i][j] = rows[i].second + cols[j].second - rows[i].first - cols[j].first;
            }
        }
        
        return diff;
    }
};