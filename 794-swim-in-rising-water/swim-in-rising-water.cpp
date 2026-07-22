class Solution {
public:
    vector<int> parent, size;
    void dsu(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }

    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB) return;

        if(size[rootA] > size[rootB]){
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
        else{
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
    }

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0, finalCell = m*n - 1;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int dir[] = {-1, 0, 1, 0, -1};
        vector<tuple<int, int, int>> cells;

        dsu(m*n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cells.push_back({grid[i][j], i, j});
            }
        }

        sort(cells.begin(), cells.end());

        for(int i = 0; i < cells.size(); i++){
            auto [lvl, r, c] = cells[i];
            vis[r][c] = 1;

            for(int k = 0; k < 4; k++){
                int nr = r + dir[k], nc = c + dir[k+1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    if(vis[nr][nc]) unite(nr * n + nc, r * n + c);
                }
            }
            if(find(0) == find(finalCell)) return lvl;
        }

        return -1;
    }
};