class Solution {
public:
    vector<int> parent, size;

    void dsu(int n){
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n+1, 1);
    }

    int find(int a){
        if(parent[a] == a) return a;

        return parent[a] =  find(parent[a]);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(size[a] > size[b]){
            parent[b] = a;
            size[a] += size[b];
        }
        else{
            parent[a] = b;
            size[b] += size[a];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(), idx;
        dsu(n);

        for(int i = 0; i < n; i++){
            int a = edges[i][0], b = edges[i][1];

            if(find(a) == find(b)) idx = i;
            else unite(a, b);
        }

        return edges[idx];
    }
};