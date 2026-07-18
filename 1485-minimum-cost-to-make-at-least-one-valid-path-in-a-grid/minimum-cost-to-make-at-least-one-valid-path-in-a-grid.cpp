class Solution {
public:
    void print(vector<vector<int>>& mat){
        for(auto& r : mat){
            for(auto& ele : r){
                cout << ele <<" ";
            }
            cout<<endl;
        }
    }
    int minCost(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // Right, Left, Lower, Upper
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;  // {row, col}

        dq.push_front({0,0});
        dist[0][0] = 0;

        while(!dq.empty()){
            auto [r, c] = dq.front();
            dq.pop_front();

            // cout << r<< " "<<c<<endl;
            if(r == m-1 && c == n-1){
                return dist[r][c];
            }

            for(int i = 0; i < 4; i++){
                auto [dr, dc] = dir[i];
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int newCost = dist[r][c] + (grid[r][c] != i + 1);

                    if(newCost < dist[nr][nc]){
                        dist[nr][nc] = newCost;
                        if(grid[r][c] == i + 1)
                            dq.push_front({nr,nc});
                        else
                            dq.push_back({nr,nc});
                    }
                }
            }
        }
        return 0;
    }
};