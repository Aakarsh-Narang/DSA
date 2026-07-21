class Solution {
public:
    int bfs(int r, int c, int label, vector<vector<int>>& grid){
        int size = 0, m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<int> dir = {-1, 0, 1, 0, -1};

        q.push({r, c});
        grid[r][c] = label;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            size++;

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    grid[nr][nc] = label;
                }
            }
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0, label = 2, m = grid.size(), n = grid[0].size();
        unordered_map<int, int> mp;  // label -> size
        vector<int> dir = {-1, 0, 1, 0, -1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    mp[label] = bfs(i, j, label, grid);
                    ans = max(ans, mp[label]);
                    label++;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    int newSize = 1;  // Current cell
                    for(int k = 0; k < 4; k++){
                        int nr = i + dir[k], nc = j + dir[k+1];
                        if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != 0){
                            st.insert(grid[nr][nc]);
                        }
                    }   

                    for(auto& island : st){
                        newSize += mp[island];
                    }
                    ans = max(ans, newSize);
                }
            }
        }
        return ans;
    }
};