class Solution {
public:
    // Kruskals's Algorithm (DSU)

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
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(size[a] < size[b]){
            parent[a] = b;
            size[b] += size[a];
        }
        else{
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int totalCost = 0, n = points.size();
        vector<tuple<int, int, int>> edges;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i==j) continue;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dx = abs(x2 - x1), dy = abs(y2 - y1);
                edges.push_back({dx + dy, i, j});
            }
        }
        
        dsu(n);
        sort(edges.begin(), edges.end());

        for(auto& [wt, a, b] : edges){
            if(find(a) == find(b)) continue;

            totalCost += wt;

            unite(a, b);
        }
        
        return totalCost;
    }
};