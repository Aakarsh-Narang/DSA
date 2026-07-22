class Solution {
public:
    vector<int> parent, size;
    void dsu(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }

    // Union by size
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

    int find(int a){
        if(parent[a] == a) return a;

        return parent[a] = find(parent[a]);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dsu(m * n);

        vector<int> dir = {-1, 0, 1, 0, -1};

        // Build the DSU
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0)
                    continue;

                int node = i * n + j;

                // Up
                if(i > 0 && grid[i-1][j] == 1)
                    unite(node, (i-1) * n + j);

                // Left
                if(j > 0 && grid[i][j-1] == 1)
                    unite(node, node - 1);
            }
        }

        int ans = 0;

        // Existing largest island (handles all-1s case)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    ans = max(ans, size[find(i * n + j)]);
                }
            }
        }

        // Try flipping every 0
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    continue;

                unordered_set<int> roots;

                for(int k = 0; k < 4; k++) {
                    int nr = i + dir[k];
                    int nc = j + dir[k + 1];

                    if(nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1)
                    {
                        roots.insert(find(nr * n + nc));
                    }
                }

                int cur = 1;

                for(int root : roots)
                    cur += size[root];

                ans = max(ans, cur);
            }
        }

        return ans;
    }
};