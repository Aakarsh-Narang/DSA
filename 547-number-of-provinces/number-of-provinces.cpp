class Solution {
public:
    int n;
    vector<int> parent, size;

    void dsu(int sz){
        n = sz;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return;   // Already Connected

        if(size[pa] < size[pb]){
            unite(b, a);
            return;
        }

        parent[pb] = pa;
        size[pa] += size[pb];
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz = isConnected.size();
        dsu(sz);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    unite(i, j);
                }
            }
        }

        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(find(i));
        }

        return st.size();
    }
};